#ifndef TIMERBELLDIALOG_H
#define TIMERBELLDIALOG_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class BellDialog;
}

class BellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BellDialog(QWidget *parent = nullptr);
    ~BellDialog();

    void AddName(QString name);

    void AddInfo(QString info);

    void AddSound(QString path);

private slots:
    void on_okayButton_clicked();

private:
    Ui::BellDialog *ui;
    QMediaPlayer* _mp;
};

#endif // TIMERBELLDIALOG_H
