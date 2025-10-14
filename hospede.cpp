#include "hospede.hpp"

void Hospede::setEndereco(const Endereco& endereco) {
    this->endereco = endereco;
}

Endereco Hospede::getEndereco() const {
    return endereco;
}

void Hospede::setCartao(const Cartao& cartao) {
    this->cartao = cartao;
}

Cartao Hospede::getCartao() const {
    return cartao;
}