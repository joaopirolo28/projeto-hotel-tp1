/**
 * @file ServicoHotel.hpp
 * @brief Declaracao da classe concreta de servico para gerenciamento de Hoteis.
 * @author Tarsila Marques
 * @date 21 de novembro de 2025
 */

#ifndef SERVICOHOTEL_HPP
#define SERVICOHOTEL_HPP

#include "interfaces/IServicoHotel.hpp"
#include "servico/IPersistenciaHotel.hpp"
#include "servico/IPersistenciaQuarto.hpp" 
#include "entidades/hotel.hpp"
#include "dominios/codigo.hpp"
#include <memory>
#include <vector>

using namespace std;

/**
 * @brief Implementacao concreta da interface IServicoHotel.
 * @details Responsavel por gerenciar as operacoes CRUD e listagem para a entidade Hotel,
 * aplicando regras de negocio e delegando o acesso aos dados para a camada de persistencia.
 */
class ServicoHotel : public IServicoHotel {
private:
    /**
     * @brief Ponteiro inteligente (unique_ptr) para a persistencia de Hotel.
     * (Persistencia Primaria)
     */
    unique_ptr<IPersistenciaHotel> persistenciaHotel;

    /**
     * @brief Ponteiro inteligente (unique_ptr) para a persistencia de Quarto.
     * (Necessario para a regra de negocio: nao excluir hotel com quartos dependentes).
     */
    unique_ptr<IPersistenciaQuarto> persistenciaQuarto;

public:
    /**
     * @brief Construtor da classe de servico.
     * @param pHotel Ponteiro para a implementacao de persistencia de Hotel.
     * @param pQuarto Ponteiro para a implementacao de persistencia de Quarto.
     */
    ServicoHotel(unique_ptr<IPersistenciaHotel> pHotel, unique_ptr<IPersistenciaQuarto> pQuarto);

    /**
     * @brief Cadastra um novo Hotel no sistema.
     * @details Delega a operacao para a camada de persistencia.
     * @param hotel O objeto Hotel a ser cadastrado.
     * @return true se o cadastro for bem-sucedido, false caso contrario.
     */
    bool cadastrarHotel(Hotel hotel) override;

    /**
     * @brief Consulta e retorna um Hotel pelo seu codigo.
     * @details Chama a persistencia para buscar o registro.
     * @param codigo O Codigo (chave primaria) do hotel.
     * @return O objeto Hotel encontrado.
     * @throw runtime_error Se o Hotel nao for encontrado na base de dados.
     */
    Hotel consultarHotel(Codigo codigo) override;

    /**
     * @brief Edita os dados de um Hotel existente.
     * @details Delega a operacao de atualizacao para a camada de persistencia.
     * @param hotel O objeto Hotel com os dados a serem atualizados.
     * @return true se a edicao for bem-sucedida, false caso contrario.
     */
    bool editarHotel(Hotel hotel) override;

    /**
     * @brief Exclui um Hotel pelo seu codigo.
     * @details Implementa a regra de negocio: verifica se ha quartos ativos antes de excluir (consistencia).
     * @param codigo O Codigo do Hotel a ser excluido.
     * @return true se a exclusao for bem-sucedida, false caso contrario.
     */
    bool excluirHotel(Codigo codigo) override;

    /**
     * @brief Retorna uma lista de todos os Hoteis cadastrados.
     * @return Um vetor (vector) contendo todos os objetos Hotel.
     */
    vector<Hotel> listarHoteis() override;
};

#endif // SERVICOHOTEL_HPP_INCLUDED