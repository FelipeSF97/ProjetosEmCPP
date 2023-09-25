/*Programa que cria o cadastro de pessoas com seu nome, idade e data nascimento. O vetor deve suportar até 10 cadastros.
O usuário deve digitar "+" caso queria adicionar mais pessoas, ou "." caso não queira. O vetor cheio também encerra a adição. 
Após adicionar pessoas ao vetor, o suário deve inserir um mês. O programa irá ler as informações do usuário ao mês correspondente*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Data{
  int dia;
  int mes;
  int ano;
};

struct Pessoa{
  string nome;
  double altura;
  Data nascimento;
};

int main(){
  const int max_pessoas = 10;
  Pessoa pessoas[max_pessoas];
  int quant_pessoas = 0;

  while(true){
    string option;
    getline(cin, option);

    if(option == "+"){
      if(quant_pessoas < max_pessoas){
        Pessoa add;
        
        getline(cin, add.nome);
        string strAltura;
        getline(cin, strAltura);
        add.altura = stod(strAltura);
        string strDia;
        getline(cin, strDia);
        add.nascimento.dia = stoi(strDia);
        string strMes;
        getline(cin, strMes);
        add.nascimento.mes = stoi(strMes);
        string strAno;
        getline(cin, strAno);
        add.nascimento.ano = stoi(strAno);
        
        pessoas[quant_pessoas] = add;
        quant_pessoas++;
        cout << "> OK" << endl;
      }else{
        cout << "> VETOR CHEIO" << endl;
        string ignoredInput;
        getline(cin, ignoredInput);
        string ignoredInput2;
        getline(cin, ignoredInput2);
        string ignoredInput3;
        getline(cin, ignoredInput3);
        string ignoredInput4;
        getline(cin, ignoredInput4);
        string ignoredInput5;
        getline(cin, ignoredInput5);
      }
    }else if(option == "."){
      break;
    }else{
      cout << "> OPÇÃO INVÁLIDA" << endl;
    }
  }
  int mesAlvo;
  cin >> mesAlvo;
  cin.ignore();

  bool alvo = false;

  for(int i = 0; i < quant_pessoas; i++){
    if (pessoas[i].nascimento.mes == mesAlvo){
      cout << pessoas[i].nome << "; " << fixed << setprecision(2) << pessoas[i].altura << "; " << pessoas[i].nascimento.dia << "/" << pessoas[i].nascimento.mes << "/" << pessoas[i].nascimento.ano << endl;
      alvo = true;
    }
  }
  if (!alvo){
    cout << "> SEM ANIVERSARIOS" << endl;
  }
  return 0;
}