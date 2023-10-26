#include <iostream>

using namespace std;

class Relogio{
private:
    int hora;
    int minuto;
    int segundo;
public:
    Relogio(int h, int m, int s){
        defineHora(h, m, s);
    }
    void defineHora(int h, int m, int s){
        if(h >= 0 && h < 24 && m >= 0 && m < 60 && s >=0 && s < 60){
            this->hora = h;
            this->minuto = m;
            this->segundo = s;
        }else{
            cout << "Horário inválido!" << endl;
        }
    }
    void obtemHora(int &h, int &m, int &s){
        h = hora;
        m = minuto;
        s = segundo;
    }
    void avancaSegundos(){
        segundo ++;
        if(segundo == 60){
            segundo = 0;
            minuto++;
            if(minuto == 60){
                minuto = 0;
                hora++;
                if (hora == 24){
                    hora =0;
                }
            }
        }
    }
};

int main(){
    Relogio relogio(23, 59, 59);

    int hora, minuto, segundo;
    relogio.obtemHora(hora, minuto, segundo);
    cout << "Horário: " << hora << ":" << minuto << ":" << segundo << endl;

    relogio.avancaSegundos();
    relogio.obtemHora(hora, minuto, segundo);
    cout << "Novo horário: " << hora << ":" << minuto << ":" << segundo << endl;

    return 0;
}