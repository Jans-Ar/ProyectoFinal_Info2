QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bloque.cpp \
    enemy.cpp \
    galleta.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    nivel2.cpp \
    pendulosimple.cpp \
    proyectil.cpp \
    saludables.cpp \
    score.cpp \
    tiempo.cpp \
    trampolin.cpp

HEADERS += \
    bloque.h \
    enemy.h \
    galleta.h \
    jugador.h \
    mainwindow.h \
    menu.h \
    nivel2.h \
    pendulosimple.h \
    proyectil.h \
    saludables.h \
    score.h \
    tiempo.h \
    trampolin.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    nivel2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sprites.qrc

DISTFILES +=
