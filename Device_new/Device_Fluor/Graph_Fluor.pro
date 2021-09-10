#-------------------------------------------------
#
# Project created by QtCreator 
#
#-------------------------------------------------

QT       += widgets
QT       += xml

TEMPLATE = lib

include (../../config.pro)

DEFINES += GRAPH_FLUOR_LIBRARY

#in
SOURCES += graph_fluor.cpp

HEADERS += graph_fluor.h \
           Graph_Fluor_global.h

#--- QWT ---
QWT_LOCATION = /home/dnadev/qwt-6.1.4
INCLUDEPATH += $${QWT_LOCATION}/include
QWT = qwt
VER__MAJ = 6
CONFIG(debug, debug|release) {QWT = $${QWT}$${SUFFIX}}
LIBS += -L$${QWT_LOCATION}/lib -l$${QWT}

#--- Protocol ---
INCLUDEPATH += ../../Protocol/Protocol_Lib
PROTOCOL_LIB = Protocol_lib
LIBS += -L../../$${CURRENT_BUILD} -l$${PROTOCOL_LIB}

#out
TARGET = $$qtLibraryTarget(GraphFluor_lib)
target.files = TARGET
target.path = /home/root/balu/$${CURRENT_BUILD}
INSTALLS += target
export(INSTALLS)

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/graph_fluor_ru.ts

RESOURCES += resource_graph_fluor.qrc
