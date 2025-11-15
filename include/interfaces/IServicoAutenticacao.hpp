/**
 * @file IServicoAutenticacao.hpp
 * @brief Definição da interface para os serviços de autenticação.
 * @author Tarsila Marques
 * @date 15 de novembro de 2025
 */

#ifndef ISERVICOAUTENTICACAO_HPP
#define ISERVICOAUTENTICACAO_HPP

#include "dominios/email.hpp"
#include "dominios/senha.hpp"

/**
 * @brief Interface que define os serviços de autenticação e cadastro de gerente.
 */
class IServicoAutenticacao {
public:
    virtual ~IServicoAutenticacao() {}

    /**
     * @brief Autentica um gerente no sistema.
     * @param email O email do gerente.
     * @param senha A senha do gerente.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    virtual bool autenticar(Email email, Senha senha) = 0;

    // (O cadastro de Gerente está aqui, pois é parte do fluxo de "criar conta")
};

#endif // ISERVICOAUTENTICACAO_HPP