/**
 * @file IPersistenciaHotel.hpp
 * @brief Definição da interface de persistência (Contrato) para a entidade Hotel.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */

#ifndef IPERSISTENCIAHOTEL_HPP
#define IPERSISTENCIAHOTEL_HPP

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include <stdexcept>
#include <vector>

/**
 * @brief Interface Abstrata para Persistência de Dados do Hotel.
 * @details Define o contrato CRUD (Criar, Ler, Atualizar, Deletar) para a entidade Hotel.
 * Esta interface é usada pela Camada de Serviço, garantindo Inversão de Dependência
 * e separação entre lógica de negócio e mecanismo de armazenamento.
 */
class IPersistenciaHotel {
public:
    /**
     * @brief Destrutor virtual.
     */
    virtual ~IPersistenciaHotel() = default;

    /**
     * @brief Armazena um novo Hotel no repositório de dados.
     * @param hotel O objeto Hotel a ser persistido.
     * @return true se o cadastro for bem-sucedido, false caso contrário (chave duplicada).
     */
    virtual bool cadastrar(const Hotel& hotel) = 0;

    /**
     * @brief Consulta um Hotel pelo seu código.
     * @param codigo O código do Hotel (chave primária).
     * @return O objeto Hotel se encontrado.
     * @throws std::runtime_error Se o Hotel não for encontrado.
     */
    virtual Hotel consultar(const Codigo& codigo) = 0;

    /**
     * @brief Edita um Hotel existente no repositório.
     * @param hotel O objeto Hotel com dados atualizados.
     * @return true se a edição for bem-sucedida, false caso contrário.
     */
    virtual bool editar(const Hotel& hotel) = 0;

    /**
     * @brief Exclui um Hotel pelo seu código.
     * @param codigo O código do Hotel a ser excluído.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    virtual bool excluir(const Codigo& codigo) = 0;

    /**
     * @brief Retorna uma lista de todos os Hotéis no repositório.
     * @return Um vetor contendo objetos Hotel.
     */
    virtual std::vector<Hotel> listarTodos() = 0;
};

#endif // IPERSISTENCIAHOTEL_HPP
