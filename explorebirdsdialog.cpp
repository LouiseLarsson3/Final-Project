#include "explorebirdsdialog.h"
#include "ui_explorebirdsdialog.h"
#include "araripedialog.h"

exploreBirdsDialog::exploreBirdsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exploreBirdsDialog)
{
    ui->setupUi(this);
    QListWidgetItem *bird1 = new QListWidgetItem(QIcon(":/rec/img/Ararpie manakin.jpg"), "Araripe Manakin");
    ui->listWidget->addItem(bird1);
    QListWidgetItem *bird2 = new QListWidgetItem(QIcon(":/rec/img/Eastern bristlebird.jpg"), "Eastern bristlebird");
    ui->listWidget->addItem(bird2);
    QListWidgetItem *bird3 = new QListWidgetItem(QIcon(":/rec/img/Pale-headed brushfinsh.jpg"), "Pale-headed brushfish");
    ui->listWidget->addItem(bird3);
    QListWidgetItem *bird4 = new QListWidgetItem(QIcon(":/rec/img/Thick-billed parrot.jpg"), "Thick-billed parrot");
    ui->listWidget->addItem(bird4);

    // connect the itemClicked() signal of the listWidget to the onListWidgetItemClicked() slot
    connect(ui->listWidget, &QListWidget::itemClicked, this, &exploreBirdsDialog::onListWidgetItemClicked);
}

/*Open new dialog window when Araripe Manakin is clicked from list*/
void exploreBirdsDialog::onListWidgetItemClicked(QListWidgetItem *item)
{
    if (item->text() == "Araripe Manakin") {
        AraripeDialog araripeDialog(this); // create a new instance of AraripeDialog with the parent exploreBirdsDialog
        araripeDialog.setModal(true);
        araripeDialog.exec();
    }
}

exploreBirdsDialog::~exploreBirdsDialog()
{
    delete ui;
}
