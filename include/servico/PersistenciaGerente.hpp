/**
 * @file PersistenciaGerente.hpp
 * @brief Definição da classe concreta de persistência para Gerente.
 */
#ifndef PERSISTENCIAGERENTE_HPP
#define PERSISTENCIAGERENTE_HPP

#include "servico/IPersistenciaGerente.hpp"
#include <string>

/**
 * @brief Implementação concreta da interface IPersistenciaGerente.
 * @details Responsável por mapear e manipular os dados da entidade Gerente
 * no banco de dados SQLite.
 */
class PersistenciaGerente : public IPersistenciaGerente {
public:
    PersistenciaGerente();

    bool cadastrar(const Gerente& gerente) override;
    Gerente consultar(const Email& email) override;
    bool autenticar(const Email& email, const Senha& senha) override;
    bool editar(const Gerente& gerente) override;
    bool excluir(const Email& email) override;
};

#endif // PERSISTENCIAGERENTE_HPP
