#ifndef ADDTIMERDIALOG_H
#define ADDTIMERDIALOG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class AddTimerDialog;
}

class AddTimerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTimerDialog(QWidget *parent = nullptr);

    ~AddTimerDialog();

    QTime GetTime();

    QString GetName();

    QString GetInfo();

    QString GetPath();

private slots:
    void on_increaseSecondsButton_clicked();

    void on_decreaseSecondsButton_clicked();

    void on_increaseMinutesButton_clicked();

    void on_decreaseMinutesButton_clicked();

    void on_increaseHoursButton_clicked();

    void on_decreaseHoursButton_clicked();

    void on_cancelButton_clicked();

    void on_applyButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::AddTimerDialog *ui;
    QTime _time;

    void TimeRefresh();
};

#endif // ADDTIMERDIALOG_H
