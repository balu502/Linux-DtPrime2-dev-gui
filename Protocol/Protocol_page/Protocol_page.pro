#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T16:52:33
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += network quickwidgets
QT       += xml


TEMPLATE = lib

include (../../config.pro)

DEFINES += PROTOCOL_PAGE_LIBRARY

#in
SOURCES += protocol_page.cpp

HEADERS += protocol_page.h\
        protocol_page_global.h


INCLUDEPATH += ../../Device/Device_page
INCLUDEPATH += ../../Main_RT

#--- QWT ---
QWT_LOCATION = /home/dnadev/qwt-6.1.4
INCLUDEPATH += $${QWT_LOCATION}/include

#--- Protocol ---
INCLUDEPATH += ../Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#--- Protocol_List ---
INCLUDEPATH += ../Protocol_List
PROTOCOL_LIST = Protocol_List
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIST}

#--- Protocol_Info ---
INCLUDEPATH += ../Protocol_Info
PROTOCOL_INFO = Protocol_Info
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_INFO}

#--- Protocol_Program ---
INCLUDEPATH += ../Protocol_Program
PROTOCOL_PROGRAM = Protocol_Program
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_PROGRAM}

#--- Protocol_Samples ---
INCLUDEPATH += ../Protocol_Samples
PROTOCOL_SAMPLES = Protocol_Samples
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_SAMPLES}


#out
TARGET = $$qtLibraryTarget(protocol_lib)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/protocol_page_ru.ts\
               translations/protocol_page_en.ts

RESOURCES += \
    resource_pro.qrc



