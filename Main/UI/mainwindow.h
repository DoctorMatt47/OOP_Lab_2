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

    void on_buttonChangeTimer_clicked();

    void on_buttonChangeAlarm_clicked();

    void on_listTimers_itemClicked(QListWidgetItem *item);

    void on_buttonStop_clicked();

    void on_buttonStart_clicked();

    void on_buttonContinue_clicked();

    void on_buttonPause_clicked();

    void on_listAlarms_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    int _index;
    bool _isTimer;
    QVector<Timer*> _timers;
    QVector<Alarm*> _alarms;
};
#endif // MAINWINDOW_H
