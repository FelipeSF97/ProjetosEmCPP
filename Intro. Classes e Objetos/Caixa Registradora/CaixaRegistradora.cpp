#include <iostream>
#include "CaixaRegistradora.hpp"

using namespace std;

CaixaRegistradora::CaixaRegistradora(double t, int ni){
    total = t;
    numItens = ni;
}
CaixaRegistradora::~CaixaRegistradora(){}
int CaixaRegistradora::obtemNumItens(){
    return numItens;
}
double CaixaRegistradora::obtemTotal(){
    return total;
}
void CaixaRegistradora::adicionaItem(double preco){
    total += preco;
    numItens++;
}
void CaixaRegistradora::limpa(){
    total = 0.0;
    numItens = 0;
}