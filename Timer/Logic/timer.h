#ifndef TIMER_H
#define TIMER_H

#include <QDateTime>
#include <QObject>
#include <QTimer>

#include <Main/UI/belldialog.h>

/*!
 * \brief The Timer class
 *
 * Represents Timer clock for a specific time.
 * Displays a dialog box when the set amount of time has passed.
 */
class Timer : public QObject
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

    /*! Left time for timer call at the moment. */
    QTime _timeLeft;

    /*! Left time for timer call at the starting position. */
    QTime _timeMax;

    /*! Name of the timer. */
    QString _name;

    /*! Information about this timer. */
    QString _info;

    /*! Path of rington. */
    QString _ringtonPath;

    /*! Date and time of timer creating. */
    QDateTime _dateTimeOfCreating;

    /*! True, if timer is active, else false.*/
    bool _isActive;

    /*! True if timer was started, else false.*/
    bool _isStarted;

public:
    /*!
     * \brief Timer
     *
     * Default constructor.
     *
     * \param parent Parent object.
     */
    explicit Timer(QObject *parent = nullptr) = delete;

    /*!
     * \brief Timer
     *
     * Constructor with params.
     * Creates timer with passed arguments.
     *
     * \param timeMax Left time for timer call at the starting position.
     * \param name Name of the timer.
     * \param info Information about this timer.
     * \param ringtonPath Path of rington.
     */
    Timer(QTime timeMax, QString name, QString info, QString ringtonPath);

    /*!
     * \brief Timer
     *
     * Copy constructor. Constructs the timer
     * with the copy of the contents of other.
     *
     * \param t Another timer to be used as source
     *  to initialize the elements of the timer with.
     */
    Timer(const Timer& t);

    /*!
     * \brief ~Timer
     *
     * Default destructor. Destruct the object.
     */
    ~Timer();

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
     * \brief GetName
     *
     * Returns name of the timer.
     *
     * \return Name of the timer.
     */
    QString GetName();

    /*!
     * \brief GetInfo
     *
     * Returns information of the timer.
     *
     * \return Information of the timer.
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
     * \brief GetMaxTime
     *
     * Returns left time to the timer call at the starting position.
     *
     * \return Left time to the timer call at the starting position.
     */
    QTime GetMaxTime();


    /*!
     * \brief GetIsActive
     *
     * Returns true, if timer is active and false if is not.
     *
     * \return Is timer active.
     */
    bool GetIsActive();

    /*!
     * \brief GetIsStarted
     *
     * Returns true, if timer was started and false if was not.
     *
     * \return Is timer was started.
     */
    bool GetIsStarted();


    /*!
     * \brief GetDateTimeOfCreating
     *
     * Returns date and time of timer creating.
     *
     * \return Date and time of timer creating.
     */
    QDateTime GetDateTimeOfCreating();


    /*!
     * \brief GetPercentOfProgress
     *
     * Returns percent of timer progress.
     *
     * \return Percent of timer progress.
     */
    double GetPercentOfProgress();


    /*!
     * \brief Start
     *
     * Starts the timer.
     *
     * \return True, if worked correctly.
     */
    bool Start();

    /*!
     * \brief Stop
     *
     * Stops the timer.
     *
     * \return True, if worked correctly.
     */
    bool Stop();

    /*!
     * \brief Pause
     *
     * Pauses the timer.
     *
     * \return True, if worked correctly.
     */
    bool Pause();

    /*!
     * \brief Continue
     *
     * Continues the timer.
     *
     * \return True, if worked correctly.
     */
    bool Continue();

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

    /*!
     * \brief Call
     *
     * This signal calls when the timer rings.
     */
    void Call();
};

#endif // TIMER_H
