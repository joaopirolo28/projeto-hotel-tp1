/**
 * @file Hospede.hpp
 * @brief Definição da classe da entidade Hospede.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef HOSPEDE_HPP
#define HOSPEDE_HPP

#include "pessoa.hpp"
#include "endereco.hpp"
#include "cartao.hpp"

/**
 * @brief Classe entidade que representa um Hóspede.
 * @details Herda de Pessoa e adiciona atributos específicos de um hóspede,
 * como Endereço e Cartão de crédito para fins de reserva e faturamento.
 */
class Hospede : public Pessoa {
private:
    /**
     * @brief O endereço postal do hóspede.
     */
    Endereco endereco;

    /**
     * @brief O cartão de crédito do hóspede, usado para garantia de reservas.
     */
    Cartao cartao;

public:
    /**
     * @brief Define o endereço do hóspede.
     * @param endereco Um objeto do tipo Endereco.
     */
    void setEndereco(const Endereco& endereco);

    /**
     * @brief Retorna o endereço do hóspede.
     * @return Um objeto do tipo Endereco.
     */
    Endereco getEndereco() const;

    /**
     * @brief Define o cartão de crédito do hóspede.
     * @param cartao Um objeto do tipo Cartao.
     */
    void setCartao(const Cartao& cartao);

    /**
     * @brief Retorna o cartão de crédito do hóspede.
     * @return Um objeto do tipo Cartao.
     */
    Cartao getCartao() const;
};

#endif // HOSPEDE_HPP