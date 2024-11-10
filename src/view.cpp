#include "view.h"
#include <iostream>

View::View() {}

void View::doSomething(const QString& text){
    std::cout << text.toUtf8().toStdString() << '\n';
}
