/**
 * @file ServicoReservas.hpp
 * @brief Declaracao da classe concreta de servico para gerenciamento de Reservas.
 * @author João Pedro
 * @date 20 de novembro de 2025
 */

#ifndef SERVICORESERVAS_HPP
#define SERVICORESERVAS_HPP

#include "interfaces/interfaces.hpp"
#include "servico/IPersistenciaReserva.hpp"

#include "entidades/reserva.hpp"
#include "dominios/email.hpp"
#include "dominios/codigo.hpp"
#include <memory>
#include <vector>

using namespace std;

/**
 * @brief Implementacao concreta da interface IServicoReservas.
 * @details Responsavel por gerenciar as operacoes CRUD para a entidade Reserva,
 * aplicando regras de negocio (como conflito de datas) e delegando o acesso
 * aos dados para a camada de persistencia.
 */
class ServicoReservas : public IServicoReservas {
private:
    /**
     * @brief Ponteiro inteligente para a interface de persistencia.
     * Usado para acesso ao banco de dados (inversao de dependencia).
     */
    unique_ptr<IPersistenciaReserva> persistencia;

public:
    /**
     * @brief Construtor da classe de servico.
     * @param p Ponteiro inteligente (unique_ptr) para a implementacao de persistencia.
     */
    ServicoReservas(unique_ptr<IPersistenciaReserva> p);

    /**
     * @brief Cadastra uma nova reserva.
     * @details Deve verificar se há conflito de datas com outras reservas
     * para o mesmo quarto antes de persistir.
     * @param reserva O objeto Reserva a ser cadastrado.
     * @return true se o cadastro for bem-sucedido.
     * @throw runtime_error Se houver conflito de datas.
     */
    bool cadastrarReserva(Reserva reserva) override;

    /**
     * @brief Consulta uma Reserva pelo código.
     * @param codigo O código da reserva (chave primária).
     * @return O objeto Reserva encontrado.
     * @throw runtime_error Se a reserva não for encontrada.
     */
    Reserva consultarReserva(Codigo codigo) override;

    /**
     * @brief Edita os dados de uma Reserva existente.
     * @details Deve verificar se a edicao resulta em conflito de datas.
     * @param reserva O objeto Reserva com os dados atualizados.
     * @return true se a edicao for bem-sucedida.
     */
    bool editarReserva(Reserva reserva) override;

    /**
     * @brief Exclui uma Reserva pelo código.
     * @param codigo O código da Reserva a ser excluída.
     * @return true se a exclusao for bem-sucedida.
     */
    bool excluirReserva(Codigo codigo) override;

    /**
     * @brief Retorna a lista de todas as reservas de um hóspede específico.
     * @param emailHospede O email do hóspede para filtrar as reservas.
     * @return Um vetor de objetos Reserva.
     */
    vector<Reserva> listarReservas(Email emailHospede) override;
};

#endif // SERVICORESERVAS_HPP
