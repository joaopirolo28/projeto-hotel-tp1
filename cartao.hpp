#ifndef CARTAO_HPP
#define CARTAO_HPP
#include<string>

using namespace std;

class Cartao{

private:
string valor;
void validar(const string&valorCartao) const;

public:
Cartao()=default;
void setValor(const string&valorCartao);
string getValor()const;

};

inline string Cartao::getValor() const{
    return this->valor;
}
#endif //CARTAO_HPP