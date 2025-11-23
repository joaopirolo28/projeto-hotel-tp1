/**
 * @file IPersistenciaReserva.hpp
 * @brief Definição da interface de persistência (Contrato) para a entidade Reserva.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */
#ifndef IPERSISTENCIARESERVA_HPP
#define IPERSISTENCIARESERVA_HPP

#include "dominios/dominios.hpp" // Contém Codigo, Email, Numero
#include "entidades/entidades.hpp" // Contém Reserva
#include <stdexcept>
#include <vector>

using namespace std;

/**
 * @brief Interface Abstrata para Persistência de Dados da Reserva.
 * @details Define o contrato CRUD para a entidade Reserva. Esta interface é usada
 * pelos Serviços para acessar dados, suportando a lógica de negócio
 * de verificação de conflito de datas e consistência de exclusão.
 */
class IPersistenciaReserva {
    public:
        /**
         * @brief Destrutor virtual.
         */
        virtual ~IPersistenciaReserva() {}

        /**
         * @brief Armazena uma nova Reserva no repositório de dados.
         * @param reserva O objeto Reserva a ser persistido.
         * @return true se o cadastro for bem-sucedido, false caso contrário (chave duplicada).
         */
        virtual bool cadastrar(const Reserva& reserva) = 0;

        /**
         * @brief Consulta uma Reserva pelo seu código.
         * @param codigo O código da Reserva (chave primária).
         * @return O objeto Reserva se encontrado.
         * @throw std::runtime_error Se a Reserva não for encontrada.
         */
        virtual Reserva consultar(const Codigo& codigo) = 0;

        /**
         * @brief Edita uma Reserva existente no repositório de dados.
         * @param reserva O objeto Reserva com os dados atualizados.
         * @return true se a edição for bem-sucedida, false caso contrário.
         */
        virtual bool editar(const Reserva& reserva) = 0;

        /**
         * @brief Exclui uma Reserva pelo seu código.
         * @param codigo O código da Reserva a ser excluído.
         * @return true se a exclusão for bem-sucedida, false caso contrário.
         */
        virtual bool excluir(const Codigo& codigo) = 0;

        /**
         * @brief Retorna a lista de Reservas de um hóspede específico.
         * @param emailHospede O Email do Hóspede para filtro.
         * @return Um vetor (vector) de objetos Reserva.
         */
        virtual std::vector<Reserva> listarPorHospede(const Email& emailHospede) = 0;

        /**
         * @brief Lista todas as reservas associadas a um Quarto específico.
         * @details Usado para verificar conflito de datas (lógica de negócio) e consistência na exclusão de Quarto.
         * @param codigoHotel O código do Hotel onde o quarto está.
         * @param numeroQuarto O número do Quarto.
         * @return Um vetor (vector) de objetos Reserva.
         */
        virtual std::vector<Reserva> listarReservasPorQuarto(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;
};

#endif // IPERSISTENCIARESERVA_HPP