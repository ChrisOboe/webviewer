#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineQuick>
#include <QCommandLineParser>
#include <QUrl>
#include "browser.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setOrganizationName("webviewer");
    QCoreApplication::setApplicationName("webviewer");
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

    if (argc != 2 ) {
        return 1;
    };

    QUrl url(argv[1]);

    QtWebEngineQuick::initialize();
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Browser b(url.toString());
    engine.rootContext()->setContextProperty("browser", &b);
    const QUrl qmlUrl(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [qmlUrl](QObject *obj, const QUrl &objUrl) {
        if (!obj && qmlUrl == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(qmlUrl);
    return app.exec();
}