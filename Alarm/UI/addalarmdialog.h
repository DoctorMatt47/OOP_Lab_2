#ifndef ADDALARMDIALOG_H
#define ADDALARMDIALOG_H

#include <QDialog>
#include <QTime>
#include <QVector>

namespace Ui {
class AddAlarmDialog;
}

class AddAlarmDialog : public QDialog
{
    Q_OBJECT

private:
    /*! Window. */
    Ui::AddAlarmDialog *ui;

    /*! Time of Alarm */
    QTime _time;

    /*! Days of week */
    QVector<bool> _daysOfWeek;

    /*!
     * \brief TimeRefresh
     *
     * Sets field "_time" to the window.
     */
    void TimeRefresh();

public:
    /*!
     * \brief AddAlarmDialog
     *
     * Default constructor.
     *
     * \param parent Parent object.
     */
    explicit AddAlarmDialog(QWidget *parent = nullptr);

    /*!
     * \brief ~AddAlarmDialog
     *
     * Default destructor. Destruct the object.
     */
    ~AddAlarmDialog();

    /*!
     * \brief GetTime
     *
     * Returns the time set in the window.
     *
     * \return Time set in the window.
     */
    QTime GetTime();

    /*!
     * \brief GetName
     *
     * Returns the name set in the window.
     *
     * \return Name set in the window.
     */
    QString GetName();

    /*!
     * \brief GetInfo
     *
     * Returns the information set in the window.
     *
     * \return Information set in the window.
     */
    QString GetInfo();

    /*!
     * \brief GetPath
     *
     * Returns the path set in the window.
     *
     * \return Path set in the window.
     */
    QString GetPath();

    /*!
     * \brief GetDaysOfWeek
     *
     * Returns days of week.
     *
     * \return Days of week.
     */
    QVector<bool> GetDaysOfWeek();

private slots:
    /*!
     * \brief on_increaseSecondsButton_clicked
     *
     * This slot increases seconds by one.
     */
    void on_increaseSecondsButton_clicked();

    /*!
     * \brief on_decreaseSecondsButton_clicked
     *
     * This slot decreases seconds by one.
     */
    void on_decreaseSecondsButton_clicked();

    /*!
     * \brief on_increaseMinutesButton_clicked
     *
     * This slot increases minutes by one.
     */
    void on_increaseMinutesButton_clicked();

    /*!
     * \brief on_decreaseMinutesButton_clicked
     *
     * This slot decreases minutes by one.
     */
    void on_decreaseMinutesButton_clicked();

    /*!
     * \brief on_increaseHoursButton_clicked
     *
     * This slot increases hours by one.
     */
    void on_increaseHoursButton_clicked();

    /*!
     * \brief on_decreaseHoursButton_clicked
     *
     * This slot decreases hours by one.
     */
    void on_decreaseHoursButton_clicked();

    /*!
     * \brief on_applyButton_clicked
     *
     * This slot hides this window and creates new alarm.
     */
    void on_applyButton_clicked();

    /*!
     * \brief on_cancelButton_clicked
     *
     * This slot hides this window and does not create new alarm.
     */
    void on_cancelButton_clicked();

    /*!
     * \brief on_monButton_clicked
     *
     * Adds  or removes Monday to the days of week vector.
     */
    void on_monButton_clicked();

    /*!
     * \brief on_tueButton_clicked
     *
     * Adds  or removes Tuesday to the days of week vector.
     */
    void on_tueButton_clicked();

    /*!
     * \brief on_wedButton_clicked
     *
     * Adds  or removes Wednessday to the days of week vector.
     */
    void on_wedButton_clicked();

    /*!
     * \brief on_thuButton_clicked
     *
     * Adds or removes Thursday to the days of week vector.
     */
    void on_thuButton_clicked();

    /*!
     * \brief on_friButton_clicked
     *
     * Adds or removes Friday to the days of week vector.
     */
    void on_friButton_clicked();

    /*!
     * \brief on_satButton_clicked
     *
     * Adds or removes Saturday to the days of week vector.
     */
    void on_satButton_clicked();

    /*!
     * \brief on_sunButton_clicked
     *
     * Adds or removes Sunday to the days of week vector.
     */
    void on_sunButton_clicked();


    /*!
     * \brief on_toolButton_clicked
     *
     * This slot shows selection path window.
     */
    void on_toolButton_clicked();
};

#endif // ADDALARMDIALOG_H
