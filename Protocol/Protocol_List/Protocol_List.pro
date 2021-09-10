#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T18:28:56
#
#-------------------------------------------------
QT       += core gui
QT       += widgets
QT       += qml
QT       += xml

TEMPLATE = lib

include (../../config.pro)

DEFINES += PROTOCOL_LIST_LIBRARY

#in
SOURCES += protocol_list.cpp

HEADERS += protocol_list.h\
        protocol_list_global.h

#out
TARGET = $$qtLibraryTarget(Protocol_List)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/protocol_list_ru.ts\
               translations/protocol_list_en.ts

RESOURCES += \
    resource_prolist.qrc
