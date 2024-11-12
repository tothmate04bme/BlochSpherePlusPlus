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
                std::complex<double> _10_, std::complex<double> _11_);
};

struct QuantumState {
public:
    std::complex<double> a; // |0> coefficient
    std::complex<double> b; // |1> coefficient

    QuantumState(std::complex<double> a_, std::complex<double> b_) :
        a(a_), b(b_){}

    QuantumState& operator*=(const QuantumGate& gate);
};

double deg_to_rad(double rad);

int calculate_rotate_around_x(QuantumState qs);

int calculate_rotate_around_y(QuantumState qs);

int calculate_rotate_around_z(QuantumState qs);

#endif // QUANTUMBACKEND_H
