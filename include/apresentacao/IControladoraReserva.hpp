/**
 * @file IControladoraReserva.hpp
 * @brief Definição da interface para a Controladora de Gerenciamento de Reservas.
 * @details Este módulo é responsável por todas as operações de CRUD, incluindo a
 * validação de datas e a consulta de disponibilidade.
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef ICONTROLADORARESERVA_HPP
#define ICONTROLADORARESERVA_HPP

#include <string>

/**
 * @brief Interface que define o contrato para a Controladora de Reservas.
 * @details Esta controladora gerencia o fluxo de interações do usuário (via console)
 * para as operações CRUD (Criar, Ler, Editar, Excluir) da entidade Reserva,
 * conforme o Requisito Funcional 2. As operações exigem a interação com Hóspedes,
 * Quartos e Datas.
 */
class IControladoraReserva {
public:
    /**
     * @brief Destrutor virtual para garantir a desalocação correta de classes derivadas.
     */
    virtual ~IControladoraReserva() = default;

    /**
     * @brief Inicia o fluxo de operações de CRUD de Reservas.
     * @details Exibe o menu de gerenciamento de reservas e chama as funções
     * de cadastro, consulta, edição, exclusão e listagem.
     */
    virtual void executar() = 0;
};

#endif // ICONTROLADORARESERVA_HPP
