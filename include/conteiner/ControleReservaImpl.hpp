/**
 * @file ControleReservaImpl.hpp
 * @brief Implementação da interface IControleReserva usando std::list.
 */
#ifndef CONTRLERESERVAIMPL_HPP
#define CONTRLERESERVAIMPL_HPP

#include "conteiner/IControleReserva.hpp"
#include <list>

using namespace std;

class ControleReservaImpl : public IControleReserva {
private:
    list<Reserva> container;
    void carregarSQLite() { /* Lógica de carga SQLite */ }
    void salvarSQLite() { /* Lógica de salvamento SQLite */ }

public:
    ControleReservaImpl() { carregarSQLite(); }
    virtual ~ControleReservaImpl() { salvarSQLite(); }

    bool incluir(const Reserva& reserva) override;
    bool remover(const Codigo& codigo) override;
    Reserva pesquisar(const Codigo& codigo) override;
    bool atualizar(const Reserva& reserva) override;
    std::vector<Reserva> listarPorHospede(const Email& emailHospede) override;
};

#endif // CONTRLERESERVAIMPL_HPP
