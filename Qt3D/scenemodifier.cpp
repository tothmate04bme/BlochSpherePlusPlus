// Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "scenemodifier.h"
#include <Qt3DRender/QGeometryRenderer>
#include <QtCore/QDebug>

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity)
{
    // Shape data
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(20);
    sphereMesh->setSlices(20);
    sphereMesh->setRadius(a);

    Qt3DExtras::QCylinderMesh *xAxisMesh = new Qt3DExtras::QCylinderMesh();
    xAxisMesh->setRings(20);
    xAxisMesh->setSlices(20);
    xAxisMesh->setRadius(0.03f);
    xAxisMesh->setLength(2 * a);

    Qt3DExtras::QCylinderMesh *yAxisMesh = new Qt3DExtras::QCylinderMesh();
    yAxisMesh->setRings(20);
    yAxisMesh->setSlices(20);
    yAxisMesh->setRadius(0.03f);
    yAxisMesh->setLength(2 * a);

    Qt3DExtras::QCylinderMesh *zAxisMesh = new Qt3DExtras::QCylinderMesh();
    zAxisMesh->setRings(20);
    zAxisMesh->setSlices(20);
    zAxisMesh->setRadius(0.03f);
    zAxisMesh->setLength(2 * a);

    Qt3DExtras::QCylinderMesh *qubitVecMesh = new Qt3DExtras::QCylinderMesh();
    qubitVecMesh->setRings(20);
    qubitVecMesh->setSlices(20);
    qubitVecMesh->setRadius(0.05f);
    qubitVecMesh->setLength(a);

    Qt3DExtras::QConeMesh *qubitConeMesh = new Qt3DExtras::QConeMesh();
    qubitConeMesh->setBottomRadius(0.1f);
    qubitConeMesh->setLength(a / 8);

    // Transform
    Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform();
    sphereTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DCore::QTransform *xAxisTransform = new Qt3DCore::QTransform();
    xAxisTransform->setRotationX(90);
    xAxisTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DCore::QTransform *yAxisTransform = new Qt3DCore::QTransform();
    yAxisTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DCore::QTransform *zAxisTransform = new Qt3DCore::QTransform();
    zAxisTransform->setRotationZ(90);
    zAxisTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    qubitVecTransform = new Qt3DCore::QTransform();
    qubitVecTransform->setTranslation(QVector3D(0.0f, a / 2, 0.0f));

    qubitConeTransform = new Qt3DCore::QTransform();
    qubitConeTransform->setTranslation(QVector3D(0.0f, a, 0.0f));


    //Material
    Qt3DExtras::QPhongAlphaMaterial *sphereMaterial = new Qt3DExtras::QPhongAlphaMaterial();
    sphereMaterial->setAmbient(QColor(255, 255, 255));
    sphereMaterial->setAlpha(1.0f);

    Qt3DExtras::QPhongMaterial *xAxisMaterial = new Qt3DExtras::QPhongMaterial();
    xAxisMaterial->setAmbient(QColor(255, 0, 0, 255));

    Qt3DExtras::QPhongMaterial *yAxisMaterial = new Qt3DExtras::QPhongMaterial();
    yAxisMaterial->setAmbient(QColor(0, 255, 0, 255));

    Qt3DExtras::QPhongMaterial *zAxisMaterial = new Qt3DExtras::QPhongMaterial();
    zAxisMaterial->setAmbient(QColor(0, 0, 255, 255));

    Qt3DExtras::QPhongMaterial *qubitVecMaterial = new Qt3DExtras::QPhongMaterial();
    qubitVecMaterial->setAmbient(QColor(0, 0, 0, 0));

    Qt3DExtras::QPhongMaterial *qubitConeMaterial = new Qt3DExtras::QPhongMaterial();
    qubitConeMaterial->setAmbient(QColor(0, 0, 0, 0));


    // Entity
    m_sphereEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_sphereEntity->addComponent(sphereMesh);
    m_sphereEntity->addComponent(sphereMaterial);
    m_sphereEntity->addComponent(sphereTransform);

    m_xAxisEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_xAxisEntity->addComponent(xAxisMesh);
    m_xAxisEntity->addComponent(xAxisMaterial);
    m_xAxisEntity->addComponent(xAxisTransform);

    m_yAxisEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_yAxisEntity->addComponent(yAxisMesh);
    m_yAxisEntity->addComponent(yAxisMaterial);
    m_yAxisEntity->addComponent(yAxisTransform);

    m_zAxisEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_zAxisEntity->addComponent(zAxisMesh);
    m_zAxisEntity->addComponent(zAxisMaterial);
    m_zAxisEntity->addComponent(zAxisTransform);

    m_qubitVecEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_qubitVecEntity->addComponent(qubitVecMesh);
    m_qubitVecEntity->addComponent(qubitVecMaterial);
    m_qubitVecEntity->addComponent(qubitVecTransform);

    m_qubitConeEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_qubitConeEntity->addComponent(qubitConeMesh);
    m_qubitConeEntity->addComponent(qubitConeMaterial);
    m_qubitConeEntity->addComponent(qubitConeTransform);
}

SceneModifier::~SceneModifier()
{
}

void SceneModifier::pXGate(){
    /*Qt3DCore::QTransform *xGateVecTransform = new Qt3DCore::QTransform();
    qubitVTransform.setY(qubitVTransform.y() * (-1));
    xGateVecTransform->setTranslation(qubitVTransform);
    m_qubitVecEntity->addComponent(xGateVecTransform);

    Qt3DCore::QTransform *xGateConeTransform = new Qt3DCore::QTransform();
    xGateConeTransform->setRotationX(180);
    qubitCTransform.setY(qubitCTransform.y() * (-1));
    xGateConeTransform->setTranslation(qubitCTransform);
    m_qubitConeEntity->addComponent(xGateConeTransform);*/

    qubitVecTransform->setMatrix(qubitVecTransform->rotateAround(QVector3D(0,0,0),90,QVector3D(0,1,0)));
    m_qubitVecEntity->addComponent(qubitVecTransform);
    qubitConeTransform->setMatrix(qubitConeTransform->rotateAround(QVector3D(0,0,0),90,QVector3D(0,1,0)));
    m_qubitConeEntity->addComponent(qubitConeTransform);
}

void SceneModifier::pYGate(){
    /*Qt3DCore::QTransform *xGateVecTransform = new Qt3DCore::QTransform();
    xGateVecTransform->setTranslation(qubitVTransform);
    xGateVecTransform->rotateAround(QVector3D(0,0,0),180,QVector3D(1,0,0));
    m_qubitVecEntity->addComponent(xGateVecTransform);

    Qt3DCore::QTransform *xGateConeTransform = new Qt3DCore::QTransform();
    xGateConeTransform->setTranslation(qubitCTransform);
    xGateConeTransform->setRotationZ(180);
    xGateConeTransform->rotateAround(QVector3D(0,0,0),180,QVector3D(1,0,0));
    m_qubitConeEntity->addComponent(xGateConeTransform);*/
}

void SceneModifier::pZGate(){
    /*Qt3DCore::QTransform *xGateVecTransform = new Qt3DCore::QTransform();
    xGateVecTransform->setRotationY(180);
    //qubitVTransform.setY(qubitVTransform.y() * (-1));
    xGateVecTransform->setTranslation(qubitVTransform);
    m_qubitVecEntity->addComponent(xGateVecTransform);

    Qt3DCore::QTransform *xGateConeTransform = new Qt3DCore::QTransform();
    xGateConeTransform->setRotationY(180);
    //qubitCTransform.setY(qubitCTransform.y() * (-1));
    xGateConeTransform->setTranslation(qubitCTransform);
    m_qubitConeEntity->addComponent(xGateConeTransform);*/
}

void SceneModifier::hGate(){

}

//! [4]

