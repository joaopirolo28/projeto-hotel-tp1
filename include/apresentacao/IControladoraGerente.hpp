/**
 * @file IControladoraGerente.hpp
 * @brief Interface da Controladora para o Menu Principal do Gerente.
 */
#ifndef ICONTROLADORAGERENTE_HPP
#define ICONTROLADORAGERENTE_HPP

#include <string>

/**
 * @brief Interface que define a controladora do menu principal do Gerente.
 * @details Responsável por gerenciar a navegação entre as funcionalidades (CRUDs).
 */
class IControladoraGerente {
public:
    virtual ~IControladoraGerente() {}

    /**
     * @brief Exibe o menu principal e gerencia o fluxo de escolha.
     */
    virtual void executar() = 0;
};

#endif // ICONTROLADORAGERENTE_HPP
