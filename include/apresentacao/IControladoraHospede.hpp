/**
 * @file IControladoraHospede.hpp
 * @brief Definição da interface para a Controladora de Gerenciamento de Hóspedes.
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef ICONTROLADORAHOSPEDE_HPP
#define ICONTROLADORAHOSPEDE_HPP

#include <string>

/**
 * @brief Interface que define o contrato para a Controladora de Hóspedes.
 * @details Esta controladora é responsável por gerenciar o fluxo de interações
 * do usuário (via console) para as operações CRUD (Criar, Ler, Editar, Excluir)
 * da entidade Hóspede, conforme o Requisito Funcional 2.
 */
class IControladoraHospede {
public:
    /**
     * @brief Destrutor virtual para garantir a desalocação correta de classes derivadas.
     */
    virtual ~IControladoraHospede() {}

    /**
     * @brief Inicia o fluxo de operações de CRUD de Hóspedes.
     * @details Exibe o menu de gerenciamento de hóspedes e implementa o loop principal de navegação.
     */
    virtual void executar() = 0;
};

#endif // ICONTROLADORAHOSPEDE_HPP