#ifndef WEATHER_HPP
#define WEATHER_HPP

/**
 * Class that holds weather data.
 */
class Weather
{
public:
  /**
   * Constructor for Weather class.
   *
   * \param temperature Temperature in Fahrenheit
   * \param humidity Relative humidity in %
   * \param pressure Pressure in inches mercury
   */
  Weather(double temperature, double humidity, double pressure);
  ~Weather();

  /**
   * Temperature in Fahrenheit
   */
  const double temperature;

  /**
   * Relative humidity in %
   */
  const double humidity;

  /**
   * Pressure in inches mercury
   */
  const double pressure;
};

#endif
