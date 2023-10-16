#include <iostream>
#include "Pessoa.hpp"
#include <string>

using namespace std;

Pessoa::Pessoa(string n, int i, double a){
    nome = n;
    idade = i;
    altura = a;
}
Pessoa::~Pessoa(){}
string Pessoa::obtemNome(){
    return nome;
}
int Pessoa::obtemIdade(){
    return idade;
}
double Pessoa::obtemAltura(){
    return altura;
}
void Pessoa::defineNome(string n){
    nome = n;
}
void Pessoa::defineIdade(int i){
    idade = i;
}
void Pessoa::defineAltura(double a){
    altura = a;
}
void Pessoa::imprimeDados(){
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Altura: " << altura << " de altura" << endl;
}