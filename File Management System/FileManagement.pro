QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets #version of QT greater than 4

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    actualmainwindow.cpp \
    displaytree.cpp \
    file.cpp \
    filesystem.cpp \
    folder.cpp \
    main.cpp \
    mainwindow.cpp \
    window2.cpp \
    window3.cpp

HEADERS += \
    actualmainwindow.h \
    displaytree.h \
    file.h \
    filesystem.h \
    folder.h \
    mainwindow.h \
    window2.h \
    window3.h

FORMS += \
    actualmainwindow.ui \
    displaytree.ui \
    mainwindow.ui \
    window2.ui \
    window3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc \
    Resource.qrc
