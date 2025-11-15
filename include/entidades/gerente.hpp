/**
 * @file Gerente.hpp
 * @brief Definição da classe da entidade Gerente.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "entidades/pessoa.hpp"
#include "dominios/ramal.hpp"
#include "dominios/senha.hpp"

/**
 * @brief Classe entidade que representa um Gerente.
 * @details Herda de Pessoa e adiciona atributos específicos de um gerente,
 * como Ramal e Senha para autenticação no sistema.
 */
class Gerente : public Pessoa {
private:
    /**
     * @brief O ramal telefônico do gerente.
     */
    Ramal ramal;

    /**
     * @brief A senha do gerente para acesso ao sistema.
     */
    Senha senha;

public:
    /**
     * @brief Define o ramal do gerente.
     * @param ramal Um objeto do tipo Ramal.
     */
    void setRamal(Ramal);

    /**
     * @brief Retorna o ramal do gerente.
     * @return Um objeto do tipo Ramal.
     */
    Ramal getRamal() const;

    /**
     * @brief Define a senha do gerente.
     * @param senha Um objeto do tipo Senha.
     */
    void setSenha(Senha);

    /**
     * @brief Retorna a senha do gerente.
     * @return Um objeto do tipo Senha.
     */
    Senha getSenha() const;
};

inline void Gerente::setRamal(Ramal ramal) {
    this->ramal = ramal;
}

inline Ramal Gerente::getRamal() const {
    return ramal;
}

inline void Gerente::setSenha(Senha senha) {
    this->senha = senha;
}

inline Senha Gerente::getSenha() const {
    return senha;
}
#endif // GERENTE_HPP
