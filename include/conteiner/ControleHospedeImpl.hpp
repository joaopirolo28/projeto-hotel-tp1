/**
 * @file ControleHospedeImpl.hpp
 * @brief Implementação da interface IControleHospede usando std::list.
 */
#ifndef CONTRLEHOSPEDEIMPL_HPP
#define CONTRLEHOSPEDEIMPL_HPP

#include "conteiner/IControleHospede.hpp"
#include <list>
#include <algorithm>

using namespace std;

class ControleHospedeImpl : public IControleHospede {
private:
    list<Hospede> container;
    void carregarSQLite() { /* Lógica de carga SQLite */ }
    void salvarSQLite() { /* Lógica de salvamento SQLite */ }

public:
    ControleHospedeImpl() { carregarSQLite(); }
    virtual ~ControleHospedeImpl() { salvarSQLite(); }

    bool incluir(const Hospede& hospede) override;
    bool remover(const Email& email) override;
    Hospede pesquisar(const Email& email) override;
    bool atualizar(const Hospede& hospede) override;
};

#endif // CONTRLEHOSPEDEIMPL_HPP
