#include "Weather.hpp"
#include "WeatherReader.hpp"
#include "WeatherStation.hpp"
#include "WeatherWriter.hpp"

#include <QDebug>
#include <QThread>

WeatherStation::WeatherStation(const QString &serialPort, const QString& apiKey)
  : fWeatherReader(new WeatherReader(serialPort)),
    fWeatherWriter(new WeatherWriter(apiKey))
{
  fWeatherReader->open();
}

WeatherStation::~WeatherStation()
{
}

void WeatherStation::run()
{
  const unsigned long sleepTime(500);
  const unsigned int dataReaderTimeout(500);
  while(true)
  {
    std::unique_ptr<Weather> data(fWeatherReader->read(dataReaderTimeout));
    if (data != nullptr)
    {
      fWeatherWriter->write(*data);
    }
    else
    {
      qDebug() << "Dropping empty packet";
    }
    QThread::msleep(sleepTime);
  }
}
