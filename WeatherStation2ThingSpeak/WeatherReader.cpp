#include "Weather.hpp"
#include "WeatherReader.hpp"

WeatherReader::WeatherReader(const QString &serialPort)
  : fSerialPort(serialPort)
{
  fSerialPort.setBaudRate(QSerialPort::Baud9600);
  fSerialPort.setDataBits(QSerialPort::Data8);
  fSerialPort.setParity(QSerialPort::NoParity);
  fSerialPort.setStopBits(QSerialPort::OneStop);
  fSerialPort.setFlowControl(QSerialPort::NoFlowControl);
}

WeatherReader::~WeatherReader()
{
  fSerialPort.close();
}

bool WeatherReader::open()
{
  bool ret = false;
  if (fSerialPort.isOpen())
  {
    ret = true;
  }
  else
  {
    ret = fSerialPort.open(QIODevice::ReadOnly);
  }

  return ret;
}

namespace
{
  QString readLine(QSerialPort& serialPort, QByteArray& buf, unsigned int timeoutMS)
  {
    QString ret;
    if (serialPort.isOpen())
    {
      while(!buf.contains('\n'))
      {
        if (serialPort.waitForReadyRead(timeoutMS))
        {
          buf += serialPort.readAll();
        }
      }
      int newlinePos = buf.indexOf('\n');
      ret = buf.left(newlinePos-1);
      buf = buf.right(buf.size()-newlinePos-1);
    }
    return ret;
  }
}

std::unique_ptr<Weather> WeatherReader::read(unsigned int timeoutMS)
{
  std::unique_ptr<Weather> ret = nullptr;

  // We need to synchronize with beginning weather packet.
  // We should be able to sync in 4 tries, since there are
  // 4 newlines in a packet.
  const int NUM_TRIES(4);
  bool packetSynchronized(false);
  for(int i(0); i < NUM_TRIES || !packetSynchronized; ++i)
  {
    QString line(readLine(fSerialPort, fBuffer, timeoutMS));
    packetSynchronized = line.compare("begin") == 0;
  }

  if (packetSynchronized)
  {
    QString temperature = readLine(fSerialPort, fBuffer, timeoutMS);
    QString humidity = readLine(fSerialPort, fBuffer, timeoutMS);
    QString pressure = readLine(fSerialPort, fBuffer, timeoutMS);
    ret = std::unique_ptr<Weather>(new Weather(temperature.toDouble(), humidity.toDouble(), pressure.toDouble()));
  }

  return ret;
}
