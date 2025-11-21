/**
 * @file ServicoHospede.hpp
 * @brief Declaracao da classe concreta de servico para gerenciamento de Hospedes.
 * @author Tarsila Marques
 * @date 15 de novembro de 2025
 */

#ifndef SERVICOHOSPEDE_HPP
#define SERVICOHOSPEDE_HPP

#include "interfaces/IServicoHospede.hpp"
#include "servico/IPersistenciaHospede.hpp"
#include "interfaces/IServicoReservas.hpp" 
#include "entidades/hospede.hpp"
#include "dominios/email.hpp"
#include <memory>
#include <vector>

using namespace std;

/**
 * @brief Implementacao concreta da interface IServicoHospede.
 * @details Responsavel por gerenciar as operacoes CRUD e listagem para a entidade Hospede,
 * delegando o acesso aos dados para a camada de persistencia.
 */
class ServicoHospede : public IServicoHospede {
private:
    /**
     * @brief Ponteiro inteligente (unique_ptr) para a persistencia de Hospede.
     * (Propriedade)
     */
    unique_ptr<IPersistenciaHospede> persistencia;
    
    /**
     * @brief Ponteiro para o servico de Reservas.
     * (Necessario para a regra de negocio: verificar reservas ativas do Hospede).
     */
    IServicoReservas* servicoReservas;

public:
    /**
     * @brief Construtor da classe de servico.
     * @details Recebe a persistencia (propriedade) e o servico de Reservas (referencia) 
     * para injecao de dependencia.
     * @param p Ponteiro inteligente (unique_ptr) para a implementacao de persistencia.
     * @param s Ponteiro para o ServicoReservas (a ser injetado pela Fabrica).
     */
    ServicoHospede(unique_ptr<IPersistenciaHospede> p, IServicoReservas* s);
};

/**
 * @brief Implementacao concreta da interface IServicoHospede.
 * @details Responsavel por gerenciar as operacoes CRUD e listagem para a entidade Hospede,
 * delegando o acesso aos dados para a camada de persistencia.
 */
class ServicoHospede : public IServicoHospede {
private:
    /**
     * @brief Ponteiro para a interface de persistencia de Hospede.
     */
    unique_ptr<IPersistenciaHospede> persistencia;

public:
    /**
     * @brief Construtor da classe de servico.
     * @param p Ponteiro inteligente (unique_ptr) para a implementacao de persistencia.
     */
    ServicoHospede(unique_ptr<IPersistenciaHospede> p);

    /**
     * @brief Cadastra um novo Hospede.
     * @return true se o cadastro for bem-sucedido.
     */
    bool cadastrarHospede(Hospede hospede) override;

    /**
     * @brief Consulta um Hospede pelo email.
     * @return O objeto Hospede se encontrado.
     * @throw runtime_error se nao for encontrado.
     */
    Hospede consultarHospede(Email email) override;

    /**
     * @brief Edita os dados de um Hospede existente.
     * @return true se a edicao for bem-sucedida.
     */
    bool editarHospede(Hospede hospede) override;

    /**
     * @brief Exclui um Hospede.
     * @return true se a exclusao for bem-sucedida.
     */
    bool excluirHospede(Email email) override;

    /**
     * @brief Lista todos os Hospedes cadastrados.
     * @return Vetor contendo todos os Hospedes.
     */
    vector<Hospede> listarHospedes() override;
};

#endif // SERVICOHOSPEDE_HPP
