#include "Weather.hpp"
#include "WeatherWriter.hpp"

#include "thingspeak-qt/thingspeak.hpp"
#include "thingspeak-qt/thingspeak-packet.hpp"

#include <QDebug>

WeatherWriter::WeatherWriter(const QString &apiKey)
  :fThingSpeak(new ThingSpeak(apiKey))
{
  fThingSpeak->setPostLimit(30);
}

WeatherWriter::~WeatherWriter()
{
}

void WeatherWriter::write(const Weather &data)
{
  ThingSpeakPacket p;
  p.field1 = QString::number(data.temperature);
  p.field2 = QString::number(data.pressure);
  p.field3 = QString::number(data.humidity);
  qDebug() << "T " << p.field1;
  qDebug() << "P " << p.field2;
  qDebug() << "H " << p.field3;
  fThingSpeak->post(p);
}
