#include "Main/UI/mainwindow.h"
#include "addtimerdialog.h"
#include "ui_addtimerdialog.h"

#include <QFileDialog>

/*!
 * \brief AddTimerDialog
 *
 * Default constructor.
 *
 * \param parent Parent object.
 */
AddTimerDialog::AddTimerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTimerDialog)
{
    ui->setupUi(this);
    _time = QTime(0,0,0,0);
    ui->ringtoneText->setText("F:\\Project\\OOP_Lab_2\\Resources\\nice_alarm_sound.mp3");
}

/*!
 * \brief ~AddTimerDialog
 *
 * Default destructor. Destruct the object.
 */
AddTimerDialog::~AddTimerDialog()
{
    delete ui;
}

/*!
 * \brief GetTime
 *
 * Returns the time set in the window.
 *
 * \return Time set in the window.
 */
QTime AddTimerDialog::GetTime()
{
    return _time;
}

/*!
 * \brief GetName
 *
 * Returns the name set in the window.
 *
 * \return Name set in the window.
 */
QString AddTimerDialog::GetName()
{
    return ui->nameText->toPlainText();
}

/*!
 * \brief GetInfo
 *
 * Returns the information set in the window.
 *
 * \return Information set in the window.
 */
QString AddTimerDialog::GetInfo()
{
    return ui->infoText->toPlainText();
}

/*!
 * \brief GetPath
 *
 * Returns the path set in the window.
 *
 * \return Path set in the window.
 */
QString AddTimerDialog::GetPath()
{
    return ui->ringtoneText->toPlainText();
}

/*!
 * \brief on_increaseSecondsButton_clicked
 *
 * This slot increases seconds by one.
 */
void AddTimerDialog::on_increaseSecondsButton_clicked()
{
    _time = _time.addSecs(1);
    TimeRefresh();
}

/*!
 * \brief on_decreaseSecondsButton_clicked
 *
 * This slot decreases seconds by one.
 */
void AddTimerDialog::on_decreaseSecondsButton_clicked()
{
    _time = _time.addSecs(-1);
    TimeRefresh();
}

/*!
 * \brief on_increaseMinutesButton_clicked
 *
 * This slot increases minutes by one.
 */
void AddTimerDialog::on_increaseMinutesButton_clicked()
{
    _time = _time.addSecs(1 * 60);
    TimeRefresh();
}

/*!
 * \brief on_decreaseMinutesButton_clicked
 *
 * This slot decreases minutes by one.
 */
void AddTimerDialog::on_decreaseMinutesButton_clicked()
{
    _time = _time.addSecs(-1 * 60);
    TimeRefresh();
}

/*!
 * \brief on_increaseHoursButton_clicked
 *
 * This slot increases hours by one.
 */
void AddTimerDialog::on_increaseHoursButton_clicked()
{
    _time = _time.addSecs(1 * 60 * 60);
    TimeRefresh();
}

/*!
 * \brief on_decreaseHoursButton_clicked
 *
 * This slot decreases hours by one.
 */
void AddTimerDialog::on_decreaseHoursButton_clicked()
{
    _time = _time.addSecs(-1 * 60 * 60);
    TimeRefresh();
}

/*!
 * \brief on_cancelButton_clicked
 *
 * This slot hides this window and does not create new timer.
 */
void AddTimerDialog::TimeRefresh()
{
    ui->timeLabel->setText(_time.toString("hh:mm:ss"));
}

/*!
 * \brief on_applyButton_clicked
 *
 * This slot hides this window and creates new timer.
 */
void AddTimerDialog::on_cancelButton_clicked()
{
    this->close();
}

/*!
 * \brief on_toolButton_clicked
 *
 * This slot shows selection path window.
 */
void AddTimerDialog::on_applyButton_clicked()
{
    if (!ui->nameText->toPlainText().isEmpty())
        this->accept();
}

/*!
 * \brief TimeRefresh
 *
 * Sets field "_time" to the window.
 */
void AddTimerDialog::on_toolButton_clicked()
{
    QFileDialog fileDlg;
    this->hide();
    fileDlg.setModal(true);
    fileDlg.exec();

        auto url = fileDlg.getOpenFileUrl();
        ui->ringtoneText->setText(url.path());

    this->show();
}
