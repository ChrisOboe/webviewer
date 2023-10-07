#ifndef browser_h_INCLUDED
#define browser_h_INCLUDED

#include <QObject>
#include <QString>

class Browser : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString url READ url NOTIFY urlChanged)
    Q_PROPERTY(QString session READ session NOTIFY sessionChanged)

    public:
        Browser(QString url, QObject *parent = nullptr);
        QString url();
        QString session();

    signals:
        void urlChanged(QString url);
        void sessionChanged(QString session);

    private:
        QString m_url;
        QString m_session;
};

#endif // browser_h_INCLUDED
