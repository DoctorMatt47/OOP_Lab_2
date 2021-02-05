#include "timer.h"

/*!
 * \brief Timer
 *
 * Constructor with params.
 * Creates timer with passed arguments.
 *
 * \param timeMax Left time for timer call at the starting position.
 * \param name Name of the timer.
 * \param info Information about this timer.
 * \param ringtonPath Path for rington.
 */
Timer::Timer(QTime timeMax, QString name, QString info, QString ringtonPath)
{
    _timeMax = timeMax;
    _name = name;
    _info = info;
    _timeLeft = timeMax;
    _ringtonPath = ringtonPath;
    _isActive = false;
    _isStarted = false;
    _dateTimeOfCreating = QDateTime::currentDateTime();

    _bellDlg = new BellDialog();
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));

}

/*!
 * \brief Timer
 *
 * Copy constructor. Constructs the timer
 *  with the copy of the contents of other.
 *
 * \param t Another timer to be used as source
 *  to initialize the elements of the timer with.
 */
Timer::Timer(const Timer &t)
{
    _timeLeft = t._timeLeft;
    _timeMax = t._timeMax;
    _name = t._name;
    _info = t._info;
    _isActive = t._isActive;
    _isStarted = t._isStarted;
    _dateTimeOfCreating = QDateTime::currentDateTime();
    _timeDndFrom = t._timeDndFrom;
    _timeDndTo = t._timeDndTo;
    _ringtonPath = t._ringtonPath;

    _bellDlg = new BellDialog();
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));
}

/*!
 * \brief ~MainWindow
 *
 * Default destructor. Destruct the object.
 */
Timer::~Timer()
{
    disconnect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));
    delete _timer;
    delete _bellDlg;
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
void Timer::SetDndTime(QTime *timeDndFrom, QTime *timeDndTo)
{
    _timeDndFrom = timeDndFrom;
    _timeDndTo = timeDndTo;
}

/*!
 * \brief GetName
 *
 * Returns name of the timer.
 *
 * \return Name of the timer.
 */
QString Timer::GetName()
{
    return _name;
}

/*!
 * \brief GetInfo
 *
 * Returns information of the timer.
 *
 * \return Information of the timer.
 */
QString Timer::GetInfo()
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
QTime Timer::GetLeftTime()
{
    return _timeLeft;
}

/*!
 * \brief GetMaxTime
 *
 * Returns left time to the timer call at the starting position.
 *
 * \return Left time to the timer call at the starting position.
 */
QTime Timer::GetMaxTime()
{
    return _timeMax;
}

/*!
 * \brief GetIsActive
 *
 * Returns true, if timer is active and false if is not.
 *
 * \return Is timer active.
 */
bool Timer::GetIsActive()
{
    return _isActive;
}

/*!
 * \brief GetIsStarted
 *
 * Returns true, if timer was started and false if was not.
 *
 * \return Is timer was started.
 */
bool Timer::GetIsStarted()
{
    return _isStarted;
}

/*!
 * \brief GetDateTimeOfCreating
 *
 * Returns date and time of timer creating.
 *
 * \return Date and time of timer creating.
 */
QDateTime Timer::GetDateTimeOfCreating()
{
    return _dateTimeOfCreating;
}

/*!
 * \brief GetPercentOfProgress
 *
 * Returns percent of timer progress.
 *
 * \return Percent of timer progress.
 */
double Timer::GetPercentOfProgress()
{
    double timeLeftSecs = _timeLeft.hour() * 60 * 60 + _timeLeft.minute() * 60 + _timeLeft.second();
    double timeMaxSecs = _timeMax.hour() * 60 * 60 + _timeMax.minute() * 60 + _timeMax.second();
    return (timeMaxSecs - timeLeftSecs) / timeMaxSecs;
}

/*!
 * \brief Start
 *
 * Starts the timer.
 *
 * \return True, if worked correctly.
 */
bool Timer::Start()
{
    if (!_isStarted)
    {
        _timer->start(1000);
        _timeLeft = _timeMax;
        _isStarted = true;
        _isActive = true;
        return true;
    }
    return false;
}

/*!
 * \brief Stop
 *
 * Stops the timer.
 *
 * \return True, if worked correctly.
 */
bool Timer::Stop()
{
    if (_isStarted)
    {
        _timer->stop();
        _timeLeft = _timeMax;
        _isStarted = false;
        _isActive = false;
        return true;
    }
    return false;
}

/*!
 * \brief Pause
 *
 * Pauses the timer.
 *
 * \return True, if worked correctly.
 */
bool Timer::Pause()
{
    if (_isStarted && _isActive)
    {
        _timer->stop();
        _isActive = false;
        return true;
    }
    return false;
}

/*!
 * \brief Continue
 *
 * Continues the timer.
 *
 * \return True, if worked correctly.
 */
bool Timer::Continue()
{
    if (_isStarted && !_isActive)
    {
        _timer->start(1000);
        _isActive = true;
        return true;
    }
    return false;
}

/*!
 * \brief OnTick
 *
 * This slot called each second. Decrease left time by one second.
 * Check for end of the time and display dialog box.
 */
void Timer::OnTick()
{
    _timeLeft = _timeLeft.addSecs(-1);
    if (_timeLeft.hour() == 0 && _timeLeft.minute() == 0 && _timeLeft.second() == 0)
    {
        Stop();
        Call();
        if (QTime::currentTime() < *_timeDndFrom || QTime::currentTime() > *_timeDndTo)
        {
            _bellDlg->AddName(_name);
            _bellDlg->AddInfo(_info);
            _bellDlg->AddSound(_ringtonPath);
            _bellDlg->show();
        }
    }
    TimeDecrease();
}
