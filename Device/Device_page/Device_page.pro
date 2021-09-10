#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T16:52:33
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += network
QT       += xml


TEMPLATE = lib

include (../../config.pro)

DEFINES += DEVICE_PAGE_LIBRARY

#in
SOURCES += device_page.cpp

HEADERS += device_page.h\
        device_page_global.h \
        request_dev.h \
        device_param.h \
    coeff_struct.h

INCLUDEPATH += ../../Main_RT

#--- QWT ---
QWT_LOCATION = /home/dnadev/qwt-6.1.4
INCLUDEPATH += $${QWT_LOCATION}/include

#--- Graph ---
INCLUDEPATH += ../Device_Temperature
INCLUDEPATH += ../Device_Fluor
GRAPH_TEMPERATURE = GraphTemperature_lib
GRAPH_FLUOR = GraphFluor_lib
CONFIG(debug, debug|release) {GRAPH_TEMPERATURE = $${GRAPH_TEMPERATURE}$${SUFFIX}}
LIBS += -L../../$${CURRENT_BUILD} -l$${GRAPH_TEMPERATURE}
CONFIG(debug, debug|release) {GRAPH_FLUOR = $${GRAPH_FLUOR}$${SUFFIX}}
LIBS += -L../../$${CURRENT_BUILD} -l$${GRAPH_FLUOR}

#--- Device Info ---
INCLUDEPATH += ../Device_Info
DEVICE_INFO = Device_Info
CONFIG(debug, debug|release) {DEVICE_INFO = $${DEVICE_INFO}$${SUFFIX}}
LIBS += -L../../$${CURRENT_BUILD} -l$${DEVICE_INFO}

#--- Protocol ---
INCLUDEPATH += ../../Protocol/Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}


#out
TARGET = $$qtLibraryTarget(device_lib)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target
export(INSTALLS)

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/device_page_ru.ts\
               translations/device_page_en.ts


RESOURCES += \
    resource_dev.qrc

