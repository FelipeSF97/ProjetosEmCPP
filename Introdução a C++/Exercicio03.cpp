/*Um programa que le um número ímpar n e mostre uma saída em que aparecem: na primeira linha, os números de 1 até n;
na segunda linha, os números de 2 até n-1 alinhados com os mesmos valores da linha de cima; 
na terceira linha, os números de 3 até n-2, alinhados com os mesmos valores da linha de cima; e assim por diante,
até que na última linha apareça apenas o valor (n+1)/2, alinhado como valor (n+1)/2 da linha de cima.*/

#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for(int k = 1; k <= i-1; k++)
      cout << "  ";
    for(int j = i; j <= n; j++){
      cout << j;
      cout << " ";
    }
    cout << endl;
    n--;
  }
  return 0;
}