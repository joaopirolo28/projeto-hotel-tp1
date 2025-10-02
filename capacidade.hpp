#ifndef CAPACIDADE_HPP_INCLUDED
#define CAPACIDADE_HPP_INCLUDED

using namespace std;

class Capacidade{
    private:
        static const int MINIMO = 1;
        static const int MAXIMO = 4;
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int getValor();
};

inline int Capacidade::getValor(){
    return valor;
}

#endif // CAPACIDADE_HPP_INCLUDED
