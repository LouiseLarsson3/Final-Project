#ifndef MYBIRDSDIALOG_H
#define MYBIRDSDIALOG_H

#include <QDialog>

namespace Ui {
class myBirdsDialog;
}

class myBirdsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myBirdsDialog(QWidget *parent = nullptr);
    ~myBirdsDialog();

private:
    Ui::myBirdsDialog *ui;
};

#endif // MYBIRDSDIALOG_H
