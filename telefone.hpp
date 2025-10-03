#ifndef TELEFONE_HPP_INCLUDED
#define TELEFONE_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

class Telefone{
    private:
    string valor;
    void validar(const string&valor);
    public:
    static const int TAMANHO = 12;
    Telefone(const string&valor);
    void setvalor(const string&valor);
    string getValor() const;
};

inline string Telefone::getValor()const{
    return valor;
}
#endif // TELEFONE_HPP_INCLUDED