#ifndef _CAIXAREGISTRADORA_HPP
#define _CAIXAREGISTRADORA_HPP

using namespace std;

class CaixaRegistradora{
private:
    double total;
    int numItens;
public:
    CaixaRegistradora(double t = 0.0, int ni = 0);
    ~CaixaRegistradora();
    int obtemNumItens();
    double obtemTotal();
    void adicionaItem(double preco);
    void limpa();
};

 #endif