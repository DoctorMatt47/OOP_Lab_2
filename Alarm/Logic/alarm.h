#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QMap>
#include <QDateTime>
#include <QTimer>
#include <QVector>

#include "Main/UI/belldialog.h"

/*!
 * \brief The Alarm class
 *
 * Represents Alarm clock for a specific time and specific days.
 * Displays a dialog box when the set time arrives.
 */
class Alarm : public QObject
{
    Q_OBJECT

private:
    /*! Dialog box, will be displayed when the timer rings. */
    BellDialog* _bellDlg;

    /*! QTimer object */
    QTimer* _timer;

    /*! Time from which Do Not Disturb mode starts. */
    QTime* _timeDndFrom;

    /*! Time, when Do Not Disturb mode ends. */
    QTime* _timeDndTo;

    /*! Time, when alarm will call. */
    QTime _timeAlarm;

    /*! Left time for timer call at the moment. */
    QTime _timeLeft;

    /*! Name of the alarm. */
    QString _name;

    /*! Information about this alarm. */
    QString _info;

    /*! Path of rington. */
    QString _ringtonPath;

    /*! Date and time of timer creating. */
    QDateTime _dateTimeOfCreating;

    /*! Days of week, when alarm will call. */
    QVector<bool> _daysOfWeek;

    /*! Amount of left days to alarm call. */
    int _daysLeft;

    /*! True, if timer is active, else false. */
    bool _isActive;


    /*!
     * \brief FindTimeLeft
     *
     * Finds amount of left days and time to the alarm call.
     */
    void FindTimeLeft();

public:
    /*!
     * \brief Alarm
     *
     * Default constructor.
     *
     * \param parent Parent object.
     */
    explicit Alarm(QObject *parent = nullptr) = delete;

    /*!
     * \brief Alarm
     *
     * Constructor with params.
     * Creates alarm with passed arguments.
     *
     * \param timeAlarm Time, when alarm will call.
     * \param name Name of the alarm.
     * \param info Information about this alarm.
     * \param ringtonPath Path of ringtone.
     * \param daysOfWeek Days of week, when alarm will call.
     */
    Alarm(QTime timeAlarm, QString name, QString info, QString ringtonPath, QVector<bool> daysOfWeek);

    /*!
     * \brief Alarm
     *
     * Copy constructor. Constructs the alarm
     * with the copy of the contents of other.
     *
     * \param other Another alarm to be used as source
     *  to initialize the elements of the alarm with.
     */
    Alarm(const Alarm& other);

    /*!
     * \brief ~Alarm
     *
     * Default destructor. Destruct the object.
     */
    ~Alarm();

    /*!
     * \brief SetDndTime
     *
     * Sets time from which Do Not Disturb mode starts
     * and sets time, when Do Not Disturb mode ends.
     *
     * \param timeDndFrom Time from which Do Not Disturb mode starts.
     * \param timeDndTo Time, when Do Not Disturb mode ends.
     */
    void SetDndTime(QTime* timeDndFrom, QTime* timeDndTo);

    /*!
     * \brief GetLeftDays
     *
     * Returns amount of the days, before alarm calls.
     *
     * \return Amount of the left days to alarm call.
     */
    int GetLeftDays();

    /*!
     * \brief GetName
     *
     * Returns name of the alarm.
     *
     * \return Name of the alarm.
     */
    QString GetName();

    /*!
     * \brief GetInfo
     *
     * Returns information of the alarm.
     *
     * \return Information of the alarm.
     */
    QString GetInfo();

    /*!
     * \brief GetLeftTime
     *
     * Returns left time to the timer call at the moment.
     *
     * \return Left time to the timer call at the moment.
     */
    QTime GetLeftTime();

    /*!
     * \brief GetIsActive
     *
     * Returns true, if alarm is active and false if is not.
     *
     * \return Is timer active.
     */
    bool GetIsActive();

    /*!
     * \brief GetDateTimeOfCreating
     *
     * Returns date and time of timer creating.
     *
     * \return Date and time of timer creating.
     */
    QDateTime GetDateTimeOfCreating();

    /*!
     * \brief On
     *
     * Enables timer, if it is not active.
     */
    void On();

    /*!
     * \brief Off
     *
     * Disables timer.
     */
    void Off();

private slots:
    /*!
     * \brief OnTick
     *
     * This slot called each second. Decrease left time by one second.
     * Check for end of the time and display dialog box.
     */
    void OnTick();

signals:
    /*!
     * \brief TimeDecrease
     *
     * This signal calls each second.
     */
    void TimeDecrease();
};

#endif // ALARM_H
