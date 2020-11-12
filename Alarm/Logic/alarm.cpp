#include "alarm.h"
#include <QtMath>

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

Alarm::~Alarm()
{
    _timer->stop();
    disconnect(_timer, SIGNAL(timeout()), this, SLOT(OnTick()));
    delete _timer;
}

void Alarm::SetName(QString name)
{
    _name = name;
}

void Alarm::SetInfo(QString info)
{
    _info = info;
}

void Alarm::SetDndTime(QTime *timeDndFrom, QTime *timeDndTo)
{
    _timeDndFrom = timeDndFrom;
    _timeDndTo = timeDndTo;
}

int Alarm::GetLeftDays()
{
    return _daysLeft;
}

QString Alarm::GetName()
{
    return _name;
}

QString Alarm::GetInfo()
{
    return _info;
}

QTime Alarm::GetLeftTime()
{
    return _timeLeft;
}

bool Alarm::GetIsActive()
{
    return _isActive;
}

QDateTime Alarm::GetDateTimeOfCreating()
{
    return _dateTimeOfCreating;
}

void Alarm::On()
{
    _isActive = true;
    FindTimeLeft();
    _timer->start(1000);
}

void Alarm::Off()
{
    _isActive = false;
    _daysLeft = 0;
    _timeLeft.setHMS(0, 0, 0);
    _timer->stop();
}

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
