TEMPLATE = subdirs

SUBDIRS = external/thingspeak-qt \
          WeatherStation2ThingSpeak

OTHER_FILES *= weatherstation-example.ini

WeatherStation2ThingSpeak.depends = external/thingspeak-qt
