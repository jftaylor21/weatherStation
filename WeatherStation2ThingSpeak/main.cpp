#include "WeatherStation.hpp"

#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QSettings settings("weatherstation.ini", QSettings::IniFormat);
  QString api_key(settings.value("api_key").toString());
  QString serial_port(settings.value("serial_port").toString());
  if (serial_port.isEmpty() || api_key.isEmpty())
  {
    qFatal("Error: Failed to read weatherstation.ini");
  }

  WeatherStation w(serial_port, api_key);
  w.run();

  return a.exec();
}

