#ifndef ENDERECO_HPP_INCLUDED
#define ENDERECO_HPP_INCLUDED
#include <string>

using namespace std;

class Endereco{
    private:
        string endereco_Completo;
        bool validar(string);
    public:
        bool setEndereco(string);
        string getEndereco();
};

inline string Endereco::getEndereco(){
    return endereco_Completo;
}

#endif // ENDERECO_HPP_INCLUDED
