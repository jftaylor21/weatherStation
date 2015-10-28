QT       += network
QT       -= gui

DESTDIR = $$_PRO_FILE_PWD_/exported/lib

TARGET = thingspeak-qt
TEMPLATE = lib

DEFINES += THINGSPEAKQT_LIBRARY

INCLUDEPATH *= exported/include

SOURCES += src/thingspeak.cpp \
           src/thingspeak-packet.cpp

HEADERS += exported/include/thingspeak-qt/thingspeak.hpp \
           exported/include/thingspeak-qt/thingspeak-packet.hpp \
           exported/include/thingspeak-qt/thingspeak-qt_global.hpp
