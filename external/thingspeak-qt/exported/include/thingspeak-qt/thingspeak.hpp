#ifndef THINGSPEAK_HPP
#define THINGSPEAK_HPP

#include "thingspeak-qt_global.hpp"

#include <QString>
#include <QTime>

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
   * Prevents posting data to ThingSpeak too frequently.
   * According to https://thingspeak.com/docs/channels, the maximum frequency
   * for posting data is once every 15 seconds.
   * The post limit is 0 (disabled) by default.
   *
   * \param seconds The minimum number of seconds between posting data to
   * ThingSpeak. Attempts to post more frequently will drop data. A post limit
   * of 0 disables post limiting.
   */
  void setPostLimit(unsigned int seconds);
  
  /**
   * Returns the current post limit in seconds.
   * See setPostLimit for more details about how post limit is defined.
   *
   * \return post limit in seconds
   */
  unsigned int getPostLimit() const;

  /**
   * Writes data to ThingSpeak channel.
   *
   * \param update Data to write to ThingSpeak channel.
   * \param timeoutMS Timeout for sending data in milliseconds.
   *
   * \return true if successful, 
   * false if timeout or dropped data due to post limit
   */
  bool post(const ThingSpeakPacket& update, int timeoutMS=1000);

private:
  const QString fAPIKey;
  unsigned int fPostLimit;
  QTime fPostLimitTime;
};

#endif // THINGSPEAK_HPP
