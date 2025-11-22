/**
 * @file IControladoraHotel.hpp
 * @brief Definição da interface para a Controladora de Gerenciamento de Hotéis.
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef ICONTROLADORAHOTEL_HPP
#define ICONTROLADORAHOTEL_HPP

#include <string>

/**
 * @brief Interface que define o contrato para a Controladora de Hotéis.
 * @details Esta controladora é responsável por gerenciar o fluxo de interações
 * do usuário (através do console ou GUI) para as operações CRUD (Criar, Ler,
 * Editar, Excluir) da entidade Hotel, conforme o Requisito Funcional 2.
 */
class IControladoraHotel {
public:
    /**
     * @brief Destrutor virtual para garantir a desalocação correta de classes derivadas.
     */
    virtual ~IControladoraHotel() {}

    /**
     * @brief Inicia o fluxo de operações de CRUD de Hotéis.
     * @details Exibe o menu de gerenciamento de hotéis e chama as funções
     * de cadastro, consulta, edição, exclusão e listagem.
     */
    virtual void executar() = 0;
};

#endif // ICONTROLADORAHOTEL_HPP
