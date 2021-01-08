QT       += core gui printsupport sql serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    conge.cpp \
    connection.cpp \
    consultation.cpp \
    dossiermedicale.cpp \
    employe.cpp \
    main.cpp \
    hygeia.cpp \
    medicament.cpp \
    patient.cpp \
    payement.cpp \
    poche.cpp \
    rdv.cpp

HEADERS += \
    arduino.h \
    conge.h \
    connection.h \
    consultation.h \
    dossiermedicale.h \
    employe.h \
    hygeia.h \
    medicament.h \
    patient.h \
    payement.h \
    poche.h \
    rdv.h

FORMS += \
    hygeia.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc


#windows icon and admin right
RC_ICONS = logo.ico

