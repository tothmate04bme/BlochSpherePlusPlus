#ifndef QUANTUMBACKEND_H
#define QUANTUMBACKEND_H

#include <cmath>
#include <complex>

struct QuantumGate{
    std::complex<double> elements[4];

    QuantumGate(std::complex<double> _00, std::complex<double> _01,
                std::complex<double> _10, std::complex<double> _11){
        elements[0] = _00;
        elements[1] = _01;
        elements[2] = _10;
        elements[3] = _11;
    }
};

struct QuantumState {
public:
    std::complex<double> a; // |0> coefficient
    std::complex<double> b; // |1> coefficient

    QuantumState(std::complex<double> a_, std::complex<double> b_) :
        a(a_), b(b_){}

    QuantumState& operator*=(const QuantumGate& gate){
        a = gate.elements[0] * a + gate.elements[1] * b;
        b = gate.elements[2] * a + gate.elements[3] * b;
        return *this;
    }
};


QuantumState operator*(const QuantumState& state,const QuantumGate& gate){
    std::complex<double> new_a = gate.elements[0] * state.a + gate.elements[1] * state.b;
    std::complex<double> new_b = gate.elements[2] * state.a + gate.elements[3] * state.b;
    return QuantumState(new_a, new_b);
}

int calculate_rotate_around_x(QuantumState qs){
    return 0;
}

int calculate_rotate_around_y(QuantumState qs){
    constexpr double RAD_TO_DEG = 180.0 / M_PI;

    double magA = std::abs(qs.a);

    // Calculate theta (rotation around Y-axis) in degrees
    double theta = 2 * std::acos(magA) * RAD_TO_DEG;

    return theta;
}

int calculate_rotate_around_z(QuantumState qs){
    constexpr double RAD_TO_DEG = 180.0 / M_PI;

    //double magA = std::abs(qs.a);

    // Calculate phi (rotation around Z-axis) in degrees
    double phi = (std::arg(qs.b) - std::arg(qs.a)) * RAD_TO_DEG;

    return phi;
}


#endif // QUANTUMBACKEND_H
