#include "browser.h"
#include <QUrl>
#include <QDebug>
#include <QSettings>

Browser::Browser(QString url, QObject* parent) : QObject(parent), m_settings("webviewer", "webviewer") {
  m_url = url;

  QString fqdn = QUrl(m_url).host();
  QStringList domainParts = fqdn.split('.');

  if (domainParts.count() >= 2) {
      m_session = QString("%1.%2").arg(domainParts[domainParts.count()-2]).arg(domainParts[domainParts.count()-1]);
  } else {
      m_session = "default";
  }
  qDebug() << "Created browser with URL:" << m_url << "and session:" << m_session;
}

QString Browser::url(){
  qDebug() << "url:" << m_url;
  return m_url;
}

QString Browser::session() {
  qDebug() << "session:" << m_session;
  return m_session;
}

void Browser::saveWindowSize(int width, int height) {
    QString key = QString("windowSize/%1").arg(m_session);
    m_settings.setValue(key, QSize(width, height));
}

QSize Browser::loadWindowSize() {
    QString key = QString("windowSize/%1").arg(m_session);
    return m_settings.value(key, QSize(800, 600)).toSize();
}
