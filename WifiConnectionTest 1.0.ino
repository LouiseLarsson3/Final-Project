#include <SPI.h>
#include <WiFiNINA.h>
#include <PDM.h>
#include "mbed.h"

rtos::Thread t1;
rtos::Thread t2;

const char ssid[] = "BirdNetwork";        // your network SSID (name)
const char pass[] = "12344321";    // your network password (use for WPA, or use as key for WEP)

const uint16_t port = 8090;
const char host[] = "192.168.0.29";

//global strings to store location/device, bird
char birdID[] = "unidentified";
const char deviceID[] = "Area1";

// default number of output channels
static const char channels = 1;

// default PCM output frequency
static const int frequency = 16000;

// Buffer to read samples into, each sample is 16-bits
short sampleBuffer[512];

// Number of audio samples read
volatile int samplesRead;

bool detected = false;

//Task1 WifiConnection and datatransfer with global detected as trigger
void wifiConnection(){
while (true){
  WiFiClient client;   

if (!client.connect(host, port)){
  Serial.println("Connection to host failed");
  delay(1000);
  return;
}

Serial.println("Connected to server successful!");

//Test print
if (detected){
  //Led Test to detect trigger on arduino
digitalWrite(LEDB, HIGH);

// Get current time as seconds since January 1, 1970
time_t seconds = time(NULL);
// Convert to a struct tm with local time
struct tm *now = localtime(&seconds);
// Print the date of the set time
char buffer[50];
sprintf(buffer, "%s Time:%04d%02d%02d%02d%02d %s", deviceID, 
now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, birdID);

// Send the buffer to the server using write()
size_t len = strlen(buffer);
client.write(buffer, len);

detected = false;
}
 
// close the connection:
 client.stop();
 Serial.println("client disconnected");
 rtos::ThisThread::sleep_for(1000);
}
}

//Task2 micRec that triggers detected if soundsample is high
void micRecFunc(){
  while (true){
  delay(2000);
  // Wait for samples to be read
  if (samplesRead) {

   // Print samples to the serial monitor or plotter
    for (int i = 0; i < samplesRead; i++) {
      if (sampleBuffer[i] > 10000 || sampleBuffer[i] <= -10000) {
    
        //trigger wifiFunc to send data
        detected = true;

      }
    }

    // Clear the read count
    samplesRead = 0;
  }

  }
}


void setup() {
  Serial.begin(9600);      // initialize serial communication
  set_time(1683300000);  // Set RTC time to 5 May 2023 15:20

  pinMode(LEDB, OUTPUT);

 // Configure the data receive callback
  PDM.onReceive(onPDMdata);
  
  // Initialize PDM with:
  // - one channel (mono mode)
  // - a 16 kHz sample rate for the Arduino Nano 33 BLE Sense
  if (!PDM.begin(channels, frequency)) {
  Serial.println("Failed to start PDM!");
  while (1);
  }

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  WiFi.begin(ssid, pass);
  // attempt to connect to WiFi network:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // wait 5 seconds for connection:
    delay(500);
  }
  printWifiStatus();                    // you're connected now, so print out the status

  t1.start(mbed::callback(wifiConnection));
  t2.start(mbed::callback(micRecFunc));
}


//emtpy loop
void loop() {
}

//only for testpurpose
void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void onPDMdata() {
  // Query the number of available bytes
  int bytesAvailable = PDM.available();

  // Read into the sample buffer
  PDM.read(sampleBuffer, bytesAvailable);

  // 16-bit, 2 bytes per sample
  samplesRead = bytesAvailable / 2;
}