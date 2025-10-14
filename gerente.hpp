#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "pessoa.hpp"
#include "ramal.hpp"
#include "senha.hpp"

class Gerente : public Pessoa {
private:
    Ramal ramal;
    Senha senha;

public:
    void setRamal(const Ramal& ramal);
    Ramal getRamal() const;

    void setSenha(const Senha& senha);
    Senha getSenha() const;
};

#endif // GERENTE_HPP