#include "Alarm/UI/addalarmdialog.h"
#include "Timer/UI/addtimerdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
 * \brief MainWindow
 *
 * Default constructor.
 *
 * \param parent Parent object.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _index = -1;
    _isTimer = true;
    _amountOfActiveTimers = 0;
    _amountOfActiveAlarms = 0;
    _timeDndFrom.setHMS(0, 0, 1);
    _timeDndTo.setHMS(0, 0, 0);

    ui->setupUi(this);

    ui->buttonStop->hide();
    ui->buttonContinue->hide();
    ui->timeDndFrom->setEnabled(false);
    ui->timeDndTo->setEnabled(false);
    ui->labelFrom->setEnabled(false);
    ui->labelTo->setEnabled(false);
}

/*!
 * \brief ~MainWindow
 *
 * Default destructor. Destruct the object.
 */
MainWindow::~MainWindow()
{
    delete ui;
    for (auto timer : _timers)
        delete timer;
    for (auto alarm : _alarms)
        delete alarm;
}

/*!
 * \brief OnTimeDecrease
 *
 * This slot is connected to the TimeDecrease()
 * signal from the Timer or Alarm class. Each call
 * to this method enters information about connected
 * timer on main window.
 */
void MainWindow::OnTimeDecrease()
{
    if (_isTimer)
    {
        ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->progressBar->setValue(static_cast<int>(_timers[_index]->GetPercentOfProgress() * 100));
        if (!_timers[_index]->GetIsActive())
        {
            ui->buttonStart->show();
            ui->buttonStop->hide();
        }
    }
    else
    {
        ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->labelDaysLeft->setText(QString::number(_alarms[_index]->GetLeftDays()) + " days");
    }
}

void MainWindow::OnCall()
{
    _amountOfActiveTimers--;
    ui->labelActiveTimers->setText(QString::number(_amountOfActiveTimers));
    FindNameOfFirstTimer();
}

/*!
 * \brief on_buttonAddTimer_clicked
 *
 * This slot calls window of creating a new timer.
 */
void MainWindow::on_buttonAddTimer_clicked()
{
    this->hide();
    AddTimerDialog dlg;
    dlg.setModal(true);
    if(dlg.exec() == QDialog::Accepted)
    {
        auto timer = new Timer(dlg.GetTime(), dlg.GetName(), dlg.GetInfo(), dlg.GetPath());
        timer->SetDndTime(&_timeDndFrom, &_timeDndTo);
        _timers.push_back(timer);
        ui->listTimers->addItem(_timers.back()->GetName());
        connect(_timers.back(), &Timer::Call, this, &MainWindow::OnCall);
    }
    this->show();
}

/*!
 * \brief on_buttonAddAlarm_clicked
 *
 * This slot calls window of creating a new alarm.
 */
void MainWindow::on_buttonAddAlarm_clicked()
{
    this->hide();
    AddAlarmDialog dlg;
    dlg.setModal(true);
    if(dlg.exec() == QDialog::Accepted)
    {
        auto alarm = new Alarm(dlg.GetTime(), dlg.GetName(), dlg.GetInfo(), dlg.GetPath(), dlg.GetDaysOfWeek());
        alarm->SetDndTime(&_timeDndFrom, &_timeDndTo);
        _alarms.push_back(alarm);
        _amountOfActiveAlarms++;
        ui->listAlarms->addItem(_alarms.back()->GetName());
        ui->labelActiveAlarms->setText(QString::number(_amountOfActiveAlarms));
    }
    this->show();
}

/*!
 * \brief on_listTimers_itemClicked
 *
 * This slot enters information about selected
 * timer on main window.
 */
void MainWindow::on_listTimers_itemClicked()
{
    if (_index != -1)
    {
        if (_isTimer)
            disconnect(_timers[_index], &Timer::TimeDecrease, this, &MainWindow::OnTimeDecrease);
        else
            disconnect(_alarms[_index], &Alarm::TimeDecrease, this, &MainWindow::OnTimeDecrease);
    }

    _index = ui->listTimers->currentRow();
    _isTimer = true;

    ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
    ui->labelName->setText(_timers[_index]->GetName());
    ui->labelInfo->setText(_timers[_index]->GetInfo());
    ui->labelDate->setText(_timers[_index]->GetDateTimeOfCreating().date().toString());
    ui->labelTime->setText(_timers[_index]->GetDateTimeOfCreating().time().toString("hh:mm:ss"));
    ui->progressBar->setValue(static_cast<int>(_timers[_index]->GetPercentOfProgress() * 100));
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

    connect(_timers[_index], &Timer::TimeDecrease, this, &MainWindow::OnTimeDecrease);
}

/*!
 * \brief on_listAlarms_itemClicked
 *
 * This slot enters information about selected
 * alarm on main window.
 */
void MainWindow::on_listAlarms_itemClicked()
{
    if (_index != -1)
    {
        if (_isTimer)
            disconnect(_timers[_index], &Timer::TimeDecrease, this, &MainWindow::OnTimeDecrease);
        else
            disconnect(_alarms[_index], &Alarm::TimeDecrease, this, &MainWindow::OnTimeDecrease);
    }

    _index = ui->listAlarms->currentRow();
    _isTimer = false;

    ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
    ui->labelName->setText(_alarms[_index]->GetName());
    ui->labelInfo->setText(_alarms[_index]->GetInfo());
    ui->labelDate->setText(_alarms[_index]->GetDateTimeOfCreating().date().toString());
    ui->labelTime->setText(_alarms[_index]->GetDateTimeOfCreating().time().toString("hh:mm:ss"));
    ui->progressBar->setValue(0);
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

    connect(_alarms[_index], &Alarm::TimeDecrease, this, &MainWindow::OnTimeDecrease);
}

/*!
 * \brief on_buttonStop_clicked
 *
 * This slot stops the selected timer,
 * returns it to its starting position.
 */
void MainWindow::on_buttonStop_clicked()
{
    if (_index == -1)
        return;
    if(_timers[_index]->Stop())
    {
        _amountOfActiveTimers--;
        ui->labelActiveTimers->setText(QString::number(_amountOfActiveTimers));
        ui->labelTimeLeft->setText(_timers[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->labelFirstTimer->setText(FindNameOfFirstTimer());

        ui->buttonStop->hide();
        ui->buttonStart->show();
        ui->buttonContinue->show();
        ui->buttonPause->hide();
    }
}

/*!
 * \brief on_buttonStart_clicked
 *
 * This slot starts the selected timer.
 */
void MainWindow::on_buttonStart_clicked()
{
    if (_index == -1)
        return;
    if (_timers[_index]->Start())
    {
        _amountOfActiveTimers++;
        ui->labelActiveTimers->setText(QString::number(_amountOfActiveTimers));
        ui->labelFirstTimer->setText(FindNameOfFirstTimer());

        ui->buttonStart->hide();
        ui->buttonStop->show();
        ui->buttonContinue->hide();
        ui->buttonPause->show();
    }
}

/*!
 * \brief on_buttonContinue_clicked
 *
 * This slot continues selected timer or alarm,
 * if it was paused.
 */
void MainWindow::on_buttonContinue_clicked()
{
    if (_index == -1)
        return;
    if (_isTimer)
    {
        if (_timers[_index]->Continue())
        {
            _amountOfActiveTimers++;
            ui->labelActiveTimers->setText(QString::number(_amountOfActiveTimers));
            ui->buttonContinue->hide();
            ui->buttonPause->show();
            ui->labelFirstTimer->setText(FindNameOfFirstTimer());
        }
    }
    else
    {
        _alarms[_index]->On();
        _amountOfActiveAlarms++;
        ui->labelActiveAlarms->setText(QString::number(_amountOfActiveAlarms));
        ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->labelDaysLeft->setText(QString::number(_alarms[_index]->GetLeftDays()) + " days");
        ui->buttonContinue->hide();
        ui->buttonPause->show();
    }
}

/*!
 * \brief on_buttonPause_clicked
 *
 * This slot pauses selected timer or alarm.
 * Time will be paused, but can be continued.
 */
void MainWindow::on_buttonPause_clicked()
{
    if (_index == -1)
        return;
    if (_isTimer)
    {
        if (_timers[_index]->Pause())
        {
            _amountOfActiveTimers--;
            ui->labelActiveTimers->setText(QString::number(_amountOfActiveTimers));
            ui->buttonPause->hide();
            ui->buttonContinue->show();
            ui->labelFirstTimer->setText(FindNameOfFirstTimer());
        }
    }
    else
    {
        _amountOfActiveAlarms--;
        _alarms[_index]->Off();
        ui->labelActiveAlarms->setText(QString::number(_amountOfActiveAlarms));
        ui->labelTimeLeft->setText(_alarms[_index]->GetLeftTime().toString("hh:mm:ss"));
        ui->labelDaysLeft->setText(QString::number(_alarms[_index]->GetLeftDays()) + " days");
        ui->buttonContinue->show();
        ui->buttonPause->hide();
    }
}

/*!
 * \brief on_buttonPause_clicked
 *
 * This slot pauses selected timer or alarm.
 * Time will be paused, but can be continued.
 */
QString MainWindow::FindNameOfFirstTimer()
{
    Timer* minTimer = nullptr;
    auto minTime = QTime(23, 59, 59);
    for (auto* timer : _timers)
    {
        if (timer->GetIsActive() && timer->GetLeftTime() < minTime)
        {
            minTime = timer->GetLeftTime();
            minTimer = timer;
        }
    }
    if (minTimer)
    {
        return minTimer->GetName();
    }
    return "";
}

/*!
 * \brief on_checkBox_toggled
 *
 * This slot enables or disables Do Not Disturb.
 *
 * \param checked If checked true, else false.
 */
void MainWindow::on_checkBox_toggled(bool checked)
{
    if (!checked)
    {
        ui->timeDndFrom->setEnabled(false);
        ui->timeDndTo->setEnabled(false);
        ui->labelFrom->setEnabled(false);
        ui->labelTo->setEnabled(false);
        _timeDndFrom.setHMS(0, 0, 1);
        _timeDndTo.setHMS(0, 0, 0);
    }
    else
    {
        ui->timeDndFrom->setEnabled(true);
        ui->timeDndTo->setEnabled(true);
        ui->labelFrom->setEnabled(true);
        ui->labelTo->setEnabled(true);
        _timeDndFrom = ui->timeDndFrom->time();
        _timeDndTo = ui->timeDndTo->time();
    }
}

/*!
 * \brief on_timeDndFrom_userTimeChanged
 *
 * This slot sets time, from which
 * Do Not Disturb mode starts.
 *
 * \param time Time from which
 * Do Not Disturb mode starts.
 */
void MainWindow::on_timeDndFrom_userTimeChanged(const QTime &time)
{
    _timeDndFrom = time;
}

/*!
 * \brief on_timeDndTo_userTimeChanged
 *
 * This slot sets time, when
 * Do Not Disturb mode ends.
 *
 * \param time Time, when
 * Do Not Disturb mode ends.
 */
void MainWindow::on_timeDndTo_userTimeChanged(const QTime &time)
{
    _timeDndTo = time;
}
