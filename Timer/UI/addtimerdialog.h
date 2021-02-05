#ifndef ADDTIMERDIALOG_H
#define ADDTIMERDIALOG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class AddTimerDialog;
}

/*!
 * \brief The AddTimerDialog class
 *
 * Represents a dialog box that can be used to create a new timer.
 * Allows manage created timer.
 */
class AddTimerDialog : public QDialog
{
    Q_OBJECT

private:
    /*! Window. */
    Ui::AddTimerDialog *ui;

    /*! Time of Timer */
    QTime _time;

    /*!
     * \brief TimeRefresh
     *
     * Sets field "_time" to the window.
     */
    void TimeRefresh();

public:
    /*!
     * \brief AddTimerDialog
     *
     * Default constructor.
     *
     * \param parent Parent object.
     */
    explicit AddTimerDialog(QWidget *parent = nullptr);

    /*!
     * \brief ~AddTimerDialog
     *
     * Default destructor. Destruct the object.
     */
    ~AddTimerDialog();

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
     * \brief on_cancelButton_clicked
     *
     * This slot hides this window and does not create new timer.
     */
    void on_cancelButton_clicked();

    /*!
     * \brief on_applyButton_clicked
     *
     * This slot hides this window and creates new timer.
     */
    void on_applyButton_clicked();

    /*!
     * \brief on_toolButton_clicked
     *
     * This slot shows selection path window.
     */
    void on_toolButton_clicked();
};

#endif // ADDTIMERDIALOG_H
