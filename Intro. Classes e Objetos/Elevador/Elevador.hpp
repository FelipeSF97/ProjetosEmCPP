#ifndef _ELEVADOR_HPP
#define _ELEVADOR_HPP

using namespace std;

class Elevador{
private:
    int andarAtual;
    int totalAndares;
    int capElevador;
    int quantPessoas;
public:
    Elevador(int cap, int ta);
    void entra();
    void sai ();
    void sobe();
    void desce();
    int obetemAndarAtual();
    int obtemTotalAndares();
    int obtemCapElevador();
    int obtemQuantPessoas();
};
#endif