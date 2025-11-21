// ControleHospedeImpl.cpp

#include "conteiner/ControleHospedeImpl.hpp"

bool ControleHospedeImpl::incluir(const Hospede& hospede) {
    for (const Hospede& elemento : container) {
        if (elemento.getEmail().getValor() == hospede.getEmail().getValor()) {
            return false;
        }
    }
    container.push_back(hospede);
    return true;
}

Hospede ControleHospedeImpl::pesquisar(const Email& email) {
    for (const Hospede& elemento : container) {
        if (elemento.getEmail().getValor() == email.getValor()) {
            return elemento;
        }
    }
    throw runtime_error("Hospede nao encontrado.");
}

bool ControleHospedeImpl::atualizar(const Hospede& hospede) {
    for (list<Hospede>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getEmail().getValor() == hospede.getEmail().getValor()) {
            *it = hospede;
            return true;
        }
    }
    return false;
}

bool ControleHospedeImpl::remover(const Email& email) {
    for (list<Hospede>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getEmail().getValor() == email.getValor()) {
            container.erase(it);
            return true;
        }
    }
    return false;
}
