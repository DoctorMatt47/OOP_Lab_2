#ifndef ADDALARMDIALOG_H
#define ADDALARMDIALOG_H

#include <QDialog>
#include <QTime>
#include <QVector>

namespace Ui {
class AddAlarmDialog;
}

class AddAlarmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAlarmDialog(QWidget *parent = nullptr);

    ~AddAlarmDialog();

    QTime GetTime();

    QString GetName();

    QString GetInfo();

    QString GetPath();

    QVector<bool> GetDaysOfWeek();

private slots:
    void on_increaseSecondsButton_clicked();

    void on_decreaseSecondsButton_clicked();

    void on_increaseMinutesButton_clicked();

    void on_decreaseMinutesButton_clicked();

    void on_increaseHoursButton_clicked();

    void on_decreaseHoursButton_clicked();

    void on_applyButton_clicked();

    void on_cancelButton_clicked();

    void on_monButton_clicked();

    void on_tueButton_clicked();

    void on_wedButton_clicked();

    void on_thuButton_clicked();

    void on_friButton_clicked();

    void on_satButton_clicked();

    void on_sunButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::AddAlarmDialog *ui;
    QTime _time;
    QVector<bool> _daysOfWeek;

    void TimeRefresh();
};

#endif // ADDALARMDIALOG_H
