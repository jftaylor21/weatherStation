#ifndef THINKSPEAK_PACKET_HPP
#define THINKSPEAK_PACKET_HPP

#include "thingspeak-qt_global.hpp"

#include <QDateTime>
#include <QString>
#include <QUrlQuery>

/**
 * Packet for communicating with ThingSpeak.
 *
 * See link below for more explanation on data structure:
 * https://thingspeak.com/docs/channels#update_feed
 */
struct THINGSPEAKQTSHARED_EXPORT ThingSpeakPacket
{
  static const int UNINITIALIZED_NUMBER;

  ThingSpeakPacket();

  /**
   * Get QUrlQuery that can be sent to ThingSpeak channel to write data.
   *
   * \param apiKey API Key for writing to ThingSpeak channel.
   *
   * \return QUrlQuery that can be sent to ThingSpeak channel.
   */
  QUrlQuery getQUrlQuery(const QString& apiKey) const;

  QString field1;
  QString field2;
  QString field3;
  QString field4;
  QString field5;
  QString field6;
  QString field7;
  QString field8;

  double latitude; // degrees
  double longitude; // degrees
  int elevation; // meters

  QString status; // status message

  QString twitter; // twitter username
  QString tweet; // twitter status update

  QDateTime created_at; // date this data was created
};

#endif
