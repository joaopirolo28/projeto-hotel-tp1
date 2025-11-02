#ifndef CAPACIDADE_HPP_INCLUDED
#define CAPACIDADE_HPP_INCLUDED

#include <stdexcept>

using namespace std;

class Capacidade{
    private:
        static const int MINIMO = 1;
        static const int MAXIMO = 4;
        int valor;
        void validar(int);
    public:
        void setValor(int);
        int getValor() const;
};

inline int Capacidade::getValor() const{
    return valor;
}

#endif // CAPACIDADE_HPP_INCLUDED
