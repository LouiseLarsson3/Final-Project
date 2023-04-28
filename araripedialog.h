#ifndef ARARIPEDIALOG_H
#define ARARIPEDIALOG_H

#include <QDialog>

namespace Ui {
class AraripeDialog;
}

class AraripeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AraripeDialog(QWidget *parent = nullptr);
    ~AraripeDialog();

private slots:

    void on_listenPushButton_clicked();

private:
    Ui::AraripeDialog *ui;
};

#endif // ARARIPEDIALOG_H
