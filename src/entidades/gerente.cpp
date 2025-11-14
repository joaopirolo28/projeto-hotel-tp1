#include "entidades/gerente.hpp"

void Gerente::setRamal(const Ramal& ramal) {
    this->ramal = ramal;
}

Ramal Gerente::getRamal() const {
    return ramal;
}

void Gerente::setSenha(const Senha& senha) {
    this->senha = senha;
}

Senha Gerente::getSenha() const {
    return senha;
}
