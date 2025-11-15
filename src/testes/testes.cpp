#include "testes.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void TUEntidadeHotel::setUp() {
    hotel = new Hotel(); 
    estado = SUCESSO; 
}

void TUEntidadeHotel::tearDown() {
    
    delete hotel;
}

void TUEntidadeHotel::testarCenarioSucesso() {
    
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;

    try {
       
        nome = Nome("Hotel Palace");
        endereco = Endereco("Rua B, 45");
        telefone = Telefone("+5511999998888");
        codigo = Codigo("HOTEL12345");
    } catch (const invalid_argument& e) {
        estado = FALHA;
        return; 
    }

    
    hotel->setNome(nome);
    hotel->setEndereco(endereco);
    hotel->setTelefone(telefone);
    hotel->setCodigo(codigo);

    
    if (hotel->getNome().getNome() != "Hotel Palace") estado = FALHA;
    if (hotel->getEndereco().getEndereco() != "Rua B, 45") estado = FALHA;
    if (hotel->getTelefone().getValor() != "+5511999998888") estado = FALHA;
    if (hotel->getCodigo().getValor() != "HOTEL12345") estado = FALHA;
}

int TUEntidadeHotel::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}



void TUEntidadeQuarto::setUp() {
    quarto = new Quarto();
    estado = SUCESSO;
}

void TUEntidadeQuarto::tearDown() {
    delete quarto;
}

void TUEntidadeQuarto::testarCenarioSucesso() {
   
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria;
    Ramal ramal;

    try {
        numero = Numero(101);
        capacidade = Capacidade(2);
        diaria = Dinheiro(250.50);
        ramal = Ramal(22);
    } catch (const invalid_argument& e) {
        estado = FALHA;
        return;
    }

   
    quarto->setNumero(numero);
    quarto->setCapacidade(capacidade);
    quarto->setDiaria(diaria);
    quarto->setRamal(ramal);

   
    if (quarto->getNumero().getValor() != 101) estado = FALHA;
    if (quarto->getCapacidade().getValor() != 2) estado = FALHA;
    if (quarto->getDiaria().getValor() != 250.50) estado = FALHA;
    if (quarto->getRamal().getValor() != 22) estado = FALHA;
}

int TUEntidadeQuarto::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}


void TUEntidadeReserva::setUp() {
    reserva = new Reserva();
    estado = SUCESSO;
}

void TUEntidadeReserva::tearDown() {
    delete reserva;
}

void TUEntidadeReserva::testarCenarioSucesso() {
    
    Codigo codigo;
    Data chegada;
    Data partida;
    Dinheiro valor;

    try {
        codigo = Codigo("RESERVA001");
        chegada = Data(10, "NOV", 2025); 
        partida = Data(15, "NOV", 2025);
        valor = Dinheiro(1250.00);
    } catch (const invalid_argument& e) {
        estado = FALHA;
        return;
    }

    
    reserva->setCodigo(codigo);
    reserva->setChegada(chegada);
    reserva->setPartida(partida);
    reserva->setValor(valor);


    if (reserva->getCodigo().getValor() != "RESERVA001") estado = FALHA;

    if (reserva->getChegada().getDia() != 10) estado = FALHA;
    if (reserva->getChegada().getMes() != "NOV") estado = FALHA;
    if (reserva->getChegada().getAno() != 2025) estado = FALHA;

    if (reserva->getPartida().getDia() != 15) estado = FALHA;
    if (reserva->getPartida().getMes() != "NOV") estado = FALHA;
    if (reserva->getPartida().getAno() != 2025) estado = FALHA;

    if (reserva->getValor().getValor() != 1250.00) estado = FALHA;
}

int TUEntidadeReserva::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}


void TUEntidadeHospede::setUp() {
    hospede = new Hospede();
    estado = SUCESSO;
}

void TUEntidadeHospede::tearDown() {
    delete hospede;
}

void TUEntidadeHospede::testarCenarioSucesso() {
    
    Nome nome;
    Email email;
    Endereco endereco;
    Cartao cartao;

    try {
        nome = Nome("Joao Silva");
        email = Email("joao.silva@email.com");
        endereco = Endereco("Rua C, 789");
        cartao = Cartao("4992739871692345"); 
    } catch (const invalid_argument& e) {
        estado = FALHA;
        return;
    }

    
    hospede->setNome(nome);
    hospede->setEmail(email);
    hospede->setEndereco(endereco);
    hospede->setCartao(cartao);

    
    if (hospede->getNome().getNome() != "Joao Silva") estado = FALHA;
    if (hospede->getEmail().getEmail() != "joao.silva@email.com") estado = FALHA;
    if (hospede->getEndereco().getEndereco() != "Rua C, 789") estado = FALHA;
    if (hospede->getCartao().getValor() != "4992739871692345") estado = FALHA;
}

int TUEntidadeHospede::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}