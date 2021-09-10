#-------------------------------------------------
#
# Project created by QtCreator 2019-06-04T19:01:06
#
#-------------------------------------------------

QT       += core gui
QT       += widgets xml


TEMPLATE = lib
include (../../config.pro)

DEFINES += PROTOCOL_PROGRAM_LIBRARY


#in
SOURCES += protocol_program.cpp

HEADERS += protocol_program.h\
        protocol_program_global.h

#--- Protocol ---
INCLUDEPATH += ../Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#--- QWT ---
QWT_LOCATION = /home/dnadev/qwt-6.1.4
INCLUDEPATH += $${QWT_LOCATION}/include
QWT = qwt
VER__MAJ = 6
CONFIG(debug, debug|release) {QWT = $${QWT}$${SUFFIX}}
LIBS += -L$${QWT_LOCATION}/lib -l$${QWT}

#out
TARGET = $$qtLibraryTarget(Protocol_Program)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/protocol_program_ru.ts\
               translations/protocol_program_en.ts

RESOURCES += \
    resource_program.qrc
