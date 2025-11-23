/**
 * @file PersistenciaQuarto.hpp
 * @brief Definicao da classe concreta de persistencia para Quarto.
 * @author Joao Pedro
 * @date 21 de novembro de 2025
 */
#ifndef PERSISTENCIAQUARTO_HPP
#define PERSISTENCIAQUARTO_HPP

#include "interfaces/interfaces.hpp"
#include "entidades/quarto.hpp"
#include "dominios/numero.hpp"
#include "dominios/codigo.hpp"
#include "persistencias/IPersistenciaQuarto.hpp"
#include <sqlite3.h>
#include <vector>

/**
 * @brief Implementacao concreta da interface IPersistenciaQuarto (DAO).
 * @details Responsavel por gerenciar as operacoes CRUD e listagem para a entidade Quarto,
 * utilizando o banco de dados SQLite e a chave composta (CodigoHotel, NumeroQuarto).
 */
class PersistenciaQuarto : public IPersistenciaQuarto {
private:
    /**
     * @brief Ponteiro para o manipulador da conexao SQLite.
     * @details Usado para realizar todas as operacoes SQL no banco de dados.
     */
    sqlite3 *db_connection;

public:
    /**
     * @brief Construtor da classe de persistencia.
     * @details Abre a conexao com o banco de dados e garante que a tabela QUARTOS exista.
     */
    PersistenciaQuarto();
    
    /**
     * @brief Destrutor da classe de persistencia.
     * @details Fecha a conexao ativa com o banco de dados SQLite.
     */
    ~PersistenciaQuarto();

    /**
     * @brief Armazena um novo Quarto no banco de dados.
     * @details A chave estrangeira CodigoHotel e usada para associar o Quarto.
     * @param codigoHotel O Codigo do Hotel ao qual o Quarto pertence.
     * @param quarto O objeto Quarto a ser persistido.
     * @return true se o cadastro for bem-sucedido, false caso contrario (ex: numero duplicado no hotel).
     */
    bool cadastrar(const Codigo& codigoHotel, const Quarto& quarto) override;

    /**
     * @brief Consulta um Quarto pelo Codigo do Hotel e Numero do Quarto.
     * @param codigoHotel O Codigo do Hotel (parte da chave composta).
     * @param numeroQuarto O Numero do Quarto.
     * @return O objeto Quarto se encontrado.
     * @throw runtime_error Se o Quarto nao for encontrado.
     */
    Quarto consultar(const Codigo& codigoHotel, const Numero& numeroQuarto) override;

    /**
     * @brief Edita os dados de um Quarto existente.
     * @param codigoHotel O Codigo do Hotel (chave para localizacao).
     * @param quarto O objeto Quarto com os dados atualizados.
     * @return true se a edicao for bem-sucedida, false caso contrario.
     */
    bool editar(const Codigo& codigoHotel, const Quarto& quarto) override;

    /**
     * @brief Exclui um Quarto pelo Codigo do Hotel e Numero do Quarto.
     * @param codigoHotel O Codigo do Hotel (chave para localizacao).
     * @param numeroQuarto O Numero do Quarto a ser excluido.
     * @return true se a exclusao for bem-sucedida, false caso contrario.
     */
    bool excluir(const Codigo& codigoHotel, const Numero& numeroQuarto) override;
    
    /**
     * @brief Retorna uma lista de todos os Quartos de um Hotel especifico.
     * @param codigoHotel O Codigo do Hotel para filtro.
     * @return Um vetor (vector) de objetos Quarto.
     */
    std::vector<Quarto> listarQuartos(const Codigo& codigoHotel) override;
};

#endif // PERSISTENCIAQUARTO_HPP