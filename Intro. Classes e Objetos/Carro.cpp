#include <iostream>
#include <sstream>

using namespace std;

class Carro {
private:
  double tanque;
  double distanciaPerc;
  int consumo;

public:
  Carro(double t = 0, double dp = 0, int c = 15) {
    tanque = t;
    distanciaPerc = dp;
    consumo = c;
  }
  void obtemGasolina(double &t) { tanque = t; }
  void obtemDistancia(double &dp) { distanciaPerc = dp; }
  void obtemConsumo(int c) { consumo = c; }
  double defineGasolina() { return tanque; }
  double defineDistancia() { return distanciaPerc; }
  void abastece(double quant) {
    if (tanque + quant <= 50) {
      tanque += quant;
    } else {
      tanque = 50;
      cout << "Tanque cheio!!!" << endl;
    }
  }
  void move(double distancia) {
    double combustivelNec = distancia / tanque;
    if (combustivelNec <= tanque) {
      distanciaPerc += distancia;
    } else {
      cout << "Sem combustível!!!" << endl;
    }
  }
  string toString() {
    stringstream ss;
    ss << "Distancia percorrida: " << distanciaPerc << " Km" << endl;
    ss << "Combustivel restante: " << tanque << " litros" << endl;
    return ss.str();
  }
};
int main() {
  Carro carro1;
  Carro carro2;

  carro1.abastece(20);
  carro2.abastece(30);

  carro1.move(200);
  carro2.move(400);

  std::cout << "Carro 1:\n" << carro1.toString() << std::endl;
  std::cout << "Carro 2:\n" << carro2.toString() << std::endl;

  return 0;
}