#ifndef ARARIPESOUNDDIALOG_H
#define ARARIPESOUNDDIALOG_H

#include <QDialog>


namespace Ui {
class araripeSoundDialog;
}

class araripeSoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit araripeSoundDialog(QWidget *parent = nullptr);
    ~araripeSoundDialog();

private slots:
    void on_ProgressSlider_sliderMoved(int position);

    void on_VolumeSlider_sliderMoved(int position);

    void on_StopPushButton_clicked();

    void on_StartPushButton_clicked();

private:
    Ui::araripeSoundDialog *ui;
};

#endif // ARARIPESOUNDDIALOG_H
