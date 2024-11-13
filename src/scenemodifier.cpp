// Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "scenemodifier.h"
#include <Qt3DRender/QGeometryRenderer>
#include <QtCore/QDebug>
#include <Qt3DExtras/QPhongAlphaMaterial>
#include <Qt3DRender/QPointLight>
#include <Qt3DExtras/QText2DEntity>

#include <Qt3DExtras/QExtrudedTextMesh>
#include <QFont>

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
    xAxisMesh->setLength(2 * a - (a / 32.0));

    Qt3DExtras::QCylinderMesh *yAxisMesh = new Qt3DExtras::QCylinderMesh();
    yAxisMesh->setRings(20);
    yAxisMesh->setSlices(20);
    yAxisMesh->setRadius(0.03f);
    yAxisMesh->setLength(2 * a - (a / 32.0));

    Qt3DExtras::QCylinderMesh *zAxisMesh = new Qt3DExtras::QCylinderMesh();
    zAxisMesh->setRings(20);
    zAxisMesh->setSlices(20);
    zAxisMesh->setRadius(0.03f);
    zAxisMesh->setLength(2 * a - (a / 32.0));

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
    qubitVecMesh->setLength(a * (15.0 / 16.0));

    Qt3DExtras::QPhongMaterial *qubitVecMaterial = new Qt3DExtras::QPhongMaterial();
    qubitVecMaterial->setAmbient(QColor(0, 0, 0, 0));

    qubitVecTransform = new Qt3DCore::QTransform();
    qubitVecTransform->setRotationX(90);
    qubitVecTransform->setTranslation(QVector3D(0.0f, 0.0f, a / 2.0));

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

    //cone

    Qt3DExtras::QConeMesh *qubitConeMesh = new Qt3DExtras::QConeMesh();
    qubitConeMesh->setBottomRadius(0.1f);
    qubitConeMesh->setLength(a / 8);

    qubitConeTransform = new Qt3DCore::QTransform();
    qubitConeTransform->setRotationX(90);
    qubitConeTransform->setTranslation(QVector3D(0.0f, 0.0f, a));

    Qt3DExtras::QPhongMaterial *qubitConeMaterial = new Qt3DExtras::QPhongMaterial();
    qubitConeMaterial->setAmbient(QColor(0, 0, 0, 0));

    m_qubitConeEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_qubitConeEntity->addComponent(qubitConeMesh);
    m_qubitConeEntity->addComponent(qubitConeMaterial);
    m_qubitConeEntity->addComponent(qubitConeTransform);

    //axis cones

        //x
    xAxisConeTransform = new Qt3DCore::QTransform();
    xAxisConeTransform->setRotationZ(-90);
    xAxisConeTransform->setTranslation(QVector3D(a * (31.0 / 32.0), 0.0f, 0.0f));

    auto* xAxisConeMaterial = new Qt3DExtras::QPhongMaterial();
    xAxisConeMaterial->setAmbient(QColor(255, 0, 0, 0));

    m_xAxisCone = new Qt3DCore::QEntity(m_rootEntity);
    m_xAxisCone->addComponent(qubitConeMesh);
    m_xAxisCone->addComponent(xAxisConeMaterial);
    m_xAxisCone->addComponent(xAxisConeTransform);

        //y
    yAxisConeTransform = new Qt3DCore::QTransform();
    //yAxisConeTransform->setRotationZ(0);
    yAxisConeTransform->setTranslation(QVector3D(0.0f, a * (31.0 / 32.0), 0.0f));

    auto* yAxisConeMaterial = new Qt3DExtras::QPhongMaterial();
    yAxisConeMaterial->setAmbient(QColor(0, 255, 0, 0));

    m_yAxisCone = new Qt3DCore::QEntity(m_rootEntity);
    m_yAxisCone->addComponent(qubitConeMesh);
    m_yAxisCone->addComponent(yAxisConeMaterial);
    m_yAxisCone->addComponent(yAxisConeTransform);

        //z
    zAxisConeTransform = new Qt3DCore::QTransform();
    zAxisConeTransform->setRotationX(90);
    zAxisConeTransform->setTranslation(QVector3D(0.0f, 0.0f, a * (31.0 / 32.0)));

    auto* zAxisConeMaterial = new Qt3DExtras::QPhongMaterial();
    zAxisConeMaterial->setAmbient(QColor(0, 0, 255, 0));

    m_zAxisCone = new Qt3DCore::QEntity(m_rootEntity);
    m_zAxisCone->addComponent(qubitConeMesh);
    m_zAxisCone->addComponent(zAxisConeMaterial);
    m_zAxisCone->addComponent(zAxisConeTransform);

    //axis signs
        //x
    auto* xtextmesh = new Qt3DExtras::QExtrudedTextMesh();
    xtextmesh->setText("X");
    xtextmesh->setFont(QFont("Arial", 24));
    xtextmesh->setDepth(0.25f);  // Controls the extrusion depth of the text

    auto* xtexttransform = new Qt3DCore::QTransform();
    xtexttransform->setRotationX(90);
    xtexttransform->setTranslation(QVector3D(a + 0.2, 0.0f, -0.25f));
    xtexttransform->setScale(0.5);

    auto* xtext = new Qt3DCore::QEntity(rootEntity);
    xtext->addComponent(xtextmesh);
    xtext->addComponent(xAxisMaterial);
    xtext->addComponent(xtexttransform);

        //y
    auto* ytextmesh = new Qt3DExtras::QExtrudedTextMesh();
    ytextmesh->setText("Y");
    ytextmesh->setFont(QFont("Arial", 24));
    ytextmesh->setDepth(0.25f);  // Controls the extrusion depth of the text

    auto* ytexttransform = new Qt3DCore::QTransform();
    ytexttransform->setRotationZ(90);
    ytexttransform->setRotationY(90);
    ytexttransform->setTranslation(QVector3D(0.0f, a + 0.2f, -0.25f));
    ytexttransform->setScale(0.5);

    auto* ytext = new Qt3DCore::QEntity(rootEntity);
    ytext->addComponent(ytextmesh);
    ytext->addComponent(yAxisMaterial);
    ytext->addComponent(ytexttransform);

        //z

    auto* ztextmesh = new Qt3DExtras::QExtrudedTextMesh();
    ztextmesh->setText("Z");
    ztextmesh->setFont(QFont("Arial", 24));
    ztextmesh->setDepth(0.25f);  // Controls the extrusion depth of the text

    auto* ztexttransform = new Qt3DCore::QTransform();
    ztexttransform->setRotationZ(90);
    ztexttransform->setRotationY(90);
    ztexttransform->setRotationX(-90);
    ztexttransform->setTranslation(QVector3D(0.2f, -0.1f, a + 0.2f));
    ztexttransform->setScale(0.5);

    auto* ztext = new Qt3DCore::QEntity(rootEntity);
    ztext->addComponent(ztextmesh);
    ztext->addComponent(zAxisMaterial);
    ztext->addComponent(ztexttransform);
}

SceneModifier::~SceneModifier()
{
}


//! [4]

