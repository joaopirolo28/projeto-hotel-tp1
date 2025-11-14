/**
 * @file endereco.hpp
 * @brief Definição da classe de domínio Endereco.
 * @author João Pedro
 * @date 14 de novembro de 2025
 */

#ifndef ENDERECO_HPP_INCLUDED
#define ENDERECO_HPP_INCLUDED
#include <string>
#include <stdexcept>

using namespace std;
/**
 * @brief Classe para armazenar e validar um endereço.
 * @details O endereço deve ser uma string com 5 a 30 caracteres.
 * Não pode começar ou terminar com vírgula, ponto ou espaço.
 */
class Endereco{
    private:
        /**
         * @brief Armazena o endereço completo.
         */
        string endereco_Completo;
        /**
         * @brief Valida o formato e o tamanho da string do endereço.
         * @param endereco String contendo o endereço a ser validado.
         * @throw invalid_argument Se o endereço for inválido.
         */
        void validar(string);
    public:
        /**
         * @brief Define o valor do endereço após validação.
         * @param endereco A string contendo o endereço completo.
         * @throw invalid_argument Se o endereço não atender aos critérios de validação (tamanho, caracteres iniciais/finais, pontuação).
         */
        void setEndereco(string);
        /**
         * @brief Retorna o valor atual do endereço.
         * @return Uma string contendo o endereço completo.
         */
        string getEndereco() const;
};

inline string Endereco::getEndereco() const{
    return endereco_Completo;
}

#endif // ENDERECO_HPP_INCLUDED
