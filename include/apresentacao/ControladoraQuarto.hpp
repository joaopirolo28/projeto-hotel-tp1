/**
 * @file ControladoraQuarto.hpp
 * @brief Definição da classe concreta para a Controladora de Gerenciamento de Quartos (CRUD).
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef CONTROLADORAQUARTO_HPP
#define CONTROLADORAQUARTO_HPP

#include "apresentacao/IControladoraQuarto.hpp"
#include "interfaces/interfaces.hpp"
#include "entidades/entidades.hpp"
#include <memory>
#include <iostream>

/**
 * @brief Implementação concreta da interface IControladoraQuarto.
 * @details Esta classe é responsável por interagir diretamente com o usuário
 * (via console), coletar dados de entrada, incluindo o Código do Hotel,
 * validar o formato usando Domínios, e chamar os métodos correspondentes
 * na Camada de Serviço (IServicoQuarto) para realizar as operações de CRUD.
 */
class ControladoraQuarto : public IControladoraQuarto {
private:
    /**
     * @brief Ponteiro para o Serviço de Gerenciamento de Quartos.
     * @details Usado para chamar as operações de negócio (CRUD).
     */
    IServicoQuarto* servicoQuarto;

public:
    /**
     * @brief Construtor da ControladoraQuarto.
     * @details Implementa a Injeção de Dependência, recebendo o serviço
     * de Quartos.
     * @param sQuarto Ponteiro para o Serviço de Quartos.
     */
    ControladoraQuarto(IServicoQuarto* sQuarto);

    /**
     * @brief Inicia o fluxo de operações de CRUD de Quartos.
     * @details Exibe o menu de opções (Cadastro, Consulta, Edição, Exclusão, Listagem).
     */
    void executar() override;

private:
    /**
     * @brief Coleta dados (incluindo o Código do Hotel) e chama o serviço para cadastrar um novo Quarto.
     */
    void cadastrarQuarto();

    /**
     * @brief Coleta o código do Hotel e o número do Quarto e chama o serviço para consultar e exibir o Quarto.
     */
    void consultarQuarto();

    /**
     * @brief Coleta dados (incluindo o Código do Hotel) e chama o serviço para editar um Quarto existente.
     */
    void editarQuarto();

    /**
     * @brief Coleta o código do Hotel e o número do Quarto e chama o serviço para excluir o Quarto.
     */
    void excluirQuarto();

    /**
     * @brief Coleta o código do Hotel e chama o serviço para listar e exibir todos os Quartos do Hotel.
     */
    void listarQuartos();

    /**
     * @brief Função auxiliar para coletar os dados básicos de um Quarto 
     * (Número, Capacidade, Diária, Ramal).
     * @return Um objeto Quarto preenchido.
     * @throw invalid_argument Se o formato de algum Domínio for inválido.
     */
    Quarto coletarDadosQuarto();
};

#endif // CONTROLADORAQUARTO_HPP
