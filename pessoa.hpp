/**
 * @file Pessoa.hpp
 * @brief Definição da classe base da entidade Pessoa.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "nome.hpp"
#include "email.hpp"

/**
 * @brief Classe base que representa uma Pessoa.
 * @details Esta classe serve como alicerce para outras entidades como Gerente e Hóspede,
 * contendo atributos comuns a ambos, como nome e email. Os atributos são protegidos
 * para permitir o acesso direto por classes derivadas.
 */
class Pessoa {
protected:
    /**
     * @brief O nome da pessoa.
     */
    Nome nome;

    /**
     * @brief O endereço de email da pessoa.
     */
    Email email;

public:
    /**
     * @brief Define o nome da pessoa.
     * @param nome Um objeto do tipo Nome.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome da pessoa.
     * @return Um objeto do tipo Nome.
     */
    Nome getNome() const;

    /**
     * @brief Define o email da pessoa.
     * @param email Um objeto do tipo Email.
     */
    void setEmail(const Email& email);

    /**
     * @brief Retorna o email da pessoa.
     * @return Um objeto do tipo Email.
     */
    Email getEmail() const;
};

#endif // PESSOA_HPP