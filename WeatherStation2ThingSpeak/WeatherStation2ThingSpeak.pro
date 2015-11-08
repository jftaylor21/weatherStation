QT += core network serialport
QT -= gui

TARGET = WeatherStation2ThingSpeak
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

include (../external/thingspeak-qt/exported/thingspeak-qt.pri)

HEADERS *= Weather.hpp \
           WeatherReader.hpp \
           WeatherStation.hpp \
           WeatherWriter.hpp

SOURCES *= main.cpp \
           Weather.cpp \
           WeatherReader.cpp \
           WeatherStation.cpp \
           WeatherWriter.cpp

