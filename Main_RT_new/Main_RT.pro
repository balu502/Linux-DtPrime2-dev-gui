#-------------------------------------------------
#
# Project created by QtCreator 2019-04-08T17:36:02
#
#-------------------------------------------------

QT       += core gui
QT       += qml quick script quickwidgets
QT       += network
QT       += xml
#QT       += websockets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include (../config.pro)

VERSION = 9.1.0.3
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

TARGET = Main_RT
target.files = TARGET
target.path = /home/root/balu/$${CURRENT_BUILD}
INSTALLS += target
export(INSTALLS)

TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS

#IN
SOURCES += main.cpp\
        main_rt.cpp \
        worker_wait.cpp \
        sp.cpp

HEADERS  += main_rt.h \
            worker_wait.h \
            sp.h

OTHER_FILES += qml/web_5jul.qml \
#               qml/web.qml

#--- QWT ---
include (/home/dnadev/qwt-6.1.4/features/qwt.prf )
QWT_LOCATION = /home/dnadev/qwt-6.1.4
INCLUDEPATH += $${QWT_LOCATION}/include

#--- Device_Page ---
INCLUDEPATH += ../Device/Device_page
INCLUDEPATH += ../Device/Device_Temperature
INCLUDEPATH += ../Device/Device_Fluor
INCLUDEPATH += ../Device/Device_Info

DEVICE_PAGE = device_lib
LIBS += -L../$${CURRENT_BUILD} -l$${DEVICE_PAGE}

#--- Protocol_Page ---
INCLUDEPATH += ../Protocol/Protocol_page
PROTOCOL_PAGE = protocol_lib
LIBS += -L../$${CURRENT_BUILD} -l$${PROTOCOL_PAGE}

#--- Protocol_List ---
INCLUDEPATH += ../Protocol/Protocol_List
PROTOCOL_LIST = Protocol_List
LIBS += -L../$${CURRENT_BUILD} -l$${PROTOCOL_LIST}

#--- Protocol ---
INCLUDEPATH += ../Protocol/Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#--- Protocol_Info ---
INCLUDEPATH += ../Protocol/Protocol_Info
PROTOCOL_INFO = Protocol_Info
LIBS += -L../$${CURRENT_BUILD} -l$${PROTOCOL_INFO}

#--- Protocol_Program ---
INCLUDEPATH += ../Protocol/Protocol_Program
PROTOCOL_PROGRAM = Protocol_Program
LIBS += -L../$${CURRENT_BUILD} -l$${PROTOCOL_PROGRAM}

#--- Protocol_Samples ---
INCLUDEPATH += ../Protocol/Protocol_Samples
PROTOCOL_SAMPLES = Protocol_Samples
LIBS += -L../$${CURRENT_BUILD} -l$${PROTOCOL_SAMPLES}

#--- Graph_Temperature ---
GRAPH_TEMPERATURE = GraphTemperature_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${GRAPH_TEMPERATURE}

#--- Graph_Fluor ---
GRAPH_FLUOR = GraphFluor_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${GRAPH_FLUOR}

#--- Device Info ---
DEVICE_INFO = Device_Info
LIBS += -L../../$${CURRENT_BUILD} -l$${DEVICE_INFO}

#--- Analysis_Page ---
INCLUDEPATH += ../Analysis/Analysis_page
ANALYSIS_PAGE = analysis_lib
LIBS += -L../$${CURRENT_BUILD} -l$${ANALYSIS_PAGE}

#--- Settigs_Page ---
INCLUDEPATH += ../Settings/Settings_page
SETTINGS_PAGE = settings_lib
LIBS += -L../$${CURRENT_BUILD} -l$${SETTINGS_PAGE}

#OUT
DESTDIR = ../$${CURRENT_BUILD}
TRANSLATIONS = translations/ru.ts

RESOURCES += \
    resource.qrc

#DISTFILES += \
#    qml/web_5jul.qml


