#ifndef RAMAL_HPP_INCLUDED
#define RAMAL_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

class Ramal{
    private:
        static const int LIMITE = 50;
        int valor;
        void validar(int);
    public:
        void setValor(int);
        int getValor() const;
};

inline int Ramal::getValor() const{
    return valor;
}

#endif // RAMAL_HPP_INCLUDED
