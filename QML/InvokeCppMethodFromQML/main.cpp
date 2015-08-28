#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <greeting.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Greeting greeting;

    auto rootContext=engine.rootContext();
    rootContext->setContextProperty("greetingClass",&greeting);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

