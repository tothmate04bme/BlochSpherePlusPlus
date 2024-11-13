// Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "scenemodifier.h"
#include <Qt3DRender/QGeometryRenderer>
#include <QtCore/QDebug>
#include <Qt3DExtras/QPhongAlphaMaterial>
#include <Qt3DRender/QPointLight>

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity)
{
    // Shape data
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(40);
    sphereMesh->setSlices(40);
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

    // Transform
    Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform();
    sphereTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DCore::QTransform *xAxisTransform = new Qt3DCore::QTransform();
    xAxisTransform->setRotationZ(90);
    xAxisTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DCore::QTransform *yAxisTransform = new Qt3DCore::QTransform();
    yAxisTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DCore::QTransform *zAxisTransform = new Qt3DCore::QTransform();
    zAxisTransform->setRotationX(90);
    zAxisTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));


    //Material
    Qt3DExtras::QPhongAlphaMaterial *sphereMaterial = new Qt3DExtras::QPhongAlphaMaterial();
    sphereMaterial->setAmbient(QColor(255, 255, 255));
    sphereMaterial->setAlpha(0.8f);

    Qt3DExtras::QPhongMaterial *xAxisMaterial = new Qt3DExtras::QPhongMaterial();
    xAxisMaterial->setAmbient(QColor(255, 0, 0, 255));

    Qt3DExtras::QPhongMaterial *yAxisMaterial = new Qt3DExtras::QPhongMaterial();
    yAxisMaterial->setAmbient(QColor(0, 255, 0, 255));

    Qt3DExtras::QPhongMaterial *zAxisMaterial = new Qt3DExtras::QPhongMaterial();
    zAxisMaterial->setAmbient(QColor(0, 0, 255, 255));


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

    //amplitude

    Qt3DExtras::QCylinderMesh *qubitVecMesh = new Qt3DExtras::QCylinderMesh();
    qubitVecMesh->setRings(20);
    qubitVecMesh->setSlices(20);
    qubitVecMesh->setRadius(0.05f);
    qubitVecMesh->setLength(a);

    Qt3DExtras::QPhongMaterial *qubitVecMaterial = new Qt3DExtras::QPhongMaterial();
    qubitVecMaterial->setAmbient(QColor(0, 0, 0, 0));

    qubitVecTransform = new Qt3DCore::QTransform();
    qubitVecTransform->setRotationX(90);
    qubitVecTransform->setTranslation(QVector3D(0.0f, 0.0f, a / 2));

    m_qubitVecEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_qubitVecEntity->addComponent(qubitVecMesh);
    m_qubitVecEntity->addComponent(qubitVecMaterial);
    m_qubitVecEntity->addComponent(qubitVecTransform);

    // Ambient light
    auto *ambientLight = new Qt3DRender::QPointLight(rootEntity);
    ambientLight->setColor("white");
    ambientLight->setIntensity(1.0f);
    ambientLight->setEnabled(true);

    rootEntity->addComponent(ambientLight);

}

SceneModifier::~SceneModifier()
{
}


//! [4]

