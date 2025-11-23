/**
 * @file IControladoraAutenticacao.hpp
 * @brief Interface da Controladora para Autenticação.
 */
#ifndef ICONTROLADORAAUTENTICACAO_HPP
#define ICONTROLADORAAUTENTICACAO_HPP

#include "interfaces/interfaces.hpp"
#include <string>

using namespace std;

/**
 * @brief Interface que define a controladora de Autenticação.
 * @details Responsável por gerenciar as interações de login e cadastro de Gerente.
 */
class IControladoraAutenticacao {
public:
    virtual ~IControladoraAutenticacao() {}

    /**
     * @brief Inicia o fluxo de autenticação (login) ou cadastro de Gerente.
     * @return Retorna o email do Gerente logado ou um email vazio se o login falhar.
     */
    virtual string executar() = 0;
};

#endif // ICONTROLADORAAUTENTICACAO_HPP_INCLUDED
