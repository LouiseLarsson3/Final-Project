#ifndef EXPLOREBORDSDIALOG_H
#define EXPLOREBORDSDIALOG_H

#include <QDialog>

namespace Ui {
class ExploreBordsDialog;
}

class ExploreBordsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExploreBordsDialog(QWidget *parent = nullptr);
    ~ExploreBordsDialog();

private:
    Ui::ExploreBordsDialog *ui;
};

#endif // EXPLOREBORDSDIALOG_H
