/**
 * @file ramal.hpp
 * @brief Definição da classe de domínio Ramal.
 * @author João Pedro
 * @date 14 de novembro de 2025
 */

#ifndef RAMAL_HPP_INCLUDED
#define RAMAL_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;
/**
 * @brief Classe para armazenar e validar o ramal de um hotel.
 * @details O valor do ramal deve ser um inteiro entre 00 e 50.
 */
class Ramal{
    private:
        /**
         * @brief Limite máximo permitido para o ramal (50).
         */
        static const int LIMITE = 50;
        /**
         * @brief Armazena o valor do ramal.
         */
        int valor;
        /**
         * @brief Valida o valor do ramal.
         * @param valor Valor inteiro a ser validado.
         * @throw invalid_argument Se o valor estiver fora do intervalo de 0 a 50.
         */
        void validar(int);
    public:
        /**
         * @brief Define o valor do ramal após validação.
         * @param valor O valor inteiro (0-50) a ser definido.
         * @throw invalid_argument Se o valor for menor que 0 ou maior que 50.
         */
        void setValor(int);
        /**
         * @brief Retorna o valor atual do ramal.
         * @return O valor inteiro do ramal.
         */
        int getValor() const;
};

inline int Ramal::getValor() const{
    return valor;
}

#endif // RAMAL_HPP_INCLUDED
