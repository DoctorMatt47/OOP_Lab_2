#ifndef TIMERBELLDIALOG_H
#define TIMERBELLDIALOG_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class BellDialog;
}

/*!
 * \brief The BellDialog class
 *
 * Represents dialog box, which will be displayed when
 * timer or alarm rings.
 */
class BellDialog : public QDialog
{
    Q_OBJECT
private:
    /*! Window. */
    Ui::BellDialog *ui;

    /*! Media player, plays selected ringtone. */
    QMediaPlayer* _mp;

public:
    /*!
     * \brief BellDialog
     *
     * Default constructor.
     *
     * \param parent Parent object.
     */
    explicit BellDialog(QWidget *parent = nullptr);

    /*!
     * \brief ~BellDialog
     *
     * Default destructor. Destruct the object.
     */
    ~BellDialog();

    /*!
     * \brief AddName
     *
     * Displays passed name on the interface.
     *
     * \param name Name of timer or alarm, which will be displayed on the interface.
     */
    void AddName(QString name);

    /*!
     * \brief AddInfo
     *
     * Displays passed information on the interface.
     *
     * \param info information of timer or alarm, which will be displayed on the interface.
     */
    void AddInfo(QString info);

    /*!
     * \brief AddSound
     *
     * Sets the ringtone path.
     *
     * \param path Ringtone path.
     */
    void AddSound(QString path);

private slots:
    /*!
     * \brief on_okayButton_clicked
     *
     * Closes the window.
     */
    void on_okayButton_clicked();
};

#endif // TIMERBELLDIALOG_H
