/**
 * @file ControleHotelImpl.hpp
 * @brief Implementação da interface IControleHotel usando std::list.
 */
#ifndef CONTRLEHOTELIMPL_HPP
#define CONTRLEHOTELIMPL_HPP

#include "conteiner/IControleHotel.hpp"
#include <list>
#include <vector>

using namespace std;

class ControleHotelImpl : public IControleHotel {
private:
    list<Hotel> container;
    void carregarSQLite() { /* Lógica de carga SQLite */ }
    void salvarSQLite() { /* Lógica de salvamento SQLite */ }

public:
    ControleHotelImpl() { carregarSQLite(); }
    virtual ~ControleHotelImpl() { salvarSQLite(); }

    bool incluir(const Hotel& hotel) override;
    bool remover(const Codigo& codigo) override;
    Hotel pesquisar(const Codigo& codigo) override;
    bool atualizar(const Hotel& hotel) override;
    std::vector<Hotel> listarTodos() override;
};

#endif // CONTRLEHOTELIMPL_HPP
