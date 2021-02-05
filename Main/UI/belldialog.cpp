#include "belldialog.h"
#include "ui_belldialog.h"

/*!
 * \brief BellDialog
 *
 * Default constructor.
 *
 * \param parent Parent object.
 */
BellDialog::BellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BellDialog)
{
    _mp = new QMediaPlayer();
    ui->setupUi(this);
}

/*!
 * \brief ~BellDialog
 *
 * Default destructor. Destruct the object.
 */
BellDialog::~BellDialog()
{
    delete ui;
}

/*!
 * \brief AddName
 *
 * Displays passed name on the interface.
 *
 * \param name Name of timer or alarm, which will be displayed on the interface.
 */
void BellDialog::AddName(QString name)
{
    ui->nameLabel->setText(name);
}

/*!
 * \brief AddInfo
 *
 * Displays passed information on the interface.
 *
 * \param info information of timer or alarm, which will be displayed on the interface.
 */
void BellDialog::AddInfo(QString info)
{
    ui->infoLabel->setText(info);
}

/*!
 * \brief AddSound
 *
 * Sets the ringtone path.
 *
 * \param path Ringtone path.
 */
void BellDialog::AddSound(QString path)
{
    _mp->setMedia(QUrl::fromLocalFile(path));
    _mp->setVolume(50);
    _mp->play();
}

/*!
 * \brief on_okayButton_clicked
 *
 * Closes the window.
 */
void BellDialog::on_okayButton_clicked()
{
    _mp->stop();
    this->hide();
}
