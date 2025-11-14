/**
 * @file Codigo.hpp
 * @brief Definição da classe de domínio Codigo.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;
/**
 * @brief Classe para armazenar e validar um código de identificação.
 * @details O código deve ser composto por exatamente 10 caracteres,
 * que podem ser letras (a-z) ou dígitos (0-9).
 */
class Codigo {
private:
    /**
     * @brief Armazena o valor do código.
     */
    string valor;

    /**
     * @brief Valida um código de acordo com as regras de negócio.
     * @param valor String contendo o código a ser validado.
     * @throw invalid_argument se o código for inválido.
     */
    void validar(const string& valor);

public:
    /**
     * @brief Construtor da classe Codigo.
     * @details Inicializa o objeto com um valor de código, que é imediatamente validado.
     * @param valor O código a ser definido.
     * @throw invalid_argument Se o valor não atender aos critérios de validação.
     */
    Codigo(const string& valor);

    Codigo() {}

    /**
     * @brief Define o valor do código após validá-lo.
     * @param valor O código a ser definido.
     * @throw invalid_argument Se o valor não atender aos critérios de validação.
     */
    void setValor(const string& valor);

    /**
     * @brief Retorna o valor do código.
     * @return Uma string contendo o valor atual do código.
     */
    string getValor() const;

    /**
     * @brief Constante que define o tamanho exato que o código deve ter.
     */
    static const int TAMANHO_MAX = 10;
};

/**
 * @brief Implementação inline do método getValor.
 * @return O valor do atributo 'valor' da classe.
 */
inline string Codigo::getValor() const {
    return valor;
}

#endif // CODIGO_HPP_INCLUDED
