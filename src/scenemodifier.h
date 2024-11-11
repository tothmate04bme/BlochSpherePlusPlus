// Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef SCENEMODIFIER_H
#define SCENEMODIFIER_H

#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QConeMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QPhongAlphaMaterial>

class SceneModifier : public QObject
{
    Q_OBJECT

public:
    explicit SceneModifier(Qt3DCore::QEntity *rootEntity);
    ~SceneModifier();
    void pXGate();
    void pYGate();
    void pZGate();
    void hGate();

    float a = 4.0f;              //Scale
    Qt3DCore::QTransform *qubitVecTransform;
    Qt3DCore::QTransform *qubitConeTransform;
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_sphereEntity;
    Qt3DCore::QEntity *m_xAxisEntity;
    Qt3DCore::QEntity *m_yAxisEntity;
    Qt3DCore::QEntity *m_zAxisEntity;
    Qt3DCore::QEntity *m_qubitVecEntity;
    Qt3DCore::QEntity *m_qubitConeEntity;
};

#endif // SCENEMODIFIER_H

