#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T16:52:33
#
#-------------------------------------------------

QT       += core gui
QT       += widgets xml
QT       += network


TEMPLATE = lib

include (../../config.pro)

DEFINES += SETTINGS_PAGE_LIBRARY

#in
SOURCES += settings_page.cpp \
           edit_ip.cpp

HEADERS += settings_page.h\
        settings_page_global.h \
        edit_ip.h

INCLUDEPATH += ../../Device/Device_page

#--- Protocol_List ---
INCLUDEPATH += ../../Protocol/Protocol_List
PROTOCOL_LIST = Protocol_List
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIST}

#--- Protocol ---
INCLUDEPATH += ../../Protocol/Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#out
TARGET = $$qtLibraryTarget(settings_lib)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/settings_page_ru.ts\
               translations/settings_page_en.ts
RESOURCES += \
    resource_settings.qrc
