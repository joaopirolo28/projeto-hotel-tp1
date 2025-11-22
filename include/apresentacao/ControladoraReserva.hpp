/**
 * @file ControladoraReserva.hpp
 * @brief Definição da classe concreta para a Controladora de Gerenciamento de Reservas (CRUD).
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef CONTROLADORARESERVA_HPP
#define CONTROLADORARESERVA_HPP

#include "apresentacao/IControladoraReserva.hpp"
#include "interfaces/interfaces.hpp"
#include "entidades/entidades.hpp"

#include <memory>
#include <iostream>
#include <vector>

/**
 * @brief Implementação concreta da interface IControladoraReserva.
 * @details Esta classe é responsável por interagir diretamente com o usuário (via console),
 * coletar dados da Reserva (Código, Datas, Quarto, Hóspede) e chamar os métodos
 * na Camada de Serviço (IServicoReservas) para realizar as operações de CRUD.
 * * Devido à complexidade da Reserva, esta controladora acessa diversos serviços para
 * verificar a disponibilidade de quartos e a existência de hóspedes.
 */
class ControladoraReserva : public IControladoraReserva {
private:
    /**
     * @brief Ponteiro raw para o Serviço de Gerenciamento de Reservas.
     * @details Usado para chamar as operações de negócio (CRUD). A posse pertence a ControladoraGerente.
     */
    IServicoReserva* servicoReserva;

    /**
     * @brief Ponteiro raw para o Serviço de Hotel.
     * @details Usado para consultar informações de Hotéis e Quartos (necessário para a reserva).
     */
    IServicoHotel* servicoHotel;

    /**
     * @brief Ponteiro raw para o Serviço de Hóspede.
     * @details Usado para verificar a existência e consultar o Hóspede (necessário para a reserva).
     */
    IServicoHospede* servicoHospede;


public:
    /**
     * @brief Construtor da ControladoraReserva.
     * @details Implementa a Injeção de Dependência, recebendo as referências para os serviços necessários.
     * @param sReserva Ponteiro raw para o Serviço de Reservas.
     * @param sHotel Ponteiro raw para o Serviço de Hotel (para disponibilidade/preço).
     * @param sHospede Ponteiro raw para o Serviço de Hóspede (para vincular o cliente).
     */
    ControladoraReserva(
        IServicoReserva* sReserva,
        IServicoHotel* sHotel,
        IServicoHospede* sHospede
    );

    /**
     * @brief Destrutor. Não precisa liberar memória, pois a posse dos ponteiros é da ControladoraGerente.
     */
    virtual ~ControladoraReserva() {}


    /**
     * @brief Inicia o fluxo de operações de CRUD de Reservas.
     * @details Exibe o menu de opções (Cadastro, Consulta, Edição, Exclusão, Listagem).
     */
    void executar() override;

private:
    /**
     * @brief Coleta dados (Código, Datas, Quarto, Hóspede) e chama o serviço para criar uma nova Reserva.
     */
    void realizarReserva();

    /**
     * @brief Coleta o Código da Reserva e chama o serviço para consultar e exibir a Reserva.
     */
    void consultarReserva();

    /**
     * @brief Coleta dados atualizados e chama o serviço para editar uma Reserva existente.
     * @details A edição pode incluir mudança de datas ou quarto, exigindo nova verificação de disponibilidade.
     */
    void editarReserva();

    /**
     * @brief Coleta o Código da Reserva e chama o serviço para excluir a Reserva.
     */
    void excluirReserva();

    /**
     * @brief Chama o serviço para listar e exibir todas as Reservas.
     */
    void listarReservas();

    /**
     * @brief Função auxiliar para coletar os dados necessários de uma Reserva (código, datas).
     * @return Um objeto Reserva preenchido com dados básicos.
     */
    Reserva coletarDadosReserva();

    /**
     * @brief Função auxiliar para consultar disponibilidade de quartos para as datas especificadas.
     * @details Interage com o servicoHotel para verificar se há quartos disponíveis.
     */
    void consultarDisponibilidade();
};

#endif // CONTROLADORARESERVA_HPP
