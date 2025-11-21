// ControleHotelImpl.cpp

#include "conteiner/ControleHotelImpl.hpp"

bool ControleHotelImpl::incluir(const Hotel& hotel) {
    for (const Hotel& elemento : container) {
        if (elemento.getCodigo().getValor() == hotel.getCodigo().getValor()) {
            return false;
        }
    }
    container.push_back(hotel);
    return true;
}

Hotel ControleHotelImpl::pesquisar(const Codigo& codigo) {
    for (const Hotel& elemento : container) {
        if (elemento.getCodigo().getValor() == codigo.getValor()) {
            return elemento;
        }
    }
    throw runtime_error("Hotel nao encontrado.");
}

bool ControleHotelImpl::atualizar(const Hotel& hotel) {
    for (list<Hotel>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getCodigo().getValor() == hotel.getCodigo().getValor()) {
            *it = hotel;
            return true;
        }
    }
    return false;
}

bool ControleHotelImpl::remover(const Codigo& codigo) {
    for (list<Hotel>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            container.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Hotel> ControleHotelImpl::listarTodos() {
    return std::vector<Hotel>(container.begin(), container.end());
}
