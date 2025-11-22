/**
 * @file ServicoAutenticacao.hpp
 * @brief Implementação da interface de Lógica de Negócio para Autenticação.
 */
#ifndef SERVICOAUTENTICACAO_HPP
#define SERVICOAUTENTICACAO_HPP

#include "interfaces/interfaces.hpp"
#include "persistencias/IPersistenciaGerente.hpp"
#include <memory>

using namespace std;

/**
 * @brief Implementação concreta da interface ILN Autenticacao.
 * @details Responsável por aplicar as regras de negócio de autenticação e gestão de Gerentes.
 */
class ServicoAutenticacao : public IServicoAutenticacao {
private:
    unique_ptr<IPersistenciaGerente> persistencia;

public:
    /**
     * @brief Construtor da classe de serviço.
     * @param p Ponteiro inteligente (unique_ptr) para a implementação de persistência.
     */
    ServicoAutenticacao(unique_ptr<IPersistenciaGerente> p);

    bool autenticar(Email email, Senha senha) override;
};

#endif // SERVICOAUTENTICACAO_HPP
