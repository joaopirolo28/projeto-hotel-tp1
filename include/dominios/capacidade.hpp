/**
 * @file capacidade.hpp
 * @brief Definicao da classe de dominio Capacidade.
 * @author Joao Pedro
 * @date 14 de novembro de 2025
 */

#ifndef CAPACIDADE_HPP_INCLUDED
#define CAPACIDADE_HPP_INCLUDED

#include <stdexcept>

using namespace std;
/**
 * @brief Classe para armazenar e validar a capacidade de um quarto de hotel.
 * @details O valor deve ser um inteiro entre 1 e 4 (inclusive).
 */
class Capacidade{
    private:
        /**
         * @brief Valor minimo permitido para a capacidade (1).
         */
        static const int MINIMO = 1;
        /**
         * @brief Valor maximo permitido para a capacidade (4).
         */
        static const int MAXIMO = 4;
        /**
         * @brief Armazena o valor da capacidade.
         */
        int valor;
        /**
         * @brief Valida o valor da capacidade.
         * @param valor Valor inteiro a ser validado.
         * @throw invalid_argument Se o valor estiver fora do intervalo permitido.
         */
        void validar(int);
    public:
        /**
        * @brief Construtor padrão da classe Capacidade.
        * @details Inicializa o objeto com um valor padrão (geralmente 0 ou indefinido).
        * Necessário para a criação de entidades que contêm este domínio.
        */
        Capacidade ();
        /**
        * @brief Construtor com valor da classe Capacidade.
        * @details Inicializa o objeto com um valor, que é imediatamente validado.
        * @param valor O valor da capacidade (1, 2, 3 ou 4).
        * @throw invalid_argument Se o valor não atender aos critérios de validação.
        */
        Capacidade (int);
        /**
         * @brief Define o valor da capacidade apos validacao.
         * @param valor O valor inteiro (1-4) a ser definido.
         * @throw invalid_argument Se o valor nao for 1, 2, 3 ou 4.
         */
        void setValor(int);
        /**
         * @brief Retorna o valor atual da capacidade.
         * @return O valor inteiro da capacidade.
         */
        int getValor() const;
};

inline int Capacidade::getValor() const{
    return valor;
}

#endif // CAPACIDADE_HPP_INCLUDED
