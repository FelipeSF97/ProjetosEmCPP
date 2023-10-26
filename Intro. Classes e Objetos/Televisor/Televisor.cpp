#include <iostream>
#include "Televisor.hpp"

using namespace std;

Televisor::Televisor(int v = 0, int c = 1){
    volume = v;
    canal = c;
}
int Televisor::obtemVolume(){return volume;}
int Televisor::obtemCanal(){return canal;}
void Televisor::aumentaVolume(){
    if(volume < 100){
        volume++;
        cout << "Aumenta Volume: " << volume << endl;
    }else{
        cout << "Volume máximo!" << endl;
    }
}
void Televisor::diminuiVolume(){
    if(volume > 0){
        volume--;
        cout << "Diminui Volume: " << volume << endl;
    }else{
        cout << "Volume mínimo!" << endl;
    }
}
void Televisor::proximoCanal(){
    if(canal < 50){
        canal++;
        cout << "Próximo Canal: " << canal << endl;
    }else{
        cout << "Não há outros canais acima deste." << endl;
    }
}
void Televisor::canalAnterior(){
    if(canal > 1){
        canal--;
        cout << "Volta Canal: " << canal << endl;
    }else{
        cout << "Não há outros canais abaixo deste." << endl;
    }
}


