/**
 * @file Numero.hpp
 * @brief Definição da classe de domínio Numero.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef NUMERO_HPP_INCLUDED
#define NUMERO_HPP_INCLUDED

#include <stdexcept>

using namespace std;

/**
 * @brief Classe para armazenar e validar um domínio do tipo Número.
 * @details Representa um número inteiro que deve estar dentro de um intervalo pré-definido.
 * O valor deve ser entre 1 e 999.
 */
class Numero {
private:
    /**
     * @brief Armazena o valor do número.
     */
    int valor;

    /**
     * @brief Valida um número de acordo com as regras de negócio.
     * @param valor O número inteiro a ser validado.
     * @throw invalid_argument se o número estiver fora do intervalo permitido.
     */
    void validar(int valor);

public:
    /**
     * @brief Constante que define o limite inferior do intervalo de validação.
     */
    static const int LIMITE_INFERIOR = 1;
    /**
     * @brief Constante que define o limite superior do intervalo de validação.
     */
    static const int LIMITE_SUPERIOR = 999;

    /**
     * @brief Construtor da classe Numero.
     * @details Inicializa o objeto com um valor, que é imediatamente validado.
     * @param valor O número a ser definido.
     * @throw invalid_argument Se o valor não atender aos critérios de validação.
     */
    Numero(int valor);

    Numero() {}

    /**
     * @brief Define o valor do número após validá-lo.
     * @param valor O número a ser definido.
     * @throw invalid_argument Se o valor não atender aos critérios de validação.
     */
    void setValor(int valor);

    /**
     * @brief Retorna o valor do número.
     * @return Um inteiro contendo o valor atual.
     */
    int getValor() const;
};

/**
 * @brief Implementação inline do método getValor.
 * @return O valor do atributo 'valor' da classe.
 */
inline int Numero::getValor() const {
    return valor;
}

#endif // NUMERO_HPP_INCLUDED
