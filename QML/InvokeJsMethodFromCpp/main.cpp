#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <message.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Message msg;

    auto rootContext=engine.rootContext();
    rootContext->setContextProperty("messageClass",&msg);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto rootObject=engine.rootObjects().first();
    msg.setRootObject(rootObject);

    return app.exec();
}

