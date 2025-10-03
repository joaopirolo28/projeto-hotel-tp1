#ifndef NUMERO_HPP_INCLUDED
#define NUMERO_HPP_INCLUDED

#include<stdexcept>

class Numero{
    private:
    int valor;
    void validar(int valor);
    public:
    Numero(int valor);
    void setValor(int valor);
    int getValor() const;
    static const int LIMITE_INFERIOR = 1;
    static const int LIMITE_SUPERIOR = 999;
};

inline int Numero::getValor() const{
    return valor;
}
#endif // NUMERO_HPP_INCLUDED