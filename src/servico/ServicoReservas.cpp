#include "servico/ServicoReservas.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;


bool verificaConflito(const Reserva& novaReserva, const Reserva& reservaExistente) {

    Data novaChegada = novaReserva.getChegada();
    Data novaPartida = novaReserva.getPartida();

    Data existenteChegada = reservaExistente.getChegada();
    Data existentePartida = reservaExistente.getPartida();

    bool sobreposicao = (novaChegada <= existentePartida) && (novaPartida >= existenteChegada);

    return sobreposicao;
}

ServicoReservas::ServicoReservas(unique_ptr<IPersistenciaReserva> p)
    : persistencia(std::move(p)) {}

bool ServicoReservas::cadastrarReserva(Reserva reserva) {

    vector<Reserva> reservasExistentes = persistencia->listarReservasPorQuarto(
        reserva.getCodigoHotel(),
        reserva.getNumeroQuarto()
    );

    for (const auto& existente : reservasExistentes) {
        if (verificaConflito(reserva, existente)) {
            throw runtime_error("Erro de Negocio: Conflito de datas com uma reserva existente para este quarto.");
        }
    }
    return persistencia->cadastrar(reserva);
}

Reserva ServicoReservas::consultarReserva(Codigo codigo) {

    try {
        return persistencia->consultar(codigo);
    } catch (const runtime_error& e) {
        throw runtime_error("Reserva nao encontrada para o codigo informado.");
    }
}


bool ServicoReservas::editarReserva(Reserva reserva) {

    vector<Reserva> reservasExistentes = persistencia->listarReservasPorQuarto(
        reserva.getCodigoHotel(), // Primeiro argumento
        reserva.getNumeroQuarto() // Segundo argumento
    );

    for (const auto& existente : reservasExistentes) {
        if (existente.getCodigo().getValor() == reserva.getCodigo().getValor()) {
            continue;
        }
        if (verificaConflito(reserva, existente)) {
            throw runtime_error("Erro de Negocio: A edicao causaria conflito de datas com uma reserva existente.");
        }
    }
    return persistencia->editar(reserva);
}

bool ServicoReservas::excluirReserva(Codigo codigo) {
    return persistencia->excluir(codigo);
}

vector<Reserva> ServicoReservas::listarReservas(Email emailHospede) {
    return persistencia->listarPorHospede(emailHospede);
}
