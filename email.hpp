/**
 * @file Email.hpp
 * @brief Definição da classe de domínio Email.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Classe para armazenar e validar um endereço de email.
 * @details O email é validado em duas partes: local e domínio, separadas por '@'.
 * A parte local pode ter até 64 caracteres e o domínio até 255 caracteres.
 * Regras específicas de caracteres permitidos são aplicadas a cada parte.
 */
class Email {
private:
    /**
     * @brief Armazena o valor do endereço de email.
     */
    string email;

    /**
     * @brief Valida o formato geral do endereço de email.
     * @details Separa o email em parte local e domínio para validação específica.
     * @param email String contendo o email a ser validado.
     * @throw invalid_argument se o formato geral do email for inválido.
     */
    void validar(const string& email);

    /**
     * @brief Valida a parte local de um endereço de email.
     * @param parteLocal String contendo a parte do email antes do '@'.
     * @throw invalid_argument se a parte local for inválida.
     */
    void validarParteLocal(const string& parteLocal);

    /**
     * @brief Valida a parte do domínio de um endereço de email.
     * @param dominio String contendo a parte do email depois do '@'.
     * @throw invalid_argument se o domínio for inválido.
     */
    void validarDominio(const string& dominio);

public:
    /**
     * @brief Constante que define o tamanho máximo da parte local do email.
     */
    static constexpr int TAMANHO_MAX_LOCAL = 64;

    /**
     * @brief Constante que define o tamanho máximo da parte do domínio do email.
     */
    static constexpr int TAMANHO_MAX_DOMINIO = 255;

    /**
     * @brief Construtor da classe Email.
     * @details Inicializa o objeto com um endereço de email, que é imediatamente validado.
     * @param email O endereço de email a ser definido.
     * @throw invalid_argument Se o email não atender aos critérios de validação.
     */
    Email(const string& email);

    /**
     * @brief Define o valor do email após validá-lo.
     * @param email O endereço de email a ser definido.
     * @throw invalid_argument Se o email não atender aos critérios de validação.
     */
    void setEmail(const string& email);

    /**
     * @brief Retorna o valor do email.
     * @return Uma string contendo o valor atual do email.
     */
    string getEmail() const;
};

/**
 * @brief Implementação inline do método getEmail.
 * @return O valor do atributo 'email' da classe.
 */
inline string Email::getEmail() const {
    return this->email;
}

#endif // EMAIL_HPP_INCLUDED