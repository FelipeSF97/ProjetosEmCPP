/*Uma matriz quadrada de inteiros que imprime o número que contém o menor elemento da matriz.*/

#include <iostream>

using namespace std;

int main(){
  int valor, num, tam;
  cin >> tam;

  int matriz[tam][tam];
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam; j++){
      cin >> matriz[i][j];
    }
  }
  num = matriz[0][0];
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam; j++){
      if(matriz[i][j] < num){
      num = matriz[i][j];
      valor = i;
      }
    }
  }
  cout << valor << endl;
  return 0;
}