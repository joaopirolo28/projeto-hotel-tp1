#ifndef CONTROLEQUARTOIMPL_HPP_INCLUDED
#define CONTROLEQUARTOIMPL_HPP_INCLUDED



#endif // CONTROLEQUARTOIMPL_HPP_INCLUDED
/**
 * @file ControleQuartoImpl.hpp
 * @brief Implementação da interface IControleQuarto usando std::list.
 */
#ifndef CONTRLEQUARTOIMPL_HPP
#define CONTRLEQUARTOIMPL_HPP

#include "conteiner/IControleQuarto.hpp"
#include <list>

using namespace std;

// NOTA: Para simular a persistência, o Contêiner de Quarto precisa de um campo
// para ligar o Quarto ao Hotel. Usaremos uma estrutura interna (ex: tupla)
// ou trataremos o Quarto como identificado pela chave composta no Contêiner.

// Para simplificar o uso do STL, armazenaremos o Quarto em um list, mas a Controladora
// fará o filtro pelo CodigoHotel. Para este Contêiner, manteremos a chave composta
// na lógica dos métodos.
struct QuartoRegistro {
    Codigo codigoHotel;
    Quarto quarto;
};

class ControleQuartoImpl : public IControleQuarto {
private:
    list<QuartoRegistro> container; // Lista de registros (Hotel ID + Quarto)
    void carregarSQLite() { /* Lógica de carga SQLite */ }
    void salvarSQLite() { /* Lógica de salvamento SQLite */ }

public:
    ControleQuartoImpl() { carregarSQLite(); }
    virtual ~ControleQuartoImpl() { salvarSQLite(); }

    bool incluir(const Codigo& codigoHotel, const Quarto& quarto) override;
    bool remover(const Codigo& codigoHotel, const Numero& numeroQuarto) override;
    Quarto pesquisar(const Codigo& codigoHotel, const Numero& numeroQuarto) override;
    bool atualizar(const Codigo& codigoHotel, const Quarto& quarto) override;
    std::vector<Quarto> listarPorHotel(const Codigo& codigoHotel) override;
};

#endif // CONTRLEQUARTOIMPL_HPP
