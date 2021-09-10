#-------------------------------------------------
#
# Project created by QtCreator 2019-06-04T11:46:43
#
#-------------------------------------------------

QT       += core gui
QT       += widgets xml

TEMPLATE = lib

include (../../config.pro)

DEFINES += PROTOCOL_INFO_LIBRARY

#in
SOURCES += protocol_info.cpp

HEADERS += protocol_info.h\
        protocol_info_global.h

#--- Protocol ---
INCLUDEPATH += ../Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#out
TARGET = $$qtLibraryTarget(Protocol_Info)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/protocol_info_ru.ts\
               translations/protocol_info_en.ts

RESOURCES += \
    resource_proinfo.qrc
