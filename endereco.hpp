#ifndef ENDERECO_HPP_INCLUDED
#define ENDERECO_HPP_INCLUDED
#include <string>
#include <stdexcept>

using namespace std;

class Endereco{
    private:
        string endereco_Completo;
        void validar(string);
    public:
        void setEndereco(string);
        string getEndereco() const;
};

inline string Endereco::getEndereco() const{
    return endereco_Completo;
}

#endif // ENDERECO_HPP_INCLUDED
