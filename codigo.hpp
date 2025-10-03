#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED
#include<string>
#include<stdexcept>

using namespace std;
class Codigo{
private:
    string valor;
    void validar(const string&valor);
    
public:
    Codigo(const string&valor);
    void setValor(const string&valor);
    string getValor() const;
    static const int TAMANHO_MAX = 10;
};
inline string Codigo::getValor() const{
    return valor;
}
#endif//CODIGO_HPP_INCLUDED