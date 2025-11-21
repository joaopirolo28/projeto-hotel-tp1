/**
 * @file ServicoQuarto.hpp
 * @brief Declaracao da classe concreta de servico para gerenciamento de Quartos.
 * @author Tarsila Marques
 * @date  20 de novembro de 2025
 */

#ifndef SERVICOQUARTO_HPP
#define SERVICOQUARTO_HPP


#include "interfaces/interfaces.hpp"
#include "servico/IPersistenciaQuarto.hpp"
#include "servico/IPersistenciaHotel.hpp"   
#include "servico/IPersistenciaReserva.hpp"  
#include "entidades/quarto.hpp"
#include "dominios/codigo.hpp"
#include "dominios/numero.hpp"
#include <memory>
#include <vector>

using namespace std;

/**
 * @brief Implementacao concreta da interface IServicoQuarto.
 * @details Responsavel por gerenciar as operacoes CRUD para a entidade Quarto,
 * aplicando regras de consistencia que envolvem as entidades Hotel e Reserva.
 */
class ServicoQuarto : public IServicoQuarto {
private:
    /**
     * @brief Persistencia primaria de Quarto (propriedade).
     */
    unique_ptr<IPersistenciaQuarto> persistenciaQuarto;

    /**
     * @brief Persistencia de Hotel (dependencia), usada para checar se o hotel existe.
     */
    IPersistenciaHotel* persistenciaHotel; 
    
    /**
     * @brief Persistencia de Reserva (dependencia), usada para checar se ha reservas ativas antes de excluir.
     */
    IPersistenciaReserva* persistenciaReserva;

public:
    /**
     * @brief Construtor da classe de servico.
     * @param pQuarto Ponteiro inteligente para a persistencia primaria (Quarto).
     * @param pHotel Ponteiro para a persistencia de Hotel (para checar FK).
     * @param pReserva Ponteiro para a persistencia de Reserva (para checar consistencia).
     */
    ServicoQuarto(unique_ptr<IPersistenciaQuarto> pQuarto, 
                  IPersistenciaHotel* pHotel, 
                  IPersistenciaReserva* pReserva);

   /**
     * @brief Cadastra um novo Quarto no sistema.
     * @param codigoHotel O Codigo do hotel ao qual o quarto pertence.
     * @param quarto O objeto Quarto a ser cadastrado.
     * @return true se o cadastro for bem-sucedido, false caso contrario.
     */
    bool cadastrarQuarto(Codigo codigoHotel, Quarto quarto) override;

    /**
     * @brief Consulta e retorna um Quarto pelo seu Numero.
     * @param numero O Numero do quarto.
     * @return O objeto Quarto encontrado.
     */
    Quarto consultarQuarto(Numero numero) override;

    /**
     * @brief Edita os dados de um Quarto existente.
     * @param quarto O objeto Quarto com os dados a serem atualizados.
     * @return true se a edicao for bem-sucedida, false caso contrario.
     */
    bool editarQuarto(Quarto quarto) override;

    /**
     * @brief Exclui um Quarto pelo seu Numero.
     * @param numero O Numero do Quarto a ser excluido.
     * @return true se a exclusao for bem-sucedida, false caso contrario.
     */
    bool excluirQuarto(Numero numero) override;

    /**
     * @brief Retorna uma lista de todos os Quartos de um Hotel especifico.
     * @param codigoHotel O Codigo do hotel para filtrar os quartos.
     * @return Um vetor (vector) contendo todos os objetos Quarto.
     */
    vector<Quarto> listarQuartos(Codigo codigoHotel) override;
};

#endif // SERVICOQUARTO_HPP_INCLUDED