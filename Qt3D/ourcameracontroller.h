#ifndef OURCAMERACONTROLLER_H
#define OURCAMERACONTROLLER_H

#include <QOrbitCameraController>

class OurCameraController: private Qt3DExtras::QOrbitCameraController
{
public:
    OurCameraController(Qt3DCore::QEntity* entity){
        init
    }
};

#endif // OURCAMERACONTROLLER_H
