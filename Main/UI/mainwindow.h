#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include <Timer/Logic/timer.h>
#include <Alarm/Logic/alarm.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void OnTimeDecrease();

    void on_buttonAddTimer_clicked();

    void on_buttonAddAlarm_clicked();

    void on_listTimers_itemClicked();

    void on_listAlarms_itemClicked();

    void on_buttonStop_clicked();

    void on_buttonStart_clicked();

    void on_buttonContinue_clicked();

    void on_buttonPause_clicked();

    void on_checkBox_toggled(bool checked);

    void on_timeDndFrom_userTimeChanged(const QTime &time);

    void on_timeDndTo_userTimeChanged(const QTime &time);

private:
    Ui::MainWindow *ui;
    int _amountOfActiveTimers;
    int _amountOfActiveAlarms;
    int _index;
    bool _isTimer;
    QTime _timeDndFrom;
    QTime _timeDndTo;
    QVector<Timer*> _timers;
    QVector<Alarm*> _alarms;

    QString FindNameOfFirstTimer();
};
#endif // MAINWINDOW_H
