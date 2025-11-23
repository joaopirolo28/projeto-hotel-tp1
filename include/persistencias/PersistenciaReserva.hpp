/**
 * @file PersistenciaReserva.hpp
 * @brief Definição da classe concreta de persistência para Reserva.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */
#ifndef PERSISTENCIARESERVA_HPP
#define PERSISTENCIARESERVA_HPP

#include "interfaces/interfaces.hpp"
#include "persistencias/IPersistenciaReserva.hpp"
#include "entidades/reserva.hpp"
#include "dominios/data.hpp"
#include "dominios/codigo.hpp"
#include "dominios/email.hpp"
#include "dominios/numero.hpp"
#include <sqlite3.h>
#include <vector>

using namespace std;

/**
 * @brief Implementação concreta da interface IPersistenciaReserva (DAO).
 * @details Responsável por mapear e manipular os dados da entidade Reserva
 * no banco de dados SQLite. Esta classe implementa o acesso aos dados necessário
 * para a lógica de negócio (ex: checagem de conflito de datas).
 */
class PersistenciaReserva : public IPersistenciaReserva {
private:
    /**
     * @brief Ponteiro para o manipulador da conexão SQLite.
     * @details Usado para realizar todas as operações SQL no banco de dados.
     */
    sqlite3 *db_connection;

public:
    /**
     * @brief Construtor da classe de persistência.
     * @details Abre a conexão com o banco de dados e garante que a tabela RESERVAS exista.
     */
    PersistenciaReserva();

    /**
     * @brief Destrutor da classe de persistência.
     * @details Fecha a conexão ativa com o banco de dados SQLite.
     */
    ~PersistenciaReserva();

    /**
     * @brief Armazena uma nova Reserva no banco de dados.
     * @param reserva O objeto Reserva a ser persistido.
     * @return true se o cadastro for bem-sucedido, false caso contrário (chave duplicada).
     */
    bool cadastrar(const Reserva& reserva) override;

    /**
     * @brief Consulta uma Reserva pelo seu código.
     * @param codigo O código da Reserva (chave primária).
     * @return O objeto Reserva se encontrado.
     * @throw std::runtime_error Se a Reserva não for encontrada.
     */
    Reserva consultar(const Codigo& codigo) override;

    /**
     * @brief Edita uma Reserva existente no repositório de dados.
     * @param reserva O objeto Reserva com os dados atualizados.
     * @return true se a edição for bem-sucedida, false caso contrário.
     */
    bool editar(const Reserva& reserva) override;

    /**
     * @brief Exclui uma Reserva pelo seu código.
     * @param codigo O código da Reserva a ser excluído.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluir(const Codigo& codigo) override;

    /**
     * @brief Retorna a lista de Reservas de um hóspede específico.
     * @param emailHospede O Email do Hóspede para filtro.
     * @return Um vetor (vector) de objetos Reserva.
     */
    std::vector<Reserva> listarPorHospede(const Email& emailHospede) override;

    /**
     * @brief Lista todas as reservas associadas a um Quarto específico.
     * @details Usado pela Camada de Serviço para checar conflito de datas e consistência.
     * @param codigoHotel O código do Hotel onde o quarto está.
     * @param numeroQuarto O número do Quarto.
     * @return Um vetor (vector) de objetos Reserva.
     */
    std::vector<Reserva> listarReservasPorQuarto(const Codigo& codigoHotel, const Numero& numeroQuarto) override;
};

#endif // PERSISTENCIARESERVA_HPP