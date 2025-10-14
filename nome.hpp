#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

class Nome{
    private:
        string nome;
        void validar(string);
    public:
        string getNome();
        void setNome(string);
};

inline string Nome::getNome(){
    return nome;
}

#endif // NOME_HPP_INCLUDED