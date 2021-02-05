#include "addalarmdialog.h"
#include "ui_addalarmdialog.h"

#include <QFileDialog>

/*!
 * \brief AddAlarmDialog
 *
 * Default constructor.
 *
 * \param parent Parent object.
 */
AddAlarmDialog::AddAlarmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAlarmDialog)
{
    ui->setupUi(this);
    _time = QTime(0,0,0,0);
    ui->ringtoneText->setText("F:\\Project\\OOP_Lab_2\\Resources\\nice_alarm_sound.mp3");

    for (auto i = 0; i < 7; i++)
        _daysOfWeek.push_back(false);
}

/*!
 * \brief GetTime
 *
 * Returns the time set in the window.
 *
 * \return Time set in the window.
 */
QTime AddAlarmDialog::GetTime()
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
QString AddAlarmDialog::GetName()
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
QString AddAlarmDialog::GetInfo()
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
QString AddAlarmDialog::GetPath()
{
    return ui->ringtoneText->toPlainText();
}

/*!
 * \brief ~AddAlarmDialog
 *
 * Default destructor. Destruct the object.
 */
AddAlarmDialog::~AddAlarmDialog()
{
    delete ui;
}

/*!
 * \brief GetDaysOfWeek
 *
 * Returns days of week.
 *
 * \return Days of week.
 */
QVector<bool> AddAlarmDialog::GetDaysOfWeek()
{
    return _daysOfWeek;
}

/*!
 * \brief on_increaseSecondsButton_clicked
 *
 * This slot increases seconds by one.
 */
void AddAlarmDialog::on_increaseSecondsButton_clicked()
{
    _time = _time.addSecs(1);
    TimeRefresh();
}

/*!
 * \brief on_decreaseSecondsButton_clicked
 *
 * This slot decreases seconds by one.
 */
void AddAlarmDialog::on_decreaseSecondsButton_clicked()
{
    _time = _time.addSecs(-1);
    TimeRefresh();
}

/*!
 * \brief on_increaseMinutesButton_clicked
 *
 * This slot increases minutes by one.
 */
void AddAlarmDialog::on_increaseMinutesButton_clicked()
{
    _time = _time.addSecs(1 * 60);
    TimeRefresh();
}

/*!
 * \brief on_decreaseMinutesButton_clicked
 *
 * This slot decreases minutes by one.
 */
void AddAlarmDialog::on_decreaseMinutesButton_clicked()
{
    _time = _time.addSecs(-1 * 60);
    TimeRefresh();
}

/*!
 * \brief on_increaseHoursButton_clicked
 *
 * This slot increases hours by one.
 */
void AddAlarmDialog::on_increaseHoursButton_clicked()
{
    _time = _time.addSecs(1 * 60 * 60);
    TimeRefresh();
}

/*!
 * \brief on_decreaseHoursButton_clicked
 *
 * This slot decreases hours by one.
 */
void AddAlarmDialog::on_decreaseHoursButton_clicked()
{
    _time = _time.addSecs(-1 * 60 * 60);
    TimeRefresh();
}

/*!
 * \brief TimeRefresh
 *
 * Sets field "_time" to the window.
 */
void AddAlarmDialog::TimeRefresh()
{
    ui->timeLabel->setText(_time.toString("hh:mm:ss"));
}

/*!
 * \brief on_cancelButton_clicked
 *
 * This slot hides this window and does not create new alarm.
 */
void AddAlarmDialog::on_cancelButton_clicked()
{
    this->close();
}

/*!
 * \brief on_applyButton_clicked
 *
 * This slot hides this window and creates new alarm.
 */
void AddAlarmDialog::on_applyButton_clicked()
{
    if (!ui->nameText->toPlainText().isEmpty() && !_daysOfWeek.empty())
        this->accept();
}

/*!
 * \brief on_monButton_clicked
 *
 * Adds  or removes Monday to the days of week vector.
 */
void AddAlarmDialog::on_monButton_clicked()
{
    if (!_daysOfWeek[0])
    {
        _daysOfWeek[0] = true;
        ui->monButton->setAutoFillBackground(true);
        ui->monButton->setStyleSheet("color: rgb(0, 150, 0)");
    }
    else
    {
        _daysOfWeek[0] = false;
        ui->monButton->setAutoFillBackground(true);
        ui->monButton->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

/*!
 * \brief on_tueButton_clicked
 *
 * Adds  or removes Tuesday to the days of week vector.
 */
void AddAlarmDialog::on_tueButton_clicked()
{
    if (!_daysOfWeek[1])
    {
        _daysOfWeek[1] = true;
        ui->tueButton->setAutoFillBackground(true);
        ui->tueButton->setStyleSheet("color: rgb(0, 150, 0)");
    }
    else
    {
        _daysOfWeek[1] = false;
        ui->tueButton->setAutoFillBackground(true);
        ui->tueButton->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

/*!
 * \brief on_wedButton_clicked
 *
 * Adds  or removes Wednessday to the days of week vector.
 */
void AddAlarmDialog::on_wedButton_clicked()
{
    if (!_daysOfWeek[2])
    {
        _daysOfWeek[2] = true;
        ui->wedButton->setAutoFillBackground(true);
        ui->wedButton->setStyleSheet("color: rgb(0, 150, 0)");
    }
    else
    {
        _daysOfWeek[2] = false;
        ui->wedButton->setAutoFillBackground(true);
        ui->wedButton->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

/*!
 * \brief on_thuButton_clicked
 *
 * Adds or removes Thursday to the days of week vector.
 */
void AddAlarmDialog::on_thuButton_clicked()
{
    if (!_daysOfWeek[3])
    {
        _daysOfWeek[3] = true;
        ui->thuButton->setAutoFillBackground(true);
        ui->thuButton->setStyleSheet("color: rgb(0, 150, 0)");
    }
    else
    {
        _daysOfWeek[3] = false;
        ui->thuButton->setAutoFillBackground(true);
        ui->thuButton->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

/*!
 * \brief on_friButton_clicked
 *
 * Adds or removes Friday to the days of week vector.
 */
void AddAlarmDialog::on_friButton_clicked()
{
    if (!_daysOfWeek[4])
    {
        _daysOfWeek[4] = true;
        ui->friButton->setAutoFillBackground(true);
        ui->friButton->setStyleSheet("color: rgb(0, 150, 0)");
    }
    else
    {
        _daysOfWeek[4] = false;
        ui->friButton->setAutoFillBackground(true);
        ui->friButton->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

/*!
 * \brief on_satButton_clicked
 *
 * Adds or removes Saturday to the days of week vector.
 */
void AddAlarmDialog::on_satButton_clicked()
{
    if (!_daysOfWeek[5])
    {
        _daysOfWeek[5] = true;
        ui->satButton->setAutoFillBackground(true);
        ui->satButton->setStyleSheet("color: rgb(0, 150, 0)");
    }
    else
    {
        _daysOfWeek[5] = false;
        ui->satButton->setAutoFillBackground(true);
        ui->satButton->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

/*!
 * \brief on_sunButton_clicked
 *
 * Adds or removes Sunday to the days of week vector.
 */
void AddAlarmDialog::on_sunButton_clicked()
{
    if (!_daysOfWeek[6])
    {
        _daysOfWeek[6] = true;
        ui->sunButton->setAutoFillBackground(true);
        ui->sunButton->setStyleSheet("color: rgb(0, 150, 0)");
    }
    else
    {
        _daysOfWeek[6] = false;
        ui->sunButton->setAutoFillBackground(true);
        ui->sunButton->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

/*!
 * \brief on_toolButton_clicked
 *
 * This slot shows selection path window.
 */
void AddAlarmDialog::on_toolButton_clicked()
{
    QFileDialog fileDlg;
    this->hide();
    fileDlg.setModal(true);
    fileDlg.exec();

        auto url = fileDlg.getOpenFileUrl();
        ui->ringtoneText->setText(url.path());

    this->show();
}
