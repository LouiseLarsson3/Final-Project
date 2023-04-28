#include "araripesounddialog.h"
#include "ui_araripesounddialog.h"

araripeSoundDialog::araripeSoundDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::araripeSoundDialog)
{
    ui->setupUi(this);
}

araripeSoundDialog::~araripeSoundDialog()
{
    delete ui;
}

void araripeSoundDialog::on_ProgressSlider_sliderMoved(int position)
{

}


void araripeSoundDialog::on_VolumeSlider_sliderMoved(int position)
{

}


void araripeSoundDialog::on_StopPushButton_clicked()
{

}


void araripeSoundDialog::on_StartPushButton_clicked()
{

}

