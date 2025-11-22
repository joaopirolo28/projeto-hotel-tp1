/**
 * @file ControladoraHospede.hpp
 * @brief Definição da classe concreta para a Controladora de Gerenciamento de Hóspedes (CRUD).
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef CONTROLADORAHOSPEDE_HPP
#define CONTROLADORAHOSPEDE_HPP

#include "apresentacao/IControladoraHospede.hpp"
#include "interfaces/interfaces.hpp"
#include "entidades/entidades.hpp"
#include <memory>
#include <iostream>
#include <vector>

/**
 * @brief Implementação concreta da interface IControladoraHospede.
 * @details Esta classe é responsável por interagir diretamente com o usuário
 * (via console), coletar dados do Hóspede (Nome, Endereço, Cartão, Email),
 * validar o formato usando Domínios e chamar os métodos correspondentes
 * na Camada de Serviço (IServicoHospede) para realizar as operações de CRUD.
 */
class ControladoraHospede : public IControladoraHospede {
private:
    /**
     * @brief Ponteiro inteligente para o Serviço de Gerenciamento de Hóspedes.
     * @details Usado para chamar as operações de negócio (CRUD).
     */
    IServicoHospede* servicoHospede;

public:
    /**
     * @brief Construtor da ControladoraHospede.
     * @details Implementa a Injeção de Dependência, recebendo a posse do serviço
     * de Hóspedes.
     * @param sHospede Ponteiro inteligente para o Serviço de Hóspedes (posse é movida).
     */
    ControladoraHospede(IServicoHospede* sHospede);

    /**
     * @brief Inicia o fluxo de operações de CRUD de Hóspedes.
     * @details Exibe o menu de opções (Cadastro, Consulta, Edição, Exclusão, Listagem).
     */
    void executar() override;

private:
    /**
     * @brief Coleta dados (Nome, Endereço, Cartão, Email) e chama o serviço para cadastrar um novo Hóspede.
     */
    void cadastrarHospede();

    /**
     * @brief Coleta o Email do Hóspede e chama o serviço para consultar e exibir o Hóspede.
     */
    void consultarHospede();

    /**
     * @brief Coleta dados atualizados e chama o serviço para editar um Hóspede existente.
     */
    void editarHospede();

    /**
     * @brief Coleta o Email do Hóspede e chama o serviço para excluir o Hóspede.
     * @details A exclusão deve ser verificada pelo serviço para garantir que não existam Reservas ativas.
     */
    void excluirHospede();

    /**
     * @brief Chama o serviço para listar e exibir todos os Hóspedes cadastrados.
     */
    void listarHospedes();

    /**
     * @brief Função auxiliar para coletar todos os dados necessários de um Hóspede.
     * @return Um objeto Hospede preenchido.
     * @throw std::invalid_argument Se o formato de algum Domínio (Email, Nome, Cartão, Endereço) for inválido.
     */
    Hospede coletarDadosHospede();
};

#endif // CONTROLADORAHOSPEDE_HPP
