#ifndef _PESSOA_HPP
#define _PESSOA_CPP

#include <string>

using namespace std;
 class Pessoa{
private:
    string nome;
    int idade;
    double altura;
public:
    Pessoa(string n = "", int i = 0, double a = 0.00);
    ~Pessoa();
    string obtemNome();
    int obtemIdade();
    double obtemAltura();
    void defineNome(string n);
    void defineIdade(int i);
    void defineAltura(double a);
    void imprimeDados();
 };

#endif