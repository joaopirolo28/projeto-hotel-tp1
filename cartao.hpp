/**
 * @file Cartao.hpp
 * @brief Definição da classe de domínio Cartao.
 * @author Tarsila Rocha
 * @date 16 de outubro de 2025
 */

#ifndef CARTAO_HPP
#define CARTAO_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe para armazenar e validar um número de cartão de crédito.
 * @details O número do cartão deve conter 16 dígitos e ser validado
 * pelo algoritmo de Luhn.
 */
class Cartao {

private:
    std::string valor;

    /**
     * @brief Valida um número de cartão de crédito.
     * @details A validação verifica se o número tem 16 dígitos e passa
     * no teste do algoritmo de Luhn.
     * @param valorCartao String contendo o número do cartão a ser validado.
     * @throw std::invalid_argument se o número do cartão for inválido.
     */
    void validar(const std::string& valorCartao) const;

public:
    /**
     * @brief Construtor da classe Cartao.
     * @details Inicializa o objeto com um valor de cartão de crédito,
     * que é imediatamente validado.
     * @param valorCartao O número do cartão a ser definido.
     * @throw std::invalid_argument Se o valor não atender aos critérios de validação.
     */
    Cartao(const std::string& valorCartao);

    /**
     * @brief Define o valor do número do cartão de crédito.
     * @param valorCartao O número do cartão a ser definido.
     * @throw std::invalid_argument Se o valor não atender aos critérios de validação.
     */
    void setValor(const std::string& valorCartao);

    /**
     * @brief Retorna o valor do número do cartão.
     * @return Uma string contendo o valor atual do cartão.
     */
    std::string getValor() const;

};

/**
 * @brief Implementação inline do método getValor.
 * @return O valor do atributo 'valor' da classe.
 */
inline std::string Cartao::getValor() const {
    return this->valor;
}

#endif //CARTAO_HPP