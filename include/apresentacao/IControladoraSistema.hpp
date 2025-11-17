/**
 * @file IControladoraSistema.hpp
 * @brief Definição da interface da Controladora Principal do Sistema.
 */
#ifndef ICONTROLADORASISTEMA_HPP
#define ICONTROLADORASISTEMA_HPP

#include "interfaces/interfaces.hpp"

/**
 * @brief Interface que define a controladora principal de execução do sistema.
 * @details É responsável por iniciar a aplicação e gerenciar a navegação inicial.
 */
class IControladoraSistema {
public:
    virtual ~IControladoraSistema() {}
    /**
     * @brief Inicia o ciclo de vida da aplicação.
     */
    virtual void executar() = 0;
};

#endif // ICONTROLADORASISTEMA_HPP
