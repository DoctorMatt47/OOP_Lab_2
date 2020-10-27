#include "Main/mainwindow.h"
#include "Timer/addtimerdialog.h"
#include "ui_addtimerdialog.h"

AddTimerDialog::AddTimerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTimerDialog)
{
    ui->setupUi(this);
    _time = QTime(0,0,0,0);
}

AddTimerDialog::~AddTimerDialog()
{
    delete ui;
}

QTime AddTimerDialog::GetTime()
{
    return _time;
}

QString AddTimerDialog::GetName()
{
    return ui->nameText->toPlainText();
}

QString AddTimerDialog::GetInfo()
{
    return ui->infoText->toPlainText();
}

void AddTimerDialog::on_increaseSecondsButton_clicked()
{
    _time = _time.addSecs(1);
    TimeRefresh();
}

void AddTimerDialog::on_decreaseSecondsButton_clicked()
{
    _time = _time.addSecs(-1);
    TimeRefresh();
}

void AddTimerDialog::on_increaseMinutesButton_clicked()
{
    _time = _time.addSecs(1 * 60);
    TimeRefresh();
}

void AddTimerDialog::on_decreaseMinutesButton_clicked()
{
    _time = _time.addSecs(-1 * 60);
    TimeRefresh();
}

void AddTimerDialog::on_increaseHoursButton_clicked()
{
    _time = _time.addSecs(1 * 60 * 60);
    TimeRefresh();
}

void AddTimerDialog::on_decreaseHoursButton_clicked()
{
    _time = _time.addSecs(-1 * 60 * 60);
    TimeRefresh();
}

void AddTimerDialog::TimeRefresh()
{
    ui->timeLabel->setText(_time.toString("hh:mm:ss"));
}

void AddTimerDialog::on_cancelButton_clicked()
{
    this->close();
}

void AddTimerDialog::on_applyButton_clicked()
{
    this->accept();
}
