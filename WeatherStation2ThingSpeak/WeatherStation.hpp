#ifndef WEATHERSTATION_HPP
#define WEATHERSTATION_HPP

#include <QString>

#include <memory>

class WeatherReader;
class WeatherWriter;

/**
 * Reads weather from serial port and sends it to ThingSpeak.
 */
class WeatherStation
{
public:
  /**
   * Constructor for WeatherStation
   *
   * /param serialPort Name of serial port to read weather data. Example: COM3
   *
   * /param apiKey API Key associated with ThingSpeak channel.
   */
  WeatherStation(const QString& serialPort, const QString& apiKey);
  ~WeatherStation();

  /**
   * Begin reading serial data and writing to ThingSpeak channel.
   */
  void run();

private:
  std::unique_ptr<WeatherReader> fWeatherReader;
  std::unique_ptr<WeatherWriter> fWeatherWriter;
};

#endif
