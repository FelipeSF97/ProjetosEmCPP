#include <iostream>
#include <sstream>

using namespace std;

class Pneu{
private:
    string marca;
    double pressao;
public:
    Pneu(string mar = "original", double pre = 28.0);
    ~Pneu();
    void defineMarca(string mar);
    void definePressao(double pre);
    string obtemMarca();
    double obtemPressao();
    string str();
};

class Motor{
private:
    double potencia;
    double capacidadeTanque;
    double nivelTanque;
    double consumoMedio;
public:
    Motor(double pot = 1.0, double capTanque = 45.0, double nivTanque = 0.0, double cosMed = 10.0);
    ~Motor();
    void definePotencia(double pot);
    void defineCapacidadeTanque(double litros);
    void defineNivelTanque(double litros);
    void defineConsumoMedio(double kml);
    double obtemPotencia();
    double obtemCapacidadeTanque();
    double obtemNivelTanque();
    double obtemConsumoMedio();
    void desloca(double km);
    void abastece(double litros);
    string str();
};

class Automovel{
private:
    string marca;
    double quilometragem;
    Motor motor;
    Pneu pneus[4];
public:
    Automovel(string mar = "indefinida", double km = 0, Motor motor = Motor(), Pneu p1 = Pneu(), Pneu p2 = Pneu(), Pneu p3 = Pneu(), Pneu p4 = Pneu());
    ~Automovel();
    void defineMarca(string mar);
    void defineQuilometragem(double km);
    void defineMotor(Motor *motor);
    void definePneu(int num, Pneu *pneu);
    string obtemMarca();
    double obtemQuilometragem();
    Motor *obtemMotor();
    Pneu *obtemPneu();
    void desloca(double km);
    void abastece(double litros);
    void calibra(double pressao);
    string str();
};

Pneu::Pneu(string mar, double pre){ marca = mar; pressao = pre; }
Pneu::~Pneu(){}
void Pneu::defineMarca(string mar){ marca = mar; }
void Pneu::definePressao(double pre){ pressao = pre; }
string Pneu::obtemMarca(){ return marca; }
double Pneu::obtemPressao(){ return pressao; }
string Pneu::str() {
    stringstream ss;
    ss << "Pneu [Marca: " << marca << ", Pressao: " << to_string(pressao) << "]";
    return ss.str();
}
Motor::Motor(double pot, double capTanque, double nivTanque, double cosMed){
    potencia = pot;
    capacidadeTanque = capTanque;
    nivelTanque = nivTanque;
    consumoMedio = cosMed;
}
Motor::~Motor(){}
void Motor::definePotencia(double pot){ potencia = pot; }
void Motor::defineCapacidadeTanque(double litros){ capacidadeTanque = litros;}
void Motor::defineNivelTanque(double litros) { nivelTanque = litros; }
void Motor::defineConsumoMedio(double kml) { consumoMedio = kml; }
double Motor::obtemPotencia() { return potencia; }
double Motor::obtemCapacidadeTanque() { return capacidadeTanque; }
double Motor::obtemNivelTanque() { return nivelTanque; }
double Motor::obtemConsumoMedio() { return consumoMedio; }
void Motor::desloca(double km) {
    double consumo = km / consumoMedio;
    if (consumo <= nivelTanque) {
        nivelTanque -= consumo;
        cout << "Deslocamento de " << km << " km realizado." << endl;
    } else {
        cout << "Combustível insuficiente para o deslocamento." << endl;
    }
}
void Motor::abastece(double litros) {
    if (nivelTanque + litros <= capacidadeTanque) {
        nivelTanque += litros;
        cout << "Abastecimento de " << litros << " litros realizado." << endl;
    } else {
        cout << "Capacidade máxima do tanque atingida." << endl;
    }
}
string Motor::str() {
    stringstream ss;
    ss << "Motor: Potencia - " << potencia << " hp, Capacidade do Tanque - " << capacidadeTanque << " litros, Nivel do Tanque - " << nivelTanque << " litros, Consumo Medio - " << consumoMedio << " km/l";
    return ss.str();
}
Automovel::Automovel(string mar, double km, Motor motor, Pneu p1, Pneu p2, Pneu p3, Pneu p4)
    : marca(mar), quilometragem(km), motor(motor) {
    pneus[0] = p1;
    pneus[1] = p2;
    pneus[2] = p3;
    pneus[3] = p4;
}

Automovel::~Automovel() {}

void Automovel::defineMarca(string mar){ marca = mar; }

void Automovel::defineQuilometragem(double km){ quilometragem = km; }

void Automovel::defineMotor(Motor *motor) { this->motor = *motor; }

void Automovel::definePneu(int num, Pneu *pneu) {
    if (num >= 0 && num < 4) {
        pneus[num] = *pneu;
    } else {
        cout << "Número de pneu inválido." << endl;
    }
}
string Automovel::obtemMarca() { return marca; }

double Automovel::obtemQuilometragem() { return quilometragem; }

Motor *Automovel::obtemMotor() { return &motor; }

Pneu *Automovel::obtemPneu() { return pneus; }

void Automovel::desloca(double km) { motor.desloca(km); quilometragem += km; }

void Automovel::abastece(double litros) { motor.abastece(litros); }

void Automovel::calibra(double pressao) {
    for (int i = 0; i < 4; i++) {
        pneus[i].definePressao(pressao);
    }
}
string Automovel::str() {
    stringstream ss;
    ss << "Automovel: Marca - " << marca << ", Quilometragem - " << quilometragem << endl;
    ss << motor.str() << endl;
    for (int i = 0; i < 4; i++) {
        ss << pneus[i].str() << endl;
    }
    return ss.str();
}
int main() {
    Pneu pneu1("Pirelli", 32.0);
    Pneu pneu2("Pirelli", 32.0);
    Pneu pneu3("Pirelli", 32.0);
    Pneu pneu4("Pirelli", 32.0);

    Motor motor(150.0, 60.0, 30.0, 15.0);

    Automovel carro("Fiat", 5000.0, motor, pneu1, pneu2, pneu3, pneu4);

    cout << "Estado Inicial:" << endl;
    cout << carro.str() << endl;

    carro.desloca(100.0);
    carro.abastece(20.0);
    carro.calibra(35.0);

    cout << "\nEstado Final:" << endl;
    cout << carro.str() << endl;

    return 0;
}