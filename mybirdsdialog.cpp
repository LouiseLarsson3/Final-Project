#include "mybirdsdialog.h"
#include "ui_mybirdsdialog.h"

myBirdsDialog::myBirdsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myBirdsDialog)
{
    ui->setupUi(this);
}

myBirdsDialog::~myBirdsDialog()
{
    delete ui;
}
