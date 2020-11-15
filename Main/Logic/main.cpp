#include "Main/UI/mainwindow.h"

#include <QApplication>

/*!
 * \brief main
 *
 * Application entry point.
 * Main function of program,
 * starts the application.
 *
 * \param argc Number of arguments.
 * \param argv Array of arguments.
 * \return Return 0 if program worked correctly.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
