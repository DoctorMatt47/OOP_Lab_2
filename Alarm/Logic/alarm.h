#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QMap>
#include <QDateTime>
#include <QTimer>
#include <QVector>

#include "Main/UI/belldialog.h"

class Alarm : public QObject
{
    Q_OBJECT
public:
    explicit Alarm(QObject *parent = nullptr) = delete;

    Alarm(QTime timeAlarm, QString name, QString info, QString ringtonPath, QVector<bool> daysOfWeek);

    Alarm(const Alarm& other);

    ~Alarm();

    void SetName(QString name);

    void SetInfo(QString info);

    int GetLeftDays();

    QString GetName();

    QString GetInfo();

    QTime GetLeftTime();

    bool GetIsActive();

    QDateTime GetDateTimeOfCreating();

    void On();

    void Off();

signals:
    void TimeDecrease();

private slots:
    void OnTick();

private:
    int _daysLeft;
    BellDialog* _bellDlg;
    QTimer* _timer;
    QTime _timeAlarm;
    QTime _timeLeft;
    QString _name;
    QString _info;
    QString _ringtonPath;
    QDateTime _dateTimeOfCreating;
    QVector<bool> _daysOfWeek;
    bool _isActive;

    void FindTimeLeft();
};

#endif // ALARM_H
