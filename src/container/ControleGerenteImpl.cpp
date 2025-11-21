#include "conteiner/ControleGerenteImpl.hpp"
// Incluir aqui a biblioteca SQLite (ex: #include <sqlite3.h>) quando for implementar a persistência real.

// -------------------------------------------------------------------
// Métodos de Persistência (Lógica de Carregar/Salvar SQLite - PENDENTE)
// -------------------------------------------------------------------

ControleGerenteImpl::ControleGerenteImpl() {
    // Ao iniciar, o contêiner deve carregar os dados persistidos (SQLite)
    // carregarSQLite();
}

ControleGerenteImpl::~ControleGerenteImpl() {
    // Ao destruir, o contêiner deve salvar os dados de volta na persistência (SQLite)
    // salvarSQLite();
}

void ControleGerenteImpl::carregarSQLite() {
    // TODO: Implementar a lógica de leitura do banco de dados SQLite para popular 'container'.
    // Esta parte requer a biblioteca SQLite.
}

void ControleGerenteImpl::salvarSQLite() {
    // TODO: Implementar a lógica de escrita do 'container' de volta para o banco de dados SQLite.
    // Esta parte requer a biblioteca SQLite.
}

// -------------------------------------------------------------------
// Métodos CRUD (Implementação STL - CONCLUÍDO)
// -------------------------------------------------------------------

bool ControleGerenteImpl::incluir(const Gerente& gerente) {
    // 1. Verificar se já existe (chave primária: Email)
    for (const Gerente& elemento : container) {
        if (elemento.getEmail().getValor() == gerente.getEmail().getValor()) {
            return false; // Email já cadastrado
        }
    }
    // 2. Incluir no container STL
    container.push_back(gerente);
    return true;
}

Gerente ControleGerenteImpl::pesquisar(const Email& email) {
    // 1. Buscar o Gerente pelo Email
    for (const Gerente& elemento : container) {
        if (elemento.getEmail().getValor() == email.getValor()) {
            return elemento; // Encontrado
        }
    }
    // 2. Se não encontrado, lançar exceção
    throw runtime_error("Gerente nao encontrado no sistema.");
}

bool ControleGerenteImpl::atualizar(const Gerente& gerente) {
    // 1. Encontrar o Gerente a ser atualizado
    for (list<Gerente>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getEmail().getValor() == gerente.getEmail().getValor()) {
            *it = gerente; // Sobrescreve o objeto
            return true;
        }
    }
    return false; // Gerente não encontrado
}

bool ControleGerenteImpl::remover(const Email& email) {
    // 1. Encontrar e remover o elemento
    for (list<Gerente>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getEmail().getValor() == email.getValor()) {
            container.erase(it);
            return true; // Removido com sucesso
        }
    }
    return false; // Gerente não encontrado
}
// Incluir aqui a biblioteca SQLite (ex: #include <sqlite3.h>) quando for implementar a persistência real.

// -------------------------------------------------------------------
// Métodos de Persistência (Lógica de Carregar/Salvar SQLite - PENDENTE)
// -------------------------------------------------------------------

ControleGerenteImpl::ControleGerenteImpl() {
    // Ao iniciar, o contêiner deve carregar os dados persistidos (SQLite)
    // carregarSQLite();
}

ControleGerenteImpl::~ControleGerenteImpl() {
    // Ao destruir, o contêiner deve salvar os dados de volta na persistência (SQLite)
    // salvarSQLite();
}

void ControleGerenteImpl::carregarSQLite() {
    // TODO: Implementar a lógica de leitura do banco de dados SQLite para popular 'container'.
    // Esta parte requer a biblioteca SQLite.
}

void ControleGerenteImpl::salvarSQLite() {
    // TODO: Implementar a lógica de escrita do 'container' de volta para o banco de dados SQLite.
    // Esta parte requer a biblioteca SQLite.
}

// -------------------------------------------------------------------
// Métodos CRUD (Implementação STL - CONCLUÍDO)
// -------------------------------------------------------------------

bool ControleGerenteImpl::incluir(const Gerente& gerente) {
    // 1. Verificar se já existe (chave primária: Email)
    for (const Gerente& elemento : container) {
        if (elemento.getEmail().getValor() == gerente.getEmail().getValor()) {
            return false; // Email já cadastrado
        }
    }
    // 2. Incluir no container STL
    container.push_back(gerente);
    return true;
}

Gerente ControleGerenteImpl::pesquisar(const Email& email) {
    // 1. Buscar o Gerente pelo Email
    for (const Gerente& elemento : container) {
        if (elemento.getEmail().getValor() == email.getValor()) {
            return elemento; // Encontrado
        }
    }
    // 2. Se não encontrado, lançar exceção
    throw runtime_error("Gerente nao encontrado no sistema.");
}

bool ControleGerenteImpl::atualizar(const Gerente& gerente) {
    // 1. Encontrar o Gerente a ser atualizado
    for (list<Gerente>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getEmail().getValor() == gerente.getEmail().getValor()) {
            *it = gerente; // Sobrescreve o objeto
            return true;
        }
    }
    return false; // Gerente não encontrado
}

bool ControleGerenteImpl::remover(const Email& email) {
    // 1. Encontrar e remover o elemento
    for (list<Gerente>::iterator it = container.begin(); it != container.end(); ++it) {
        if (it->getEmail().getValor() == email.getValor()) {
            container.erase(it);
            return true; // Removido com sucesso
        }
    }
    return false; // Gerente não encontrado
}
