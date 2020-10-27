#ifndef TIMER_H
#define TIMER_H

#include <QDateTime>
#include <QObject>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);

    Timer(QTime timeMax, QString name, QString info);

    Timer(const Timer& t);

    ~Timer();

    void SetName(QString name);

    void SetInfo(QString info);

    QString GetName();

    QString GetInfo();

    QTime GetLeftTime();

    bool GetIsActive();

    bool GetIsStarted();

    QDateTime GetDateTimeOfCreating();

    bool Start();

    bool Stop();

    bool Pause();

    bool Continue();

signals:
    void TimeDecrease();

private slots:
    void OnTick();

private:
    QTimer* _timer;
    QTime _timeLeft;
    QTime _timeMax;
    QString _name;
    QString _info;
    QDateTime _dateTimeOfCreating;
    bool _isActive;
    bool _isStarted;
};

#endif // TIMER_H
