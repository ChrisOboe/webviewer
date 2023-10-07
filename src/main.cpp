#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngine>
#include <QCommandLineParser>
#include <QUrl>
#include "browser.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setOrganizationName("webviewer");
    QCoreApplication::setApplicationName("webviewer");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

    if (argc != 2 ) {
        return 1;
    };

    QUrl url(argv[1]);

	QtWebEngine::initialize();
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Browser b(url.toString());
    engine.rootContext()->setContextProperty("browser", &b);
    engine.load(QUrl(QStringLiteral("qrc:main.qml")));
    return app.exec();
}
