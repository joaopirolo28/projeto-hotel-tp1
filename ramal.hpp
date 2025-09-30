#ifndef RAMAL_HPP_INCLUDED
#define RAMAL_HPP_INCLUDED

#include <string>

using namespace std;

class Ramal{
    private:
        static const int LIMITE = 50;
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int getValor();
};

inline int Ramal::getValor(){
    return valor;
}

#endif // RAMAL_HPP_INCLUDED
