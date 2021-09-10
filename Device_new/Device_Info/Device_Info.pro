#-------------------------------------------------
#
# Project created by QtCreator 2019-06-13T10:55:54
#
#-------------------------------------------------

QT       += core gui
QT       += widgets xml

TEMPLATE = lib

include (../../config.pro)

DEFINES += DEVICE_INFO_LIBRARY

#in
SOURCES +=  device_info.cpp

HEADERS +=  device_info.h\
            device_info_global.h

INCLUDEPATH += ../Device_page
INCLUDEPATH += ../../Protocol/Protocol_Lib

#out
TARGET = $$qtLibraryTarget(Device_Info)
target.files = TARGET
target.path = /home/root/balu/$${CURRENT_BUILD}
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/device_info_ru.ts

RESOURCES += \
    resource_devinfo.qrc
