// Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "scenemodifier.h"

#include <QGuiApplication>

#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcameralens.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtGui/QScreen>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DExtras/qforwardrenderer.h>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qorbitcameracontroller.h>

#include <QLineEdit>
#include <string>

#include <complex>
#include "quantumbackend.h"

void rotate_amplitude(SceneModifier *modifier, int x, int y, int z){
    qDebug() << x << " " << y << " " << z << "\n";

    QMatrix4x4 translate;
    translate.translate(0.0f, 2.0f, 0.0f);

    auto matX = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), x, QVector3D(1,0,0));

    auto matY = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), y, QVector3D(0,1,0));

    auto matZ = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), z, QVector3D(0,0,1));

    auto matXYZ = matZ*(matY * (matX * translate));

    modifier->qubitVecTransform->setMatrix(matXYZ);
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0)));
    QWidget *container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);

    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);

    widget->setWindowTitle(QStringLiteral("BlochSphere++"));

    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(10, 10, 10));
    QVector3D upVec = QVector3D(0,0,1);
    cameraEntity->setUpVector(upVec);
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);

    camController->setCamera(cameraEntity);
    camController->setUpVector(upVec);


    // Scenemodifier
    SceneModifier *modifier = new SceneModifier(rootEntity);

    // Set root object of the scene
    view->setRootEntity(rootEntity);

    // Create control widgets
    /*QCommandLinkButton *info = new QCommandLinkButton();
    info->setText(QStringLiteral("Vezérlőpult"));
    info->setDescription(QString::fromLatin1("Ez lesz majd egyszer az UI."));
    info->setIconSize(QSize(0,0));*/

    QLineEdit *Xrot = new QLineEdit;
    Xrot->setPlaceholderText("X");

    QLineEdit *Yrot = new QLineEdit;
    Yrot->setPlaceholderText("Y");

    QLineEdit *Zrot = new QLineEdit;
    Zrot->setPlaceholderText("Z");

    /*QCheckBox *sphereCB = new QCheckBox(widget);
    sphereCB->setChecked(true);
    sphereCB->setText(QStringLiteral("Sphere"));*/

    //vLayout->addWidget(info);
    //vLayout->addWidget(sphereCB);

    //sphereCB->setChecked(true);
    //modifier->pXGate();
    //modifier->pXGate();

    QPushButton *XGate = new QPushButton();
    XGate->setText(QStringLiteral("X Gate"));

    QPushButton *YGate = new QPushButton();
    YGate->setText(QStringLiteral("Y Gate"));

    QPushButton *ZGate = new QPushButton();
    ZGate->setText(QStringLiteral("Z Gate"));

    QuantumState quantumbit(std::complex<double>(1.0, 0.0), std::complex<double>(0.0,0.0));

    QuantumGate X_gate(
        std::complex<double>(0.0,0.0),
        std::complex<double>(1.0,0.0),
        std::complex<double>(1.0,0.0),
        std::complex<double>(0.0,0.0)
    );

    QuantumGate Y_gate(
        std::complex<double>(0.0,0.0),
        std::complex<double>(0.0,-1.0),
        std::complex<double>(0.0,1.0),
        std::complex<double>(0.0,0.0)
    );

    QuantumGate Z_gate(
        std::complex<double>(1.0,0.0),
        std::complex<double>(0.0,0.0),
        std::complex<double>(0.0,0.0),
        std::complex<double>(-1.0,0.0)
    );

    QObject::connect(XGate,&QPushButton::clicked, [=]() {

        /*int x_rotation = 0;
        int y_rotation = 0;
        int z_rotation = 0;

        try{
            x_rotation = std::stoi(Xrot->text().toUtf8().toStdString());
            y_rotation = std::stoi(Yrot->text().toUtf8().toStdString());
            z_rotation = std::stoi(Zrot->text().toUtf8().toStdString());
        }
        catch(std::invalid_argument arg){
            //std::cout << "invalid arguments!\n";
            qDebug() << "Invalid args";
        }

        rotate_amplitude(modifier, x_rotation, y_rotation, z_rotation);*/

        qDebug() << "X pushed";

        //std::complex<double> d1(0.0, 0.0);
        //std::complex<double> d2(0.0,1.0);

        //quantumbit = quantumbit * X_gate;
        quantumbit *= X_gate;

        int x = calculate_rotate_around_x(quantumbit);
        int y = calculate_rotate_around_y(quantumbit);
        int z = calculate_rotate_around_z(quantumbit);

        rotate_amplitude(modifier, x, y, z);
    });

    QObject::connect(YGate,&QPushButton::clicked, [=]() {
        qDebug() << "Y pushed";

        quantumbit = quantumbit * Y_gate;

        int x = calculate_rotate_around_x(quantumbit);
        int y = calculate_rotate_around_y(quantumbit);
        int z = calculate_rotate_around_z(quantumbit);

        rotate_amplitude(modifier, x, y, z);
    });

    QObject::connect(ZGate,&QPushButton::clicked, [=]() {
        qDebug() << "Z pushed";

        quantumbit = quantumbit * Z_gate;

        int x = calculate_rotate_around_x(quantumbit);
        int y = calculate_rotate_around_y(quantumbit);
        int z = calculate_rotate_around_z(quantumbit);

        rotate_amplitude(modifier, x, y, z);
    });

    vLayout->addWidget(XGate);
    vLayout->addWidget(YGate);
    vLayout->addWidget(ZGate);
    //vLayout->addWidget(Xrot);
    //vLayout->addWidget(Yrot);
    //vLayout->addWidget(Zrot);

    // Show window
    widget->show();
    widget->resize(800, 600);

    return app.exec();
}
