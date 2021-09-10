#-------------------------------------------------
#
# Project created by QtCreator 2019-06-06T11:23:42
#
#-------------------------------------------------

QT       += core gui
QT       += widgets xml

TEMPLATE = lib
include (../../config.pro)
DEFINES += PROTOCOL_SAMPLES_LIBRARY

#in
SOURCES += protocol_samples.cpp

HEADERS += protocol_samples.h\
        protocol_samples_global.h

#--- Protocol ---
INCLUDEPATH += ../Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#out
TARGET = $$qtLibraryTarget(Protocol_Samples)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/protocol_sample_ru.ts\
               translations/protocol_sample_en.ts

RESOURCES += \
    resource_samples.qrc
