#ifndef WEATHERWRITER_HPP
#define WEATHERWRITER_HPP

#include <QString>

#include <memory>

class ThingSpeak;
class Weather;

/**
 * Writes weather data to ThingSpeak.
 */
class WeatherWriter
{
public:
  /**
   * Constructor for WeatherWriter.
   *
   * @param apiKey API Key associated with ThingSpeak channel.
   */
  WeatherWriter(const QString& apiKey);
  ~WeatherWriter();

  /**
   * Writes weather data to ThingSpeak channel. Will not write data to
   * ThingSpeak too frequently (max frequency = 1 message every 30 seconds)
   *
   * @param data Weather data to write to ThingSpeak.
   */
  void write(const Weather& data);

private:
  std::unique_ptr<ThingSpeak> fThingSpeak;
};

#endif
