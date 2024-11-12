#include "quantumbackend.h"
#include "scenemodifier.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

void rotate_amplitude(SceneModifier *modifier, int x, int y, int z);

QGridLayout* generate_UI(SceneModifier *modifier, QuantumState *quantumbit);

void refresh_state_sign(QLabel* label, const QuantumState* qs, double phi, double theta);
