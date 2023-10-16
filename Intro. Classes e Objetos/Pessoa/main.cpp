#include <iostream>
#include "Pessoa.hpp"

using namespace std;

int main(){
    Pessoa pessoa("Felipe", 26, 1.72);
    pessoa.imprimeDados();

    pessoa.defineIdade(30);
    pessoa.defineAltura(1.73);
    pessoa.imprimeDados();

    return 0;
}