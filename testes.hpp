#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED
#include "dominios.hpp"
#include "entidades.hpp"

class TUEntidadeHotel{
private:
    const static int VALOR_VALIDO = 1;
    void testarCenario();
    Hotel *hotel;
    void setUp();
    void tearDown();
    int estado;
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

class TUEntidadeQuarto{
private:
    void testaCenarioSucesso();
public:
    bool run();

};

class TUEntidadeReserva{
private:
    void testaCenarioSucesso();
public:
    bool run();
};

class TUEntidadeHospede{
private:
    void testaCenarioSucesso();
public:
    bool run();
};


#endif //TESTES_HPP