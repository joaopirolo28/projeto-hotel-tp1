/**
 * @file ServicoAutenticacao.hpp
 * @brief Implementação da interface de Lógica de Negócio para Autenticação.
 */
#ifndef SERVICOAUTENTICACAO_HPP
#define SERVICOAUTENTICACAO_HPP

#include "interfaces/interfaces.hpp"
#include "servico/IPersistenciaGerente.hpp"
#include <memory>

/**
 * @brief Implementação concreta da interface ILNAutenticacao.
 * @details Responsável por aplicar as regras de negócio de autenticação e gestão de Gerentes.
 */
class ServicoAutenticacao : public ILNAutenticacao {
private:
    std::unique_ptr<IPersistenciaGerente> persistencia;

public:
    /**
     * @brief Construtor da classe de serviço.
     * @param p Ponteiro para a implementação de persistência.
     */
    ServicoAutenticacao(std::unique_ptr<IPersistenciaGerente> p);

    bool autenticar(Email email, Senha senha) override;
    bool cadastrarGerente(Gerente gerente) override;
    Gerente consultarGerente(Email email) override;
    bool editarGerente(Gerente gerente) override;
    bool excluirGerente(Email email) override;
};

#endif // SERVICOAUTENTICACAO_HPP
