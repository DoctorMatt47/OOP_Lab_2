#ifndef ALARM_H
#define ALARM_H

#include <QObject>

class Alarm : public QObject
{
    Q_OBJECT
public:
    explicit Alarm(QObject *parent = nullptr);

signals:

};

#endif // ALARM_H
