#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtGui>
#include <QtQuick3D/qquick3d.h>

#include <QQuickItem>
#include <QVector3D>
#include <QQmlContext>
#include <iostream>
#include "view.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat::setDefaultFormat(QQuick3D::idealSurfaceFormat());

    QQmlApplicationEngine engine;

    View* myView = new View();
    engine.rootContext()->setContextProperty("myView", myView);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    //test pourposes



    //test ends

    return app.exec();
}
