#ifndef _TELEVISOR_HPP
#define _TELEVISOR_HPP

using namespace std;
class Televisor{
private:
    int volume;
    int canal;
public:
    Televisor(int v, int c);
    int obtemVolume();
    int obtemCanal();
    void aumentaVolume();
    void diminuiVolume();
    void proximoCanal();
    void canalAnterior();

};

#endif