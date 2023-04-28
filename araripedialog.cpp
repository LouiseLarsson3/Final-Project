#include "araripedialog.h"
#include "ui_araripedialog.h"
#include "araripesounddialog.h"

AraripeDialog::AraripeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AraripeDialog)
{
    ui->setupUi(this);
}

AraripeDialog::~AraripeDialog()
{
    delete ui;
}



void AraripeDialog::on_listenPushButton_clicked()
{
    araripeSoundDialog araripeSoundDialog;
    araripeSoundDialog.setModal(true);
    araripeSoundDialog.exec();

}

