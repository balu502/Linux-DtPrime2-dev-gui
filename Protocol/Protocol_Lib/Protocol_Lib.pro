#-------------------------------------------------
#
# Project created by QtCreator 2019-05-22T16:17:04
#
#-------------------------------------------------

QT       += widgets
QT       += xml


TEMPLATE = lib

include (../../config.pro)

DEFINES += PROTOCOL_LIB_LIBRARY

#in
SOURCES += protocol_lib.cpp

HEADERS += protocol_lib.h\
        protocol_lib_global.h

#out
TARGET = $$qtLibraryTarget(Protocol_lib)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target
export(INSTALLS)

DESTDIR = ../../$${CURRENT_BUILD}
