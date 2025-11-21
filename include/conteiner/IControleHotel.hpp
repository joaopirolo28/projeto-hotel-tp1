/**
 * @file IControleHotel.hpp
 * @brief Definição da interface de controle (Contêiner) para a entidade Hotel.
 */
#ifndef ICONTRLEHOTEL_HPP
#define ICONTRLEHOTEL_HPP

#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>
#include <vector>

class IControleHotel {
public:
    virtual ~IControleHotel() = default;

    /**
     * @brief Inclui um novo Hotel no contêiner.
     * @param hotel Objeto Hotel a ser salvo.
     * @return true se a inclusão for bem-sucedida, false se o Codigo já existir.
     */
    virtual bool incluir(const Hotel& hotel) = 0;

    /**
     * @brief Remove um Hotel pelo Codigo.
     * @param codigo O Codigo do Hotel a ser removido.
     * @return true se a remoção for bem-sucedida, false caso contrário.
     */
    virtual bool remover(const Codigo& codigo) = 0;

    /**
     * @brief Pesquisa um Hotel pelo Codigo.
     * @param codigo O Codigo do Hotel a ser pesquisado.
     * @return O objeto Hotel encontrado.
     * @throw runtime_error se o Hotel não for encontrado.
     */
    virtual Hotel pesquisar(const Codigo& codigo) = 0;

    /**
     * @brief Atualiza os dados de um Hotel existente.
     * @param hotel O objeto Hotel com os dados a serem atualizados.
     * @return true se a atualização for bem-sucedida, false se o Hotel não existir.
     */
    virtual bool atualizar(const Hotel& hotel) = 0;

    /**
     * @brief Retorna uma lista de todos os Hotéis.
     * @return Um vetor de objetos Hotel.
     */
    virtual std::vector<Hotel> listarTodos() = 0;
};

#endif // ICONTRLEHOTEL_HPP
