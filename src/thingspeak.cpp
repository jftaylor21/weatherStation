#include "thingspeak-qt/thingspeak.hpp"
#include "thingspeak-qt/thingspeak-packet.hpp"

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

ThingSpeak::ThingSpeak(const QString& apiKey)
  : fAPIKey(apiKey)
{
}

namespace
{
  const QUrl THINGSPEAK_URL("http://api.thingspeak.com/update");
}

bool ThingSpeak::post(const ThingSpeakPacket &update, int timeoutMS)
{
  QUrlQuery params(update.getQUrlQuery(fAPIKey));

  QNetworkRequest request(THINGSPEAK_URL);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

  QNetworkAccessManager networkManager;
  QNetworkReply* reply = networkManager.post(request, params.toString(QUrl::FullyEncoded).toUtf8());

  QTime time;
  time.start();
  while(!reply->isFinished() || time.elapsed() > timeoutMS)
  {
    qApp->processEvents();
  }
  return reply->isFinished();
}
