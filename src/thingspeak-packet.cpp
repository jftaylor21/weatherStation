#include "thingspeak-qt/thingspeak-packet.hpp"

const int ThingSpeakPacket::UNINITIALIZED_NUMBER(INT_MAX);

ThingSpeakPacket::ThingSpeakPacket()
  : latitude(UNINITIALIZED_NUMBER),
    longitude(UNINITIALIZED_NUMBER),
    elevation(UNINITIALIZED_NUMBER)
{
}

QUrlQuery ThingSpeakPacket::getQUrlQuery(const QString &apiKey) const
{
  QUrlQuery ret;
  ret.addQueryItem("api_key", apiKey);

  if (!field1.isEmpty())
  {
    ret.addQueryItem("field1", field1);
  }
  if (!field2.isEmpty())
  {
    ret.addQueryItem("field2", field2);
  }
  if (!field3.isEmpty())
  {
    ret.addQueryItem("field3", field3);
  }
  if (!field4.isEmpty())
  {
    ret.addQueryItem("field4", field4);
  }
  if (!field5.isEmpty())
  {
    ret.addQueryItem("field5", field5);
  }
  if (!field6.isEmpty())
  {
    ret.addQueryItem("field6", field6);
  }
  if (!field7.isEmpty())
  {
    ret.addQueryItem("field7", field7);
  }
  if (!field8.isEmpty())
  {
    ret.addQueryItem("field8", field8);
  }
  if (latitude != UNINITIALIZED_NUMBER)
  {
    ret.addQueryItem("lat", QString::number(latitude));
  }
  if (longitude != UNINITIALIZED_NUMBER)
  {
    ret.addQueryItem("long", QString::number(longitude));
  }
  if (elevation != UNINITIALIZED_NUMBER)
  {
    ret.addQueryItem("elevation", QString::number(elevation));
  }
  if (!status.isEmpty())
  {
    ret.addQueryItem("status", status);
  }
  if (!twitter.isEmpty())
  {
    ret.addQueryItem("twitter", twitter);
  }
  if (!tweet.isEmpty())
  {
    ret.addQueryItem("tweet", tweet);
  }
  if (created_at.isValid())
  {
    ret.addQueryItem("created_at", created_at.toString(Qt::ISODate));
  }
  return ret;
}
