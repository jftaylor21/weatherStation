#ifndef THINGSPEAK_HPP
#define THINGSPEAK_HPP

#include "thingspeak-qt_global.hpp"

#include <QString>

class ThingSpeakPacket;

/**
 * Communicates with ThingSpeak.
 * See https://thingspeak.com/
 */
class THINGSPEAKQTSHARED_EXPORT ThingSpeak
{
public:
  /**
   * Constructor for ThingSpeak.
   *
   * \param apiKey API Key for writing data to ThingSpeak channel.
   */
  ThingSpeak(const QString& apiKey);

  /**
   * Writes data to ThingSpeak channel.
   *
   * \param update Data to write to ThingSpeak channel.
   * \param timeoutMS Timeout for sending data in milliseconds.
   *
   * \return true if successful, false if timeout
   */
  bool post(const ThingSpeakPacket& update, int timeoutMS=1000);

private:
  const QString fAPIKey;
};

#endif // THINGSPEAK_HPP
