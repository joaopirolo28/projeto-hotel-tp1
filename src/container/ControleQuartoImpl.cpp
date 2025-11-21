// ControleQuartoImpl.cpp

#include "conteiner/ControleQuartoImpl.hpp"

bool ControleQuartoImpl::incluir(const Codigo& codigoHotel, const Quarto& quarto) {
    for (const auto& reg : container) {
        // Verifica se a chave composta (CodigoHotel + Numero) já existe
        if (reg.codigoHotel.getValor() == codigoHotel.getValor() &&
            reg.quarto.getNumero().getValor() == quarto.getNumero().getValor()) {
            return false;
        }
    }
    container.push_back({codigoHotel, quarto});
    return true;
}

Quarto ControleQuartoImpl::pesquisar(const Codigo& codigoHotel, const Numero& numeroQuarto) {
    for (const auto& reg : container) {
        if (reg.codigoHotel.getValor() == codigoHotel.getValor() &&
            reg.quarto.getNumero().getValor() == numeroQuarto.getValor()) {
            return reg.quarto;
        }
    }
    throw runtime_error("Quarto nao encontrado.");
}

bool ControleQuartoImpl::atualizar(const Codigo& codigoHotel, const Quarto& quarto) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (it->codigoHotel.getValor() == codigoHotel.getValor() &&
            it->quarto.getNumero().getValor() == quarto.getNumero().getValor()) {
            it->quarto = quarto; // Atualiza o objeto Quarto
            return true;
        }
    }
    return false;
}

bool ControleQuartoImpl::remover(const Codigo& codigoHotel, const Numero& numeroQuarto) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (it->codigoHotel.getValor() == codigoHotel.getValor() &&
            it->quarto.getNumero().getValor() == numeroQuarto.getValor()) {
            container.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Quarto> ControleQuartoImpl::listarPorHotel(const Codigo& codigoHotel) {
    std::vector<Quarto> lista;
    for (const auto& reg : container) {
        if (reg.codigoHotel.getValor() == codigoHotel.getValor()) {
            lista.push_back(reg.quarto);
        }
    }
    return lista;
}
