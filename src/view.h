#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QQmlEngine>

class View :public QObject
{
    Q_OBJECT
public:
    View();

public slots: // slots are public methods available in QML
    void doSomething(const QString &text);
};

#endif // VIEW_H
