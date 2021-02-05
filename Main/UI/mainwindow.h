#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include <Timer/Logic/timer.h>
#include <Alarm/Logic/alarm.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 *
 * This class provides interface for conveniently
 * using timers and alarms. Using this interface
 * you can create and manage timers, as well as get
 * some information about the created timers.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    /*! Main window. */
    Ui::MainWindow *ui;

    /*! Amount of active timers at the moment. */
    int _amountOfActiveTimers;

    /*! Amount of active alarms at the moment. */
    int _amountOfActiveAlarms;

    /*! Index of selected timer or alarm. */
    int _index;

    /*! True, if timer is selected, else false. */
    bool _isTimer;

    /*! Time from which Do Not Disturb mode starts. */
    QTime _timeDndFrom;

    /*! Time, when Do Not Disturb mode ends. */
    QTime _timeDndTo;

    /*! Vector of timers. */
    QVector<Timer*> _timers;

    /*! Vector of alarms. */
    QVector<Alarm*> _alarms;

    /*!
     * \brief FindNameOfFirstTimer
     *
     * This slot finds the name of
     * the first timer to ring first.
     *
     * \return The name of the first
     * timer to ring first.
     */
    QString FindNameOfFirstTimer();

public:
    /*!
     * \brief MainWindow
     *
     * Default constructor.
     *
     * \param parent Parent object.
     */
    MainWindow(QWidget *parent = nullptr);

    /*!
     * \brief ~MainWindow
     *
     * Default destructor. Destruct the object.
     */
    ~MainWindow();

private slots:
    /*!
     * \brief OnTimeDecrease
     *
     * This slot is connected to the TimeDecrease()
     * signal from the Timer or Alarm class. Each call
     * to this method enters information about connected
     * timer on main window.
     */
    void OnTimeDecrease();

    /*!
     * \brief OnCall
     *
     * This slot decrease number of active timers by one.
     */
    void OnCall();

    /*!
     * \brief on_buttonAddTimer_clicked
     *
     * This slot calls window of creating a new timer.
     */
    void on_buttonAddTimer_clicked();

    /*!
     * \brief on_buttonAddAlarm_clicked
     *
     * This slot calls window of creating a new alarm.
     */
    void on_buttonAddAlarm_clicked();

    /*!
     * \brief on_listTimers_itemClicked
     *
     * This slot enters information about selected
     * timer on main window.
     */
    void on_listTimers_itemClicked();

    /*!
     * \brief on_listAlarms_itemClicked
     *
     * This slot enters information about selected
     * alarm on main window.
     */
    void on_listAlarms_itemClicked();

    /*!
     * \brief on_buttonStop_clicked
     *
     * This slot stops the selected timer,
     * returns it to its starting position.
     */
    void on_buttonStop_clicked();

    /*!
     * \brief on_buttonStart_clicked
     *
     * This slot starts the selected timer.
     */
    void on_buttonStart_clicked();

    /*!
     * \brief on_buttonContinue_clicked
     *
     * This slot continues selected timer or alarm,
     * if it was paused.
     */
    void on_buttonContinue_clicked();

    /*!
     * \brief on_buttonPause_clicked
     *
     * This slot pauses selected timer or alarm.
     * Time will be paused, but can be continued.
     */
    void on_buttonPause_clicked();

    /*!
     * \brief on_checkBox_toggled
     *
     * This slot enables or disables Do Not Disturb.
     *
     * \param checked If checked true, else false.
     */
    void on_checkBox_toggled(bool checked);

    /*!
     * \brief on_timeDndFrom_userTimeChanged
     *
     * This slot sets time, from which
     * Do Not Disturb mode starts.
     *
     * \param time Time from which
     * Do Not Disturb mode starts.
     */
    void on_timeDndFrom_userTimeChanged(const QTime &time);

    /*!
     * \brief on_timeDndTo_userTimeChanged
     *
     * This slot sets time, when
     * Do Not Disturb mode ends.
     *
     * \param time Time, when
     * Do Not Disturb mode ends.
     */
    void on_timeDndTo_userTimeChanged(const QTime &time);
};
#endif // MAINWINDOW_H
