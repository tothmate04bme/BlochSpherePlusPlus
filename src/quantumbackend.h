#ifndef QUANTUMBACKEND_H
#define QUANTUMBACKEND_H

#include <cmath>
#include <complex>

#include <iostream>

struct QuantumGate{
    std::complex<double> _00;
    std::complex<double> _01;
    std::complex<double> _10;
    std::complex<double> _11;

    QuantumGate(std::complex<double> _00_, std::complex<double> _01_,
                std::complex<double> _10_, std::complex<double> _11_){
        _00 = _00_;
        _01 = _01_;
        _10 = _10_;
        _11 = _11_;
    }
};

struct QuantumState {
public:
    std::complex<double> a; // |0> coefficient
    std::complex<double> b; // |1> coefficient

    QuantumState(std::complex<double> a_, std::complex<double> b_) :
        a(a_), b(b_){}

    QuantumState& operator*=(const QuantumGate& gate){
        std::complex<double> new_a = gate._00 * a + gate._01 * b;
        std::complex<double> new_b = gate._10 * a + gate._11 * b;
        a = new_a;
        b = new_b;

        qDebug() << "operator*" << a.real() << a.imag() << b.real() << b.imag();

        //std::cout << a.real() << " " << a.imag() << '\n';
        //std::cout << b.real() << " " << b.imag() << "\n\n";
        return *this;
    }
};


/*QuantumState operator*(const QuantumState& state,const QuantumGate& gate){
    std::complex<double> new_a = gate.elements[0] * state.a + gate.elements[2] * state.b;
    std::complex<double> new_b = gate.elements[1] * state.a + gate.elements[3] * state.b;
    return QuantumState(new_a, new_b);
}*/

double deg_to_rad(double rad){
    double deg = rad * (180.0/3.141592653589793238463);

    qDebug() << "Deg:" << deg;

    return deg;
}

int calculate_rotate_around_x(QuantumState qs){
    double theta = 2 * std::acos(std::abs(qs.a));

    // Compute phi
    double phi = std::arg(qs.b) - std::arg(qs.a);

    // Convert to Cartesian coordinates
    //double x = std::sin(theta) * std::cos(phi);
    qDebug() << "phi:" << phi;

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


#endif // QUANTUMBACKEND_H
