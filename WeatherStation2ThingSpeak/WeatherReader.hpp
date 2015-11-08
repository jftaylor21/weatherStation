#ifndef WEATHERREADER_HPP
#define WEATHERREADER_HPP

#include <QSerialPort>
#include <QString>

#include <memory>

class Weather;

/**
 * Reads weather data from serial port.
 *
 * The expected format for the serial data is:
 *
 *  "begin"
 *  temperature string
 *  humidity string
 *  pressure string
 */
class WeatherReader
{
public:
  /**
   * Constructor for WeatherReader.
   *
   * /param serialPort Name of serial port. Example: COM3
   */
  WeatherReader(const QString& serialPort);
  ~WeatherReader();

  /**
   * Opens connection to serial port.
   *
   * /return true if open successful, false otherwise
   */
  bool open();

  /**
   * Reads weather data from serial port.
   * /param timeoutMS Timeout in milliseconds for reading each line from the
   * serial port.
   *
   * /return Weather data if successful. Returns nullptr if unsuccessful.
   */
  std::unique_ptr<Weather> read(unsigned int timeoutMS);

private:
  QSerialPort fSerialPort;
  QByteArray fBuffer;
};

#endif
