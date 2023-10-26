#include <iostream>
#include "Televisor.hpp"

using namespace std;

int main(){
    Televisor televisor(0, 1);
    cout << "Volume : " << televisor.obtemVolume() << endl;
    cout << "Canal: " << televisor.obtemCanal() << endl;
    televisor.obtemCanal();
    televisor.aumentaVolume();
    televisor.aumentaVolume();
    televisor.proximoCanal();
    televisor.proximoCanal();
    televisor.diminuiVolume();
    televisor.canalAnterior();
}