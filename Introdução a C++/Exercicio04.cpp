/*Um programa que leia uma matriz de lin linhas por col colunas de inteiros e substitua todos os 
números negativos dessa matriz pelos seus respectivos módulos, imprimindo a matriz resultante.*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    int lin, col;
    cin >> lin >> col;
    vector<vector<int>> matriz(lin, vector<int>(col));
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matriz[i][j];
        }
    }
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matriz[i][j] < 0) {
                matriz[i][j] = abs(matriz[i][j]);
            }
        }
    }
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matriz[i][j];
            if (j < col - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}