#ifndef HOSPEDE_HPP
#define HOSPEDE_HPP

#include "pessoa.hpp"
#include "endereco.hpp"
#include "cartao.hpp"

class Hospede : public Pessoa {
private:
    Endereco endereco;
    Cartao cartao;

public:
    void setEndereco(const Endereco& endereco);
    Endereco getEndereco() const;

    void setCartao(const Cartao& cartao);
    Cartao getCartao() const;
};

#endif // HOSPEDE_HPP