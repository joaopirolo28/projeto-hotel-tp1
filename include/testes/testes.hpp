#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED
#include "dominios.hpp"
#include "entidades.hpp"

const static int SUCESSO = 0;
const static int FALHA = -1;

/**
 * @brief Classe de Teste de Unidade para a entidade Hotel.
 */
class TUEntidadeHotel {
private:
    Hotel *hotel;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso(); 

public:
    int run();
};

/**
 * @brief Classe de Teste de Unidade para a entidade Quarto.
 */
class TUEntidadeQuarto {
private:
    Quarto *quarto;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    int run();
};

/**
 * @brief Classe de Teste de Unidade para a entidade Reserva.
 */
class TUEntidadeReserva {
private:
    Reserva *reserva;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    int run();
};

/**
 * @brief Classe de Teste de Unidade para a entidade Hospede.
 */
class TUEntidadeHospede {
private:
    Hospede *hospede;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    int run();
};

#endif //TESTES_HPP