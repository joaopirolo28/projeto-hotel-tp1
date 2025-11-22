/**
 * @file ControladoraHotel.hpp
 * @brief Definição da classe concreta para a Controladora de Gerenciamento de Hotéis (CRUD).
 * @author João Pedro
 * @date 22/11/2025
 */

#ifndef CONTROLADORAHOTEL_HPP
#define CONTROLADORAHOTEL_HPP

#include "apresentacao/IControladoraHotel.hpp"
#include "interfaces/interfaces.hpp"
#include "entidades/entidades.hpp"
#include <memory>
#include <iostream>

/**
 * @brief Implementação concreta da interface IControladoraHotel.
 * @details Esta classe é responsável por interagir diretamente com o usuário
 * (via console), coletar dados de entrada, validar o formato usando Domínios,
 * e chamar os métodos correspondentes na Camada de Serviço (IServicoHotel)
 * para realizar as operações de CRUD.
 */
class ControladoraHotel : public IControladoraHotel {
private:
    /**
     * @brief Ponteiro inteligente para o Serviço de Gerenciamento de Hotéis.
     * @details Usado para chamar as operações de negócio (CRUD).
     */
    IServicoHotel* servicoHotel;

public:
    /**
     * @brief Construtor da ControladoraHotel.
     * @details Implementa a Injeção de Dependência, recebendo a posse do serviço
     * de Hotéis.
     * @param sHotel Ponteiro inteligente para o Serviço de Hotéis (posse é movida).
     */
    ControladoraHotel(IServicoHotel* sHotel);

    /**
     * @brief Inicia o fluxo de operações de CRUD de Hotéis.
     * @details Exibe o menu de opções (Cadastro, Consulta, Edição, Exclusão, Listagem).
     */
    void executar() override;

private:
    /**
     * @brief Coleta dados e chama o serviço para cadastrar um novo Hotel.
     */
    void cadastrarHotel();

    /**
     * @brief Coleta o código do hotel e chama o serviço para consultar e exibir o Hotel.
     */
    void consultarHotel();

    /**
     * @brief Coleta dados e chama o serviço para editar um Hotel existente.
     */
    void editarHotel();

    /**
     * @brief Coleta o código do hotel e chama o serviço para excluir o Hotel.
     */
    void excluirHotel();

    /**
     * @brief Chama o serviço para listar e exibir todos os Hotéis cadastrados.
     */
    void listarHoteis();

    /**
     * @brief Função auxiliar para coletar todos os dados de um Hotel (Nome, Endereço, Telefone, Código).
     * @return Um objeto Hotel preenchido.
     * @throw std::invalid_argument Se o formato de algum Domínio for inválido.
     */
    Hotel coletarDadosHotel();
};

#endif // CONTROLADORAHOTEL_HPP
