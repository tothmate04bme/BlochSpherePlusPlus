#include "uifactory.h"
#include <cstring>

QGridLayout* generate_UI(SceneModifier *modifier, QuantumState *quantumbit){

    QGridLayout *layout = new QGridLayout();

    layout->setAlignment(Qt::AlignTop);

    QLineEdit *Xrot = new QLineEdit;
    Xrot->setPlaceholderText("X");

    QLineEdit *Yrot = new QLineEdit;
    Yrot->setPlaceholderText("Y");

    QLineEdit *Zrot = new QLineEdit;
    Zrot->setPlaceholderText("Z");

    QLineEdit *m11 = new QLineEdit;
    m11->setPlaceholderText("m11");
    //m11->setText(QString("0"));

    QLineEdit *m12 = new QLineEdit;
    m12->setPlaceholderText("m12");
    //m12->setText(QString("0"));

    QLineEdit *m21 = new QLineEdit;
    m21->setPlaceholderText("m21");
    //m21->setText(QString("0"));

    QLineEdit *m22 = new QLineEdit;
    m22->setPlaceholderText("m22");
    //m22->setText(QString("0"));

    QLineEdit *m11_i = new QLineEdit;
    m11_i->setPlaceholderText("m11_i");
    //m11_i->setText(QString("0"));

    QLineEdit *m12_i = new QLineEdit;
    m12_i->setPlaceholderText("m12_i");
    //m12_i->setText(QString("0"));

    QLineEdit *m21_i = new QLineEdit;
    m21_i->setPlaceholderText("m21_i");
    //m21_i->setText(QString("0"));

    QLineEdit *m22_i = new QLineEdit;
    m22_i->setPlaceholderText("m22_i");
    //m22_i->setText(QString("0"));


    QPushButton *resetbutton = new QPushButton();
    resetbutton->setText(QStringLiteral("Reset to |0>"));

    QPushButton *Xrot_button = new QPushButton();
    Xrot_button->setText(QStringLiteral("Rotate around X"));

    QPushButton *Yrot_button = new QPushButton();
    Yrot_button->setText(QStringLiteral("Rotate around Y"));

    QPushButton *Zrot_button = new QPushButton();
    Zrot_button->setText(QStringLiteral("Rotate around Z"));

    QPushButton *XGate = new QPushButton();
    XGate->setText(QStringLiteral("X Gate"));

    QPushButton *YGate = new QPushButton();
    YGate->setText(QStringLiteral("Y Gate"));

    QPushButton *ZGate = new QPushButton();
    ZGate->setText(QStringLiteral("Z Gate"));

    QPushButton *HGate = new QPushButton();
    HGate->setText(QStringLiteral("H Gate"));

    QPushButton *SGate = new QPushButton();
    SGate->setText(QStringLiteral("S Gate"));

    QPushButton *SGate_adj = new QPushButton();
    SGate_adj->setText(QStringLiteral("S_adj Gate"));

    QPushButton *TGate = new QPushButton();
    TGate->setText(QStringLiteral("T Gate"));

    QPushButton *TGate_adj = new QPushButton();
    TGate_adj->setText(QStringLiteral("T_adj Gate"));

    QPushButton *Custom_gate = new QPushButton();
    Custom_gate->setText(QStringLiteral("Apply"));

    QLabel* statuslabel = new QLabel(QString("status"));
    statuslabel->setStyleSheet("border: 2px; padding: 5px;");

    QObject::connect(XGate,&QPushButton::clicked, [=]() {

        QuantumGate *X_gate = new QuantumGate(
            std::complex<double>(0.0,0.0),
            std::complex<double>(1.0,0.0),
            std::complex<double>(1.0,0.0),
            std::complex<double>(0.0,0.0)
            );

        apply_gate(modifier, statuslabel, quantumbit, X_gate);

        delete X_gate;
    });

    QObject::connect(YGate,&QPushButton::clicked, [=]() {

        QuantumGate *Y_gate = new QuantumGate(
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,-1.0),
            std::complex<double>(0.0,1.0),
            std::complex<double>(0.0,0.0)
            );

        apply_gate(modifier, statuslabel, quantumbit, Y_gate);

        delete Y_gate;
    });

    QObject::connect(ZGate,&QPushButton::clicked, [=]() {

        QuantumGate *Z_gate = new QuantumGate(
            std::complex<double>(1.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(-1.0,0.0)
            );

        apply_gate(modifier, statuslabel, quantumbit, Z_gate);

        delete Z_gate;
    });

    QObject::connect(HGate,&QPushButton::clicked, [=]() {

        QuantumGate *H_gate = new QuantumGate(
            std::complex<double>(1.0 / std::sqrt(2),0.0),
            std::complex<double>(1.0 / std::sqrt(2),0.0),
            std::complex<double>(1.0 / std::sqrt(2),0.0),
            std::complex<double>(-1.0 / std::sqrt(2),0.0)
            );

        apply_gate(modifier, statuslabel, quantumbit, H_gate);

        delete H_gate;
    });

    QObject::connect(SGate,&QPushButton::clicked, [=]() {

        QuantumGate *S_gate = new QuantumGate(
            std::complex<double>(1.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,1.0)
            );

        apply_gate(modifier, statuslabel, quantumbit, S_gate);

        delete S_gate;
    });

    QObject::connect(SGate_adj,&QPushButton::clicked, [=]() {

        QuantumGate *S_gate_adj = new QuantumGate(
            std::complex<double>(1.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,-1.0)
            );

        apply_gate(modifier, statuslabel, quantumbit, S_gate_adj);

        delete S_gate_adj;
    });

    QObject::connect(TGate,&QPushButton::clicked, [=]() {

        QuantumGate *T_gate = new QuantumGate(
            std::complex<double>(1.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(1.0 / std::sqrt(2),1.0 / std::sqrt(2))
            );

        apply_gate(modifier, statuslabel, quantumbit, T_gate);

        delete T_gate;
    });

    QObject::connect(TGate_adj,&QPushButton::clicked, [=]() {

        QuantumGate *T_gate_adj = new QuantumGate(
            std::complex<double>(1.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(1.0 / std::sqrt(2),-1.0 / std::sqrt(2))
            );

        apply_gate(modifier, statuslabel, quantumbit, T_gate_adj);

        delete T_gate_adj;
    });

    QObject::connect(Custom_gate, &QPushButton::clicked, [=]() {
        try{
            double m11v = std::stod(m11->text().toUtf8().toStdString());
            double m11_iv = std::stod(m11_i->text().toUtf8().toStdString());
            double m12v = std::stod(m12->text().toUtf8().toStdString());
            double m12_iv = std::stod(m12_i->text().toUtf8().toStdString());
            double m21v = std::stod(m21->text().toUtf8().toStdString());
            double m21_iv = std::stod(m21_i->text().toUtf8().toStdString());
            double m22v = std::stod(m22->text().toUtf8().toStdString());
            double m22_iv = std::stod(m22_i->text().toUtf8().toStdString());

            QuantumState* check = new QuantumState(*quantumbit);

            QuantumGate *custom_gate = new QuantumGate(
                std::complex<double>(m11v,m11_iv),
                std::complex<double>(m12v,m12_iv),
                std::complex<double>(m21v,m21_iv),
                std::complex<double>(m22v,m22_iv)
                );

            (*check) *= (*custom_gate);

            double amplitude_length = std::pow(std::abs(check->a), 2.0) + std::pow(std::abs(check->b), 2.0);

            if(std::abs(amplitude_length -1.0) < 0.01){
                apply_gate(modifier, statuslabel, quantumbit, custom_gate);
            }
            else{
                QMessageBox::critical(nullptr, "Error", "Invalid gate, length of the amplitude is not one");
            }

            delete custom_gate;
        }
        catch(std::invalid_argument arg){
            QMessageBox::critical(nullptr, "Error", "Plese fill all the neccessary boxes with valid values to define a custom gate");
        }
    });

    QObject::connect(Xrot_button, &QPushButton::clicked, [=]() {
        try{
            double xrot_value = std::stod(Xrot->text().toUtf8().toStdString());
            xrot_value *= 0.017453; //conversion to radian;

            QuantumGate *xrot_gate = new QuantumGate(
                std::complex<double>(cos(xrot_value / 2.0),0.0),
                std::complex<double>(0.0,-sin(xrot_value / 2.0)),
                std::complex<double>(0.0,-sin(xrot_value / 2.0)),
                std::complex<double>(cos(xrot_value / 2.0),0.0)
                );

            apply_gate(modifier, statuslabel, quantumbit, xrot_gate);

            delete xrot_gate;
        }
        catch(std::invalid_argument arg){
            QMessageBox::critical(nullptr, "Error", "Please fill the field with a valid rotate value");
        }
    });

    QObject::connect(Yrot_button, &QPushButton::clicked, [=]() {
        try{
            double yrot_value = std::stod(Yrot->text().toUtf8().toStdString());
            yrot_value *= 0.017453; //conversion to radian;

            QuantumGate *yrot_gate = new QuantumGate(
                std::complex<double>(cos(yrot_value / 2.0),0.0),
                std::complex<double>(-sin(yrot_value / 2.0),0.0),
                std::complex<double>(sin(yrot_value / 2.0),0.0),
                std::complex<double>(cos(yrot_value / 2.0),0.0)
                );

            apply_gate(modifier, statuslabel, quantumbit, yrot_gate);

            delete yrot_gate;
        }
        catch(std::invalid_argument arg){
            QMessageBox::critical(nullptr, "Error", "Please fill the field with a valid rotate value");
        }
    });

    QObject::connect(Zrot_button, &QPushButton::clicked, [=]() {
        try{
            double zrot_value = std::stod(Zrot->text().toUtf8().toStdString());
            zrot_value *= 0.017453; //conversion to radian;

            std::complex<double> i(0, 1);

            QuantumGate *zrot_gate = new QuantumGate(
                std::exp(-i * zrot_value / 2.0),
                std::complex<double>(0.0,0.0),
                std::complex<double>(0.0,0.0),
                std::exp(i * zrot_value / 2.0)
                );

            apply_gate(modifier, statuslabel, quantumbit, zrot_gate);

            delete zrot_gate;
        }
        catch(std::invalid_argument arg){
            QMessageBox::critical(nullptr, "Error", "Please fill the field with a valid rotate value");
        }
    });

    QObject::connect(resetbutton, &QPushButton::clicked, [=]() {
        quantumbit->a = std::complex<double>(1.0,0.0);
        quantumbit->b = std::complex<double>(0.0,0.0);

        QuantumGate *I_gate = new QuantumGate(
            std::complex<double>(1.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,0.0),
            std::complex<double>(0.0,1.0)
            );

        apply_gate(modifier, statuslabel, quantumbit, I_gate);

        delete I_gate;
    });



    layout->addWidget(new QLabel("Normal Gates"), 0, 0, 1, 2);

    // Second row: Buttons X gate and Y gate
    layout->addWidget(XGate, 1, 0);
    layout->addWidget(YGate, 1, 1);

    // Third row: Buttons Z gate and H gate
    layout->addWidget(ZGate, 2, 0);
    layout->addWidget(HGate, 2, 1);

    // Fourth row: Label "phase gates"
    layout->addWidget(new QLabel("Phase Gates"), 3, 0, 1, 2);

    // Fifth row: Buttons S gate and T gate
    layout->addWidget(SGate, 4, 0);
    layout->addWidget(SGate_adj, 4, 1);

    // Sixth row: Buttons St gate and Tt gate
    layout->addWidget(TGate, 5, 0);
    layout->addWidget(TGate_adj, 5, 1);

    // Seventh row: Label "own gate"
    layout->addWidget(new QLabel("Custom Gate"), 6, 0, 1, 2);

    // Eighth row: Two text fields
    layout->addWidget(m11, 7, 0);
    layout->addWidget(m11_i, 7, 1);

    // Ninth row: Two more text fields
    layout->addWidget(m12, 8, 0);
    layout->addWidget(m12_i, 8, 1);

    layout->addWidget(m21, 9, 0);
    layout->addWidget(m21_i, 9, 1);

    layout->addWidget(m22, 10, 0);
    layout->addWidget(m22_i, 10, 1);

    // Tenth row: Button "Apply"
    layout->addWidget(Custom_gate, 11, 0, 1, 2);

    layout->addWidget(new QLabel("Rotation gates"), 12, 0, 1, 2);

    layout->addWidget(Xrot_button, 13, 1);
    layout->addWidget(Xrot, 13, 0);

    layout->addWidget(Yrot_button, 14, 1);
    layout->addWidget(Yrot, 14, 0);

    layout->addWidget(Zrot_button, 15, 1);
    layout->addWidget(Zrot, 15, 0);

    layout->addWidget(resetbutton, 16, 0, 1, 2);

    layout->addWidget(statuslabel, 17 ,0 ,1 ,2);

    QuantumGate *I_gate = new QuantumGate(
        std::complex<double>(1.0,0.0),
        std::complex<double>(0.0,0.0),
        std::complex<double>(0.0,0.0),
        std::complex<double>(0.0,1.0)
        );

    apply_gate(modifier, statuslabel, quantumbit, I_gate);

    delete I_gate;

    return layout;

}
