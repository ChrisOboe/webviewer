#include "browser.h"
#include <QUrl>
#include <QDebug>

Browser::Browser(QString url, QObject* parent) : QObject(parent) {
  m_url = url;

  QString fqdn = QUrl(m_url).host();
  QStringList domainParts = fqdn.split('.');

  m_session = QString("%1.%2").arg(domainParts[domainParts.count()-2]).arg(domainParts[domainParts.count()-1]);
}

QString Browser::url(){
  qDebug() << "url:" << m_url;
  return m_url;
}

QString Browser::session() {
  qDebug() << "session:" << m_session;
  return m_session;
}
