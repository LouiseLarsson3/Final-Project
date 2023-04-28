#include "mydatadialog.h"
#include "ui_mydatadialog.h"
#include <QtNetwork/QTcpSocket>

myDataDialog::myDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDataDialog),
    socket(nullptr),
    serverThread(nullptr)
{
    ui->setupUi(this);
}

myDataDialog::~myDataDialog()
{
    delete ui;
}


void myDataDialog::updateData(QString deviceID, QString timestamp, QString birdName)
{
    // Update the GUI with the received data
    ui->deviceIDLabel->setText(deviceID);
    ui->timestampLabel->setText(timestamp);
    ui->birdNameLabel->setText(birdName);
}
