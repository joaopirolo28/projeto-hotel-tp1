/**
 * @file Dinheiro.hpp
 * @brief Definição da classe de domínio Dinheiro.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

#include <stdexcept> // Necessário para invalid_argument

using namespace std;
/**
 * @brief Classe para armazenar e validar um valor monetário.
 * @details Armazena o valor internamente como um número inteiro de centavos
 * para evitar problemas de arredondamento com ponto flutuante. O valor
 * deve estar no intervalo de 0,01 a 1.000.000,00.
 */
class Dinheiro {

private:
    /**
     * @brief Armazena o valor monetário como um total de centavos (long int).
     */
    long int valorCentavos;

    /**
     * @brief Valida um valor monetário de acordo com as regras de negócio.
     * @param valor O valor monetário em formato double a ser validado.
     * @throw invalid_argument se o valor estiver fora do intervalo permitido.
     */
    void validar(double valor) const;

public:
    /**
     * @brief Define o valor monetário após validá-lo.
     * @details Converte o valor double para um total de centavos para armazenamento interno.
     * @param valor O valor monetário a ser definido.
     * @throw invalid_argument Se o valor não atender aos critérios de validação.
     */
    void setValor(double valor);

    /**
     * @brief Retorna o valor monetário.
     * @details Converte o valor interno (em centavos) de volta para double.
     * @return O valor monetário em formato double.
     */
    double getValor() const;
    
};

#endif //DINHEIRO_HPP