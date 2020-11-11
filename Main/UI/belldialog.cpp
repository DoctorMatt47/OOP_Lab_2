#include "belldialog.h"
#include "ui_belldialog.h"

BellDialog::BellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BellDialog)
{
    _mp = new QMediaPlayer();
    ui->setupUi(this);
}

BellDialog::~BellDialog()
{
    delete ui;
}

void BellDialog::AddName(QString name)
{
    ui->nameLabel->setText(name);
}

void BellDialog::AddInfo(QString info)
{
    ui->infoLabel->setText(info);
}

void BellDialog::AddSound(QString path)
{
    //_mp->setMedia(QUrl::fromLocalFile("E:\\Music\\Монеточка - Раскраски для взрослых (2018) [rap-game.ru]\\02. Каждый раз.mp3"));
    _mp->setMedia(QUrl::fromLocalFile(path));
    _mp->setVolume(50);
    _mp->play();
}

void BellDialog::on_okayButton_clicked()
{
    _mp->stop();
    this->hide();
}
