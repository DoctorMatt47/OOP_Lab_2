#include "Alarm/UI/addalarmdialog.h"
#include "Timer/UI/addtimerdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //this->setWindowFlags(Qt::CustomizeWindowHint);
    _index = -1;
    _isTimer = true;
    ui->setupUi(this);
    ui->buttonStop->hide();
    ui->buttonContinue->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    for (auto var : _timers)
        delete var;
}

void MainWindow::OnTimeDecrease()
{
    if (_isTimer)
        ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
    else
    {
        ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->labelDaysLeft->setText(QString::number(_alarms[_index]->GetLeftDays()) + " days");
    }
}

void MainWindow::on_buttonChangeTimer_clicked()
{
    this->hide();
    AddTimerDialog dlg;
    dlg.setModal(true);
    if(dlg.exec() == QDialog::Accepted)
    {
        auto timer = new Timer(dlg.GetTime(), dlg.GetName(), dlg.GetInfo(), dlg.GetPath());
        _timers.push_back(timer);
        ui->listTimers->addItem(_timers.back()->GetName());
    }
    this->show();
}

void MainWindow::on_buttonChangeAlarm_clicked()
{
    this->hide();
    AddAlarmDialog dlg;
    dlg.setModal(true);
    if(dlg.exec() == QDialog::Accepted)
    {
        auto alarm = new Alarm(dlg.GetTime(), dlg.GetName(), dlg.GetInfo(), dlg.GetPath(), dlg.GetDaysOfWeek());
        _alarms.push_back(alarm);
        ui->listAlarms->addItem(_alarms.back()->GetName());
    }
    this->show();
}

void MainWindow::on_listTimers_itemClicked(QListWidgetItem *item)
{
    if (_index != -1)
    {
        if (_isTimer)
            disconnect(_timers[_index], SIGNAL(TimeDecrease()), this, SLOT(OnTimeDecrease()));
        else
            disconnect(_alarms[_index], SIGNAL(TimeDecrease()), this, SLOT(OnTimeDecrease()));
    }

    _index = ui->listTimers->currentRow();
    _isTimer = true;

    ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
    ui->labelName->setText(_timers[_index]->GetName());
    ui->labelInfo->setText(_timers[_index]->GetInfo());
    ui->labelDate->setText(_timers[_index]->GetDateTimeOfCreating().date().toString());
    ui->labelTime->setText(_timers[_index]->GetDateTimeOfCreating().time().toString("hh:mm:ss"));
    ui->labelDaysLeft->setText(QString::Null());

    if (_timers[_index]->GetIsActive())
    {
        ui->buttonPause->show();
        ui->buttonContinue->hide();
    }
    else
    {
        ui->buttonContinue->show();
        ui->buttonPause->hide();
    }
    if (_timers[_index]->GetIsStarted())
    {
        ui->buttonStop->show();
        ui->buttonStart->hide();
    }
    else
    {
        ui->buttonStart->show();
        ui->buttonStop->hide();
    }

    connect(_timers[_index], SIGNAL(TimeDecrease()), this, SLOT(OnTimeDecrease()));
}

void MainWindow::on_buttonStop_clicked()
{
    if (_index == -1)
        return;
    if(_timers[_index]->Stop())
    {
        ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->buttonStop->hide();
        ui->buttonStart->show();
        ui->buttonContinue->show();
        ui->buttonPause->hide();
    }
}

void MainWindow::on_buttonStart_clicked()
{
    if (_index == -1)
        return;
    if (_timers[_index]->Start())
    {
        ui->buttonStart->hide();
        ui->buttonStop->show();
        ui->buttonContinue->hide();
        ui->buttonPause->show();
    }
}

void MainWindow::on_buttonContinue_clicked()
{
    if (_index == -1)
        return;
    if (_isTimer)
    {
        if (_timers[_index]->Continue())
        {
            ui->buttonContinue->hide();
            ui->buttonPause->show();
        }
    }
    else
    {
        _alarms[_index]->On();
        ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->labelDaysLeft->setText(QString::number(_alarms[_index]->GetLeftDays()) + " days");
        ui->buttonContinue->hide();
        ui->buttonPause->show();
    }
}

void MainWindow::on_buttonPause_clicked()
{
    if (_index == -1)
        return;
    if (_isTimer)
    {
        if (_timers[_index]->Pause())
        {
            ui->buttonPause->hide();
            ui->buttonContinue->show();
        }
    }
    else
    {
        _alarms[_index]->Off();
        ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->labelDaysLeft->setText(QString::number(_alarms[_index]->GetLeftDays()) + " days");
        ui->buttonContinue->show();
        ui->buttonPause->hide();
    }
}

void MainWindow::on_listAlarms_itemClicked(QListWidgetItem *item)
{
    if (_index != -1)
    {
        if (_isTimer)
            disconnect(_timers[_index], SIGNAL(TimeDecrease()), this, SLOT(OnTimeDecrease()));
        else
            disconnect(_alarms[_index], SIGNAL(TimeDecrease()), this, SLOT(OnTimeDecrease()));
    }

    _index = ui->listAlarms->currentRow();
    _isTimer = false;

    ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
    ui->labelName->setText(_alarms[_index]->GetName());
    ui->labelInfo->setText(_alarms[_index]->GetInfo());
    ui->labelDate->setText(_alarms[_index]->GetDateTimeOfCreating().date().toString());
    ui->labelTime->setText(_alarms[_index]->GetDateTimeOfCreating().time().toString("hh:mm:ss"));
    ui->labelDaysLeft->setText(QString::number(_alarms[_index]->GetLeftDays()) + " days");

    ui->buttonStart->setVisible(false);
    ui->buttonStop->setVisible(false);

    if (_alarms[_index]->GetIsActive())
    {
        ui->buttonPause->show();
        ui->buttonContinue->hide();
    }
    else
    {
        ui->buttonContinue->show();
        ui->buttonPause->hide();
    }

    connect(_alarms[_index], SIGNAL(TimeDecrease()), this, SLOT(OnTimeDecrease()));
}
