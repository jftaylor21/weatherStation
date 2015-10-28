#include "thingspeak-qt/thingspeak.hpp"
#include "thingspeak-qt/thingspeak-packet.hpp"

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QSettings settings("example.ini", QSettings::IniFormat);
  QString api_key(settings.value("api_key").toString());

  ThingSpeakPacket tsp;
  tsp.field1 = "44.5";
  tsp.field2 = "80.95";
  tsp.field3 = "999.3";
  ThingSpeak ts(api_key);
  ts.post(tsp);

  return 0;
}
