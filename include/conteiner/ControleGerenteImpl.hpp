/**
 * @file ControleGerenteImpl.hpp
 * @brief Implementação da interface IControleGerente usando std::list.
 */
#ifndef CONTRLEGERENTEIMPL_HPP
#define CONTRLEGERENTEIMPL_HPP

#include "conteiner/IControleGerente.hpp"
#include <list>
#include <algorithm>

using namespace std;

class ControleGerenteImpl : public IControleGerente {
private:
    list<Gerente> container;
    void carregarSQLite();
    void salvarSQLite();

public:

    ControleGerenteImpl();
    virtual ~ControleGerenteImpl();

    bool incluir(const Gerente& gerente) override;
    bool remover(const Email& email) override;
    Gerente pesquisar(const Email& email) override;
    bool atualizar(const Gerente& gerente) override;
};

#endif // CONTRLEGERENTEIMPL_HPP
