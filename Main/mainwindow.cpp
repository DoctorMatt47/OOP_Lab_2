#include "Alarm/addalarmdialog.h"
#include "Timer/addtimerdialog.h"
#include "Main/mainwindow.h"
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
    ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
}

void MainWindow::on_buttonChangeTimer_clicked()
{
    this->hide();
    AddTimerDialog dlg;
    dlg.setModal(true);
    if(dlg.exec() == QDialog::Accepted)
    {
        auto timer = new Timer(dlg.GetTime(), dlg.GetName(), dlg.GetInfo());
        _timers.push_back(timer);
        ui->listTimers->addItem(_timers.back()->GetName());
    }
    this->show();
}

void MainWindow::on_buttonChangeAlarm_clicked()
{
    auto dlg = new AddAlarmDialog();
    dlg->show();
}

void MainWindow::on_listTimers_itemClicked(QListWidgetItem *item)
{
    if (_index != -1)
        disconnect(_timers[_index], SIGNAL(TimeDecrease()), this, SLOT(OnTimeDecrease()));

    _index = ui->listTimers->currentRow();
    _isTimer = true;
    ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
    ui->labelName->setText(_timers[_index]->GetName());
    ui->labelInfo->setText(_timers[_index]->GetInfo());
    ui->labelDate->setText(_timers[_index]->GetDateTimeOfCreating().date().toString());
    ui->labelTime->setText(_timers[_index]->GetDateTimeOfCreating().time().toString("hh:mm:ss"));

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
    if (_isTimer)
    {
        if(_timers[_index]->Stop())
       {
            ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
            ui->buttonStop->hide();
            ui->buttonStart->show();
            ui->buttonContinue->show();
            ui->buttonPause->hide();
        }
    }
    else
    {

    }
}

void MainWindow::on_buttonStart_clicked()
{
    if (_index == -1)
        return;
    if (_isTimer)
    {
        if (_timers[_index]->Start())
        {
            ui->buttonStart->hide();
            ui->buttonStop->show();
            ui->buttonContinue->hide();
            ui->buttonPause->show();
        }
    }
    else
    {

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

    }
}
