#include "alarm.h"
#include <QtMath>

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
Alarm::Alarm(QTime timeAlarm, QString name, QString info, QString ringtonPath, QVector<bool> daysOfWeek)
{
    _timeAlarm = timeAlarm;
    _name = name;
    _info = info;
    _ringtonPath = ringtonPath;
    _daysOfWeek = daysOfWeek;
    _timeLeft.setHMS(0, 0, 0);
    _daysLeft = 0;

    _dateTimeOfCreating = QDateTime::currentDateTime();

    _bellDlg = new BellDialog();

    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));

    FindTimeLeft();
    _timer->start(1000);
}

/*!
 * \brief Alarm
 *
 * Copy constructor. Constructs the alarm
 * with the copy of the contents of other.
 *
 * \param other Another alarm to be used as source
 *  to initialize the elements of the alarm with.
 */
Alarm::Alarm(const Alarm &other)
{
    _timeAlarm = other._timeAlarm;
    _timeLeft = other._timeLeft;
    _name = other._name;
    _info = other._info;
    _ringtonPath = other._ringtonPath;
    _daysOfWeek = other._daysOfWeek;
    _daysLeft = other._daysLeft;

    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));
}

/*!
 * \brief ~MainWindow
 *
 * Default destructor. Destruct the object.
 */
Alarm::~Alarm()
{
    _timer->stop();
    disconnect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));
    delete _timer;
}

/*!
 * \brief SetDndTime
 *
 * Sets time from which Do Not Disturb mode starts
 * and sets time, when Do Not Disturb mode ends.
 *
 * \param timeDndFrom Time from which Do Not Disturb mode starts.
 * \param timeDndTo Time, when Do Not Disturb mode ends.
 */
void Alarm::SetDndTime(QTime *timeDndFrom, QTime *timeDndTo)
{
    _timeDndFrom = timeDndFrom;
    _timeDndTo = timeDndTo;
}

/*!
 * \brief GetLeftDays
 *
 * Returns amount of the days, before alarm calls.
 *
 * \return Amount of the left days to alarm call.
 */
int Alarm::GetLeftDays()
{
    return _daysLeft;
}

/*!
 * \brief GetName
 *
 * Returns name of the alarm.
 *
 * \return Name of the alarm.
 */
QString Alarm::GetName()
{
    return _name;
}

/*!
 * \brief GetInfo
 *
 * Returns information of the alarm.
 *
 * \return Information of the alarm.
 */
QString Alarm::GetInfo()
{
    return _info;
}

/*!
 * \brief GetLeftTime
 *
 * Returns left time to the timer call at the moment.
 *
 * \return Left time to the timer call at the moment.
 */
QTime Alarm::GetLeftTime()
{
    return _timeLeft;
}

/*!
 * \brief GetIsActive
 *
 * Returns true, if alarm is active and false if is not.
 *
 * \return Is timer active.
 */
bool Alarm::GetIsActive()
{
    return _isActive;
}

/*!
 * \brief GetDateTimeOfCreating
 *
 * Returns date and time of timer creating.
 *
 * \return Date and time of timer creating.
 */
QDateTime Alarm::GetDateTimeOfCreating()
{
    return _dateTimeOfCreating;
}

/*!
 * \brief On
 *
 * Enables timer, if it is not active.
 */
void Alarm::On()
{
    _isActive = true;
    FindTimeLeft();
    _timer->start(1000);
}

/*!
 * \brief Off
 *
 * Disables timer.
 */
void Alarm::Off()
{
    _isActive = false;
    _daysLeft = 0;
    _timeLeft.setHMS(0, 0, 0);
    _timer->stop();
}

/*!
 * \brief OnTick
 *
 * This slot called each second. Decrease left time by one second.
 * Check for end of the time and display dialog box.
 */
void Alarm::OnTick()
{
    _timeLeft = _timeLeft.addSecs(-1);
    if (_timeLeft.hour() == 0 && _timeLeft.minute() == 0 && _timeLeft.second() == 0)
    {
        if (_daysLeft != 0)
        {
            _daysLeft--;
        }
        else
        {
            FindTimeLeft();
            if (!_isActive && (QTime::currentTime() < *_timeDndFrom || QTime::currentTime() > *_timeDndTo))
            {
                _bellDlg->AddName(_name);
                _bellDlg->AddInfo(_info);
                _bellDlg->AddSound(_ringtonPath);
                _bellDlg->show();
            }
        }
    }
    TimeDecrease();
}

/*!
 * \brief FindTimeLeft
 *
 * Finds amount of left days and time to the alarm call.
 */
void Alarm::FindTimeLeft()
{
   int dayOfWeek = QDate::currentDate().dayOfWeek();
   if (QTime::currentTime() < _timeAlarm)
   {
       dayOfWeek--;
   }
   for (auto i = dayOfWeek; i < _daysOfWeek.size() + dayOfWeek - 1; i++)
   {
       auto temp = i;
       if (i == _daysOfWeek.size())
       {
           i = _daysOfWeek.size() - i;
       }
       if (_daysOfWeek[i])
       {
           _daysLeft = qFabs(temp - dayOfWeek);
           _timeLeft = _timeLeft.addSecs(QTime::currentTime().secsTo(_timeAlarm));
           break;
       }
   }
}
