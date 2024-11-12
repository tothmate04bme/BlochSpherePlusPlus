#include "quantumbackend.h"

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

int calculate_rotate_around_x(QuantumState qs){
    double theta = 2 * std::acos(std::abs(qs.a));

    // Compute phi
    double phi = std::arg(qs.b) - std::arg(qs.a);

    // Convert to Cartesian coordinates
    //double x = std::sin(theta) * std::cos(phi);
    //qDebug() << "phi:" << phi;

    //return deg_to_rad(phi);
    return deg_to_rad(theta);
}

int calculate_rotate_around_y(QuantumState qs){
    double theta = 2 * std::acos(std::abs(qs.a));

    // Compute phi
    double phi = std::arg(qs.b) - std::arg(qs.a);

    double y = std::sin(theta) * std::sin(phi);

    //return deg_to_rad(theta);
    return 0;
}

int calculate_rotate_around_z(QuantumState qs){
    double theta = 2 * std::acos(std::abs(qs.a));

    // Compute phi
    double phi = std::arg(qs.b) - std::arg(qs.a);


    // Convert to Cartesian coordinates
    double z = std::cos(theta);

    return deg_to_rad(phi);
}
