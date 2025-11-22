/**
 * @file Telefone.hpp
 * @brief Definição da classe de domínio Telefone.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef TELEFONE_HPP_INCLUDED
#define TELEFONE_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Classe para armazenar e validar um número de telefone.
 * @details O número de telefone deve seguir o formato internacional +DDDDDDDDDDDD,
 * consistindo do caractere '+' seguido por 12 dígitos.
 */
class Telefone {
private:
    /**
     * @brief Armazena o valor do número de telefone.
     */
    string valor;

    /**
     * @brief Valida um número de telefone de acordo com as regras de formato.
     * @param valor String contendo o telefone a ser validado.
     * @throw invalid_argument se o telefone for inválido.
     */
    void validar(const string& );

public:
    /**
     * @brief Constante que define o número de dígitos que o telefone deve ter.
     */
    static const int TAMANHO = 12;

    /**
     * @brief Construtor da classe Telefone.
     * @details Inicializa o objeto com um número de telefone, que é imediatamente validado.
     * @param valor O número de telefone a ser definido.
     * @throw invalid_argument Se o valor não atender aos critérios de validação.
     */
    Telefone(string);

    /**
     * @brief Construtor padrão da classe Telefone.
     * @details Inicializa o objeto com um valor padrão (string vazia).
     * Necessário para a criação de entidades (como Hotel) que contêm este domínio.
     */
    Telefone();

    /**
     * @brief Define o valor do número de telefone após validá-lo.
     * @param valor O número de telefone a ser definido.
     * @throw invalid_argument Se o valor não atender aos critérios de validação.
     */
    void setValor(string);

    /**
     * @brief Retorna o valor do número de telefone.
     * @return Uma string contendo o valor atual do telefone.
     */
    string getValor() const;
};

/**
 * @brief Implementação inline do método getValor.
 * @return O valor do atributo 'valor' da classe.
 */
inline string Telefone::getValor() const {
    return valor;
}

#endif // TELEFONE_HPP_INCLUDED
