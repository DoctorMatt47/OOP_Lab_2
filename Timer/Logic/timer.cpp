#include "timer.h"

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

Timer::Timer(const Timer &t)
{
    _timeLeft = t._timeLeft;
    _timeMax = t._timeMax;
    _name = t._name;
    _info = t._info;
    _isActive = t._isActive;
    _isStarted = t._isStarted;
    _dateTimeOfCreating = QDateTime::currentDateTime();

    _bellDlg = new BellDialog();
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));
}

Timer::~Timer()
{
    disconnect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));
    delete _timer;
    delete _bellDlg;
}

QString Timer::GetName()
{
    return _name;
}

QString Timer::GetInfo()
{
    return _info;
}

QTime Timer::GetLeftTime()
{
    return _timeLeft;
}

bool Timer::GetIsActive()
{
    return _isActive;
}

bool Timer::GetIsStarted()
{
    return _isStarted;
}

QDateTime Timer::GetDateTimeOfCreating()
{
    return _dateTimeOfCreating;
}

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

void Timer::OnTick()
{
    _timeLeft = _timeLeft.addSecs(-1);
    TimeDecrease();
    if (_timeLeft.hour() == 0 && _timeLeft.minute() == 0 && _timeLeft.second() == 0)
    {
        Stop();
        _bellDlg->AddName(_name);
        _bellDlg->AddInfo(_info);
        _bellDlg->AddSound(_ringtonPath);
        _bellDlg->show();
    }
}
