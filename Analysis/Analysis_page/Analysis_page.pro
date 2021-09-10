#-------------------------------------------------
#
# Project created by QtCreator 2019-06-26T18:55:04
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += network quickwidgets
QT       += xml


TEMPLATE = lib
include (../../config.pro)
DEFINES += ANALYSIS_PAGE_LIBRARY

#in
SOURCES += analysis_page.cpp

HEADERS += analysis_page.h\
        analysis_page_global.h

INCLUDEPATH += ../../Main_RT

#--- QWT ---
QWT_LOCATION = /home/dnadev/qwt-6.1.4
INCLUDEPATH += $${QWT_LOCATION}/include

#--- Protocol ---
INCLUDEPATH += ../../Protocol/Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#--- Protocol_List ---
INCLUDEPATH += ../../Protocol/Protocol_List
PROTOCOL_LIST = Protocol_List
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIST}

#--- Protocol_Info ---
INCLUDEPATH += ../../Protocol/Protocol_Info
PROTOCOL_INFO = Protocol_Info
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_INFO}

#--- Protocol_Program ---
INCLUDEPATH += ../../Protocol/Protocol_Program
PROTOCOL_PROGRAM = Protocol_Program
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_PROGRAM}

#--- Protocol_Samples ---
INCLUDEPATH += ../../Protocol/Protocol_Samples
PROTOCOL_SAMPLES = Protocol_Samples
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_SAMPLES}

#--- Graph ---
INCLUDEPATH += ../../Device/Device_Fluor
GRAPH_FLUOR = GraphFluor_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${GRAPH_FLUOR}

#--- GSL ---
LIBS += -lgsl -lgslcblas
#LIBS += -l gsl -l gslcblas

#out
TARGET = $$qtLibraryTarget(analysis_lib)
target.files = TARGET
#target.path = /home/root/balu/$${CURRENT_BUILD}
target.path = /home/user/prog/dev_gui
INSTALLS += target

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/analysis_page_ru.ts\
               translations/analysis_page_en.ts

RESOURCES += \
    resource_analysis.qrc
