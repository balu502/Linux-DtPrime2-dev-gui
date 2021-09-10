#-------------------------------------------------
#
# Project created by QtCreator 
#
#-------------------------------------------------

QT       += widgets
QT       += xml

TEMPLATE = lib

include (../../config.pro)

DEFINES += GRAPH_TEMPERATURE_LIBRARY


#in
SOURCES += graph_temperature.cpp

HEADERS += graph_temperature.h\
        Graph_Temperature_global.h

#--- QWT ---
QWT_LOCATION = /home/dnadev/qwt-6.1.4
INCLUDEPATH += $${QWT_LOCATION}/include
QWT = qwt
VER__MAJ = 6
CONFIG(debug, debug|release) {QWT = $${QWT}$${SUFFIX}}
LIBS += -L$${QWT_LOCATION}/lib -l$${QWT}

#out
TARGET = $$qtLibraryTarget(GraphTemperature_lib)
target.files = TARGET
target.path = /home/root/balu/$${CURRENT_BUILD}
INSTALLS += target
export(INSTALLS)

DESTDIR = ../../$${CURRENT_BUILD}
TRANSLATIONS = translations/graph_temperature_ru.ts

RESOURCES += \
   resources_graph_temperature.qrc
