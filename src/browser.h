#ifndef browser_h_INCLUDED
#define browser_h_INCLUDED

#include <QObject>
#include <QString>
#include <QSettings>
#include <QSize>

class Browser : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY urlChanged)
    Q_PROPERTY(QString session READ session NOTIFY sessionChanged)

    public:
        Browser(QString url, int forceWidth = 0, int forceHeight = 0, QObject *parent = nullptr);
        QString url();
        QString session();
        Q_INVOKABLE void saveWindowSize(int width, int height);
        Q_INVOKABLE QSize loadWindowSize();

    signals:
        void urlChanged(QString url);
        void sessionChanged(QString session);

    private:
        QString m_url;
        QString m_session;
        int m_forceWidth;
        int m_forceHeight;
        QSettings m_settings;
};

#endif // browser_h_INCLUDED
