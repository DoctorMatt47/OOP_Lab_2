QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Alarm/UI/addalarmdialog.cpp \
    Alarm/Logic/alarm.cpp \
    Main/Logic/main.cpp \
    Main/UI/mainwindow.cpp \
    Timer/UI/addtimerdialog.cpp \
    Alarm/UI/addalarmdialog.cpp \
    Timer/UI/addtimerdialog.cpp \
    Main/Logic/main.cpp \
    Main/UI/mainwindow.cpp \
    Main/UI/belldialog.cpp \
    Timer/Logic/timer.cpp \
    Alarm/UI/addalarmdialog.cpp

HEADERS += \
    Alarm/UI/addalarmdialog.h \
    Alarm/Logic/alarm.h \
    Main/UI/mainwindow.h \
    Timer/UI/addtimerdialog.h \
    Alarm/UI/addalarmdialog.h \
    Alarm/UI/addtimerdialog.h \
    Main/UI/mainwindow.h \
    Main/UI/belldialog.h \
    Timer/Logic/timer.h \
    Alarm/UI/addalarmdialog.h

FORMS += \
    Main/UI/mainwindow.ui \
    Timer/UI/addtimerdialog.ui \
    Timer/UI/addtimerdialog.ui \
    Main/UI/mainwindow.ui \
    Main/UI/belldialog.ui \
    Alarm/UI/addalarmdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
