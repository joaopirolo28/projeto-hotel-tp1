/**
 * @file IServicoGerenciamentoContas.hpp
 * @brief Definição da interface para os serviços de CRUD de contas.
 * @author Tarsila Marques
 * @date 15 de novembro de 2025
 */

#ifndef ISERVICOGERENCIAMENTOCONTAS_HPP
#define ISERVICOGERENCIAMENTOCONTAS_HPP

#include <vector>
#include "entidades/gerente.hpp"
#include "entidades/hospede.hpp"

/**
 * @brief Interface que define os serviços de CRUD para Gerentes e Hóspedes.
 */
class IServicoGerenciamentoContas {
public:
    virtual ~IServicoGerenciamentoContas() {}

    // --- Métodos para Gerente ---
    virtual bool cadastrarGerente(Gerente gerente) = 0;
    virtual Gerente consultarGerente(Email email) = 0;
    virtual bool editarGerente(Gerente gerente) = 0;
    virtual bool excluirGerente(Email email) = 0;

    // --- Métodos para Hóspede ---
    virtual bool cadastrarHospede(Hospede hospede) = 0;
    virtual Hospede consultarHospede(Email email) = 0;
    virtual bool editarHospede(Hospede hospede) = 0;
    virtual bool excluirHospede(Email email) = 0;
    virtual std::vector<Hospede> listarHospedes() = 0;
};

#endif // ISERVICOGERENCIAMENTOCONTAS_HPP