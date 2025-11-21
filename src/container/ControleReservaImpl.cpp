// ControleReservaImpl.cpp
// OBS: Esta implementação exige que a entidade Reserva tenha um atributo EmailHospede
// ou outra forma de identificar o hóspede. Assumiremos que a Controladora fornece essa informação.

#include "conteiner/ControleReservaImpl.hpp"

bool ControleReservaImpl::incluir(const Reserva& reserva) {
    for (const Reserva& elemento : container) {
        if (elemento.getCodigo().getValor() == reserva.getCodigo().getValor()) {
            return false;
        }
    }
    container.push_back(reserva);
    return true;
}

Reserva ControleReservaImpl::pesquisar(const Codigo& codigo) {
    for (const Reserva& elemento : container) {
        if (elemento.getCodigo().getValor() == codigo.getValor()) {
            return elemento;
        }
    }
    throw runtime_error("Reserva nao encontrada.");
}

bool ControleReservaImpl::atualizar(const Reserva& reserva) {
    for (list<Reserva>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getCodigo().getValor() == reserva.getCodigo().getValor()) {
            *it = reserva;
            return true;
        }
    }
    return false;
}

bool ControleReservaImpl::remover(const Codigo& codigo) {
    for (list<Reserva>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            container.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Reserva> ControleReservaImpl::listarPorHospede(const Email& emailHospede) {
    std::vector<Reserva> lista;
    // TODO: A implementação real aqui depende de como a entidade Reserva
    // armazena a referência ao hóspede (assumiremos que a Controladora fará essa filtragem)
    // Se a Reserva tiver um atributo EmailHospede, o loop seria:
    /*
    for (const Reserva& elemento : container) {
        if (elemento.getEmailHospede().getValor() == emailHospede.getValor()) {
            lista.push_back(elemento);
        }
    }
    */
    return lista;
}
