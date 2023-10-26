#include <iostream>
#include "Elevador.hpp"

using namespace std;

Elevador::Elevador(int cap, int ta){
    andarAtual = 0;
    capElevador = cap;
    totalAndares = ta;
    quantPessoas = 0;
}
int Elevador::obetemAndarAtual(){
    return andarAtual;
}
int Elevador::obtemTotalAndares(){
    return totalAndares;
}
int Elevador::obtemCapElevador(){
    return capElevador;
}
int Elevador::obtemQuantPessoas(){
    return quantPessoas;
}
void Elevador::entra(){
    if(quantPessoas < capElevador){
        quantPessoas++;
        cout << "Entra uma pessoa. Total de pessoas no elevador: " << quantPessoas << endl;
    }else{
        cout << "Elevador cheio!"<< endl;
    }
}
void Elevador::sai(){
    if(quantPessoas > 0){
        quantPessoas--;
        cout << "Sai uma pessoa. Total de pessoas no elevador: " << quantPessoas << endl;
    }else{
        cout << "O elevador está vazio." << endl;
    }
}
void Elevador::sobe(){
    if(andarAtual < totalAndares){
        andarAtual++;
        cout << "Sobe um andar. Andar atual: " << andarAtual << endl;
    }else{
        cout << "Último andar!" << endl;
    }
}
void Elevador::desce(){
    if(andarAtual > 0){
        andarAtual--;
        cout << "Desce um andar. Andar atual: " << andarAtual << endl;
    }else{
        cout << "Térreo." << endl;
    }
}
