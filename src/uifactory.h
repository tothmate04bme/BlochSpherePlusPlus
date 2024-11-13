#include "scenemodifier.h"
#include "quantumbackend.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

QGridLayout* generate_UI(SceneModifier *modifier, QuantumState *quantumbit);

void refresh_state_sign(QLabel* label, const QuantumState* qs, double phi, double theta);
