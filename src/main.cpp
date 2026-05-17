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

    QtWebEngineQuick::initialize();
    QGuiApplication app(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("A minimalistic browser for web applications");
    parser.addHelpOption();
    parser.addOption({{"W", "width"}, "Force window width", "width"});
    parser.addOption({{"H", "height"}, "Force window height", "height"});
    parser.addPositionalArgument("url", "URL to open");
    parser.process(app);

    QStringList args = parser.positionalArguments();
    if (args.isEmpty())
        parser.showHelp(1);

    QUrl url(args.first());
    int forceWidth = parser.value("width").toInt();
    int forceHeight = parser.value("height").toInt();
    Browser b(url.toString(), forceWidth, forceHeight);

    QQmlApplicationEngine engine;
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