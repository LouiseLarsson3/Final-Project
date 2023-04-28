#ifndef EXPLOREBIRDSDIALOG_H
#define EXPLOREBIRDSDIALOG_H

#include "qlistwidget.h"
#include <QDialog>

namespace Ui {
class exploreBirdsDialog;
}

class exploreBirdsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit exploreBirdsDialog(QWidget *parent = nullptr);
    ~exploreBirdsDialog();

private slots:
    void onListWidgetItemClicked(QListWidgetItem *item);

private:
    Ui::exploreBirdsDialog *ui;
};

#endif // EXPLOREBIRDSDIALOG_H
