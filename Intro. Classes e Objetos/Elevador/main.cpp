#include <iostream>
#include "Elevador.hpp"

using namespace std;

int main(){
    Elevador elevador(10, 10);
    elevador.entra();
    elevador.sobe();
    elevador.entra();
    elevador.sobe();
    elevador.sai();
    elevador.sobe();
    elevador.sai();
    elevador.entra();
    elevador.desce();
    elevador.sai();

    cout << endl;
    cout << "Andar atual: " << elevador.obetemAndarAtual() << endl;
    cout << "Total de Andares: " << elevador.obtemTotalAndares() << endl;
    cout << "Capacidade: " << elevador.obtemCapElevador() << endl;
    cout << "Pessoas no elevador: " << elevador.obtemQuantPessoas() << endl;

    return 0;
}