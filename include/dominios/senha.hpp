/**
 * @file capacidade.hpp
 * @brief Definicao da classe de dominio Capacidade.
 * @author Joao Pedro
 * @date 14 de novembro de 2025
 */

#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED
#include <string>
#include <stdexcept>
#include <map>

using namespace std;
/**
 * @brief Classe para armazenar e validar uma senha de acesso.
 * @details A senha deve ter exatamente 5 caracteres e incluir pelo menos uma letra miníscula,
 * uma letra maiúscula, um dígito e um caractere especial (dentre os permitidos: ! " # $ % & ?).
 */
class Senha{
    private:
        /**
         * @brief Armazena a string da senha.
         */
        string senha;
        /**
         * @brief Mapa de caracteres especiais permitidos.
         */
        map<char, int> especiais = {{'!', 1}, {'\"', 1}, {'#', 1}, {'$', 1}, {'%', 1}, {'&', 1}, {'?', 1}};
        /**
         * @brief Valida a senha contra as regras de formato e conte�do.
         * @param senha String contendo a senha a ser validada.
         * @throw invalid_argument Se a senha for inválida.
         */
        void validar(string);
    public:
        /**
         * @brief Construtor padrão da classe Senha.
         * @details Inicializa o objeto com um valor padrão (string vazia).
         * Necessário para a criação de entidades (como Gerente) que contêm este domínio.
         */
        Senha();

        /**
         * @brief Construtor com valor da classe Senha.
         * @details Inicializa o objeto com uma senha, que é imediatamente validada.
         * @param valor A senha a ser definida.
         * @throw invalid_argument Se a senha não atender aos critérios de validação.
         */
        Senha(string);

        /**
         * @brief Retorna o valor atual da senha.
         * @return Uma string contendo a senha.
         */
        string getSenha() const;
        /**
         * @brief Define o valor da senha após validação.
         * @param senha A string contendo a senha a ser definida.
         * @throw invalid_argument Se a senha não atender aos critérios de validação (tamanho, composição de caracteres).
         */
        void setSenha(string);
};

inline string Senha::getSenha()const {
    return senha;
}

#endif // SENHA_HPP_INCLUDED
