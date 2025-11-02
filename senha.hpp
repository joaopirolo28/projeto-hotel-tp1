#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED
#include <string>
#include <stdexcept>
#include <map>

using namespace std;

class Senha{
    private:
        string senha;
        map<char, int> especiais = {{'!', 1}, {'\"', 1}, {'#', 1}, {'$', 1}, {'%', 1}, {'&', 1}, {'?', 1}};
        void validar(string);
    public:
        string getSenha();
        void setSenha(string);
};

inline string Senha::getSenha(){
    return senha;
}

#endif // SENHA_HPP_INCLUDED
