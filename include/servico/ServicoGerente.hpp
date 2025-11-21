/**
 * @file ServicoGerente.hpp
 * @brief Declaracao da classe concreta de servico para gerenciamento de Gerente.
 * @author Tarsila Marques
 * @date 15 de novembro de 2025
 */

#ifndef SERVICOGERENTE_HPP
#define SERVICOGERENTE_HPP

// Interfaces que esta classe implementa e usa
#include "interfaces/interfaces.hpp"
#include "servico/IPersistenciaGerente.hpp"

// Classes base e utilitarios
#include "entidades/gerente.hpp"
#include "dominios/email.hpp"
#include <memory>
#include <vector>

using namespace std;

/**
 * @brief Implementacao concreta da interface IServicoGerente.
 * @details Responsavel por gerenciar as operacoes CRUD para a entidade Gerente,
 * aplicando regras de negocio de consistencia e delegando o acesso aos dados
 * para a camada de persistencia.
 */
class ServicoGerente : public IServicoGerente {
private:
    /**
     * @brief Ponteiro inteligente para a interface de persistencia.
     * Usado para acesso ao banco de dados (inversao de dependencia).
     */
    unique_ptr<IPersistenciaGerente> persistencia;

public:
    /**
     * @brief Construtor da classe de servico.
     * @param p Ponteiro inteligente (unique_ptr) para a implementacao de persistencia.
     */
    ServicoGerente(unique_ptr<IPersistenciaGerente> p);

    // --- Metodos do Contrato IServicoGerente ---

    /**
     * @brief Cadastra um novo Gerente.
     * @return true se o cadastro for bem-sucedido.
     */
    bool cadastrarGerente(Gerente gerente) override;

    /**
     * @brief Consulta um Gerente pelo email.
     * @return O objeto Gerente se encontrado.
     * @throw runtime_error se nao for encontrado.
     */
    Gerente consultarGerente(Email email) override;

    /**
     * @brief Edita os dados de um Gerente existente.
     * @return true se a edicao for bem-sucedida.
     */
    bool editarGerente(Gerente gerente) override;

    /**
     * @brief Exclui um Gerente.
     * @return true se a exclusao for bem-sucedida.
     */
    bool excluirGerente(Email email) override;
};

#endif // SERVICOGERENTE_HPP
