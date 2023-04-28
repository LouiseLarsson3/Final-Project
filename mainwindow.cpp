
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydatadialog.h"
#include "mybirdsdialog.h"
#include "explorebirdsdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_myDataPushButton_clicked()
{
    // open a new window when button is clicked
    myDataDialog myDataDialog; // create object of myDataDialog class
    myDataDialog.setModal(true); // set the modal to true
    myDataDialog.exec(); // execute the myDataDialog


}


void MainWindow::on_myBirdsPushButton_clicked()
{
    myBirdsDialog myBirdsDialog;
    myBirdsDialog.setModal(true);
    myBirdsDialog.exec();
}


void MainWindow::on_explorePushButton_clicked()
{
    exploreBirdsDialog exploreBirdsDialog;
    exploreBirdsDialog.setModal(true);
    exploreBirdsDialog.exec();
}

