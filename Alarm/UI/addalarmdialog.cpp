#include "addalarmdialog.h"
#include "ui_addalarmdialog.h"

#include <QFileDialog>

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

QTime AddAlarmDialog::GetTime()
{
    return _time;
}

QString AddAlarmDialog::GetName()
{
    return ui->nameText->toPlainText();
}

QString AddAlarmDialog::GetInfo()
{
    return ui->infoText->toPlainText();
}

QString AddAlarmDialog::GetPath()
{
    return ui->ringtoneText->toPlainText();
}

AddAlarmDialog::~AddAlarmDialog()
{
    delete ui;
}

QVector<bool> AddAlarmDialog::GetDaysOfWeek()
{
    return _daysOfWeek;
}

void AddAlarmDialog::on_increaseSecondsButton_clicked()
{
    _time = _time.addSecs(1);
    TimeRefresh();
}

void AddAlarmDialog::on_decreaseSecondsButton_clicked()
{
    _time = _time.addSecs(-1);
    TimeRefresh();
}

void AddAlarmDialog::on_increaseMinutesButton_clicked()
{
    _time = _time.addSecs(1 * 60);
    TimeRefresh();
}

void AddAlarmDialog::on_decreaseMinutesButton_clicked()
{
    _time = _time.addSecs(-1 * 60);
    TimeRefresh();
}

void AddAlarmDialog::on_increaseHoursButton_clicked()
{
    _time = _time.addSecs(1 * 60 * 60);
    TimeRefresh();
}

void AddAlarmDialog::on_decreaseHoursButton_clicked()
{
    _time = _time.addSecs(-1 * 60 * 60);
    TimeRefresh();
}

void AddAlarmDialog::TimeRefresh()
{
    ui->timeLabel->setText(_time.toString("hh:mm:ss"));
}

void AddAlarmDialog::on_cancelButton_clicked()
{
    this->close();
}

void AddAlarmDialog::on_applyButton_clicked()
{
    if (!ui->nameText->toPlainText().isEmpty() && !_daysOfWeek.empty())
        this->accept();
}

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
