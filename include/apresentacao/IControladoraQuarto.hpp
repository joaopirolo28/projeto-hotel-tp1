/**
 * @file IControladoraQuarto.hpp
 * @brief Definição da interface para a Controladora de Gerenciamento de Quartos.
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef ICONTROLADORAQUARTO_HPP
#define ICONTROLADORAQUARTO_HPP

#include <string>

/**
 * @brief Interface que define o contrato para a Controladora de Quartos.
 * @details Esta controladora é responsável por gerenciar o fluxo de interações
 * do usuário (via console) para as operações CRUD da entidade Quarto.
 * As operações de Quarto são dependentes da existência prévia de um Hotel.
 */
class IControladoraQuarto {
public:
    /**
     * @brief Destrutor virtual para garantir a desalocação correta de classes derivadas.
     */
    virtual ~IControladoraQuarto() {}

    /**
     * @brief Inicia o fluxo de operações de CRUD de Quartos.
     * @details Exibe o menu de gerenciamento de quartos e chama as funções
     * de cadastro, consulta, edição, exclusão e listagem, sempre requerendo o
     * código do Hotel para contextualizar a operação.
     */
    virtual void executar() = 0;
};

#endif // ICONTROLADORAQUARTO_HPP
