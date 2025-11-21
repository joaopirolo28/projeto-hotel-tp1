/**
 * @file IControleReserva.hpp
 * @brief Definição da interface de controle (Contêiner) para a entidade Reserva.
 */
#ifndef ICONTRLERESERVA_HPP
#define ICONTRLERESERVA_HPP

#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>
#include <vector>

class IControleReserva {
public:
    virtual ~IControleReserva() = default;

    /**
     * @brief Inclui uma nova Reserva no contêiner.
     * @param reserva Objeto Reserva a ser salvo.
     * @return true se a inclusão for bem-sucedida, false se o Codigo já existir.
     */
    virtual bool incluir(const Reserva& reserva) = 0;

    /**
     * @brief Remove uma Reserva pelo Codigo.
     * @param codigo O Codigo da Reserva a ser removida.
     * @return true se a remoção for bem-sucedida, false caso contrário.
     */
    virtual bool remover(const Codigo& codigo) = 0;

    /**
     * @brief Pesquisa uma Reserva pelo Codigo.
     * @param codigo O Codigo da Reserva a ser pesquisado.
     * @return O objeto Reserva encontrado.
     * @throw runtime_error se a Reserva não for encontrada.
     */
    virtual Reserva pesquisar(const Codigo& codigo) = 0;

    /**
     * @brief Atualiza os dados de uma Reserva existente.
     * @param reserva O objeto Reserva com os dados a serem atualizados.
     * @return true se a atualização for bem-sucedida, false se a Reserva não existir.
     */
    virtual bool atualizar(const Reserva& reserva) = 0;

    /**
     * @brief Retorna a lista de Reservas de um hóspede específico.
     * @param emailHospede Email do Hóspede para filtrar as reservas.
     * @return Um vetor de objetos Reserva.
     */
    virtual std::vector<Reserva> listarPorHospede(const Email& emailHospede) = 0;
};

#endif // ICONTRLERESERVA_HPP
