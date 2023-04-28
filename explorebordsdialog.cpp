#include "explorebordsdialog.h"
#include "ui_explorebordsdialog.h"

ExploreBordsDialog::ExploreBordsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExploreBordsDialog)
{
    ui->setupUi(this);
}

ExploreBordsDialog::~ExploreBordsDialog()
{
    delete ui;
}
