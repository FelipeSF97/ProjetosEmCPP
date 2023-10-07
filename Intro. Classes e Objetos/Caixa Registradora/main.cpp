#include <iostream>
#include "CaixaRegistradora.hpp"

using namespace std;

int main() {
    CaixaRegistradora *caixa = new CaixaRegistradora();

    caixa->adicionaItem(1.99);
    caixa->adicionaItem(2.99);
    caixa->adicionaItem(1.50);

    cout << caixa->obtemTotal() << endl;
    cout << caixa->obtemNumItens() << endl;

    caixa->limpa();
    cout << caixa->obtemTotal() << endl;
    cout << caixa->obtemNumItens() << endl;

    delete caixa;

    CaixaRegistradora caixa2;
    caixa2.adicionaItem(123.456);

    cout << caixa2.obtemTotal() << endl;
    cout << caixa2.obtemNumItens() << endl;

    return 0;
}