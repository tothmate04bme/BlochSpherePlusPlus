#include "quantumbackend.h"
//#include "scenemodifier.h"
#include <QLabel>

QuantumGate::QuantumGate(std::complex<double> _00_, std::complex<double> _01_,
            std::complex<double> _10_, std::complex<double> _11_)
{
    _00 = _00_;
    _01 = _01_;
    _10 = _10_;
    _11 = _11_;
}

QuantumState& QuantumState::operator*=(const QuantumGate& gate){
    std::complex<double> new_a = gate._00 * a + gate._01 * b;
    std::complex<double> new_b = gate._10 * a + gate._11 * b;
    a = new_a;
    b = new_b;

    return *this;
}

double deg_to_rad(double rad){
    double deg = rad * (180.0/3.141592653589793238463);

    //qDebug() << "Deg:" << deg;

    return deg;
}

double calculate_rotate_around_x(QuantumState qs){
    double theta = 2 * std::acos(std::abs(qs.a));

    // Compute phi
    double phi = std::arg(qs.b) - std::arg(qs.a);

    // Convert to Cartesian coordinates
    //double x = std::sin(theta) * std::cos(phi);
    //qDebug() << "phi:" << phi;

    //return deg_to_rad(phi);
    return deg_to_rad(theta);
}

double calculate_rotate_around_y(QuantumState qs){
    double theta = 2 * std::acos(std::abs(qs.a));

    // Compute phi
    double phi = std::arg(qs.b) - std::arg(qs.a);

    double y = std::sin(theta) * std::sin(phi);

    //return deg_to_rad(theta);
    return 0;
}

double calculate_rotate_around_z(QuantumState qs){
    double theta = 2 * std::acos(std::abs(qs.a));

    // Compute phi
    double phi = std::arg(qs.b) - std::arg(qs.a);


    // Convert to Cartesian coordinates
    double z = std::cos(theta);

    return deg_to_rad(phi);
}

void rotate_amplitude(SceneModifier *modifier, int x, int y, int z){

    QMatrix4x4 translate;
    translate.translate(0.0f, 2.0f, 0.0f);

    auto matX = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), x, QVector3D(1,0,0));

    auto matY = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), y, QVector3D(0,1,0));

    auto matZ = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), z, QVector3D(0,0,1));

    auto initializer = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), 90, QVector3D(1,0,0));

    auto initializerZ = modifier->qubitVecTransform->rotateAround(
        QVector3D(0,0,0), 90, QVector3D(0,0,1));

    auto matXYZ = initializerZ*(initializer*(matZ*(matY * (matX * translate))));

    modifier->qubitVecTransform->setMatrix(matXYZ);
}

void refresh_state_sign(QLabel* label, const QuantumState* qs, double phi, double theta){
    std::string text = "";
    text = text + "Amplitude:\n" +
           "Alpha: " + std::to_string(qs->a.real()) + " + " + std::to_string(qs->a.imag()) + "i\n" +
           "Beta: " + std::to_string(qs->b.real()) + " + " + std::to_string(qs->b.imag()) + "i\n" +
           "\nPhi: " + std::to_string(phi) +
           "\nTheta: " + std::to_string(theta);

    label->setText(QString(text.c_str()));
}

void apply_gate(SceneModifier* modifier, QLabel* statesign, QuantumState* quantumbit, QuantumGate* gate){

    (*quantumbit) *= (*gate);

    double x = calculate_rotate_around_x(*quantumbit);
    double y = calculate_rotate_around_y(*quantumbit);
    double z = calculate_rotate_around_z(*quantumbit);

    rotate_amplitude(modifier, x, z, y);

    refresh_state_sign(statesign, quantumbit, x, z);
}
