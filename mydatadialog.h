#ifndef MYDATADIALOG_H
#define MYDATADIALOG_H

#include <QDialog>

namespace Ui {
class myDataDialog;
}

class QTcpSocket;
class ServerThread;

class myDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDataDialog(QWidget *parent = nullptr);
    ~myDataDialog();

private slots:
    void updateData(QString deviceID, QString timestamp, QString birdName);

private:
    Ui::myDataDialog *ui;
    QTcpSocket *socket;
    ServerThread *serverThread;
};

#endif // MYDATADIALOG_H
