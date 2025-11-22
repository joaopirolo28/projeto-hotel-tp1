#include "persistencias/PersistenciaGerente.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"

#include <stdexcept>
#include <iostream>
#include <sqlite3.h>
#include <cstdlib>
#include <string>

using namespace std;

struct GerenteData {
    Gerente result;
    bool found = false;
};

static int retrieve_gerente_data(void *data, int argc, char **argv, char **azColName) {
    GerenteData *pData = (GerenteData*)data;

    try {
        pData->result.setEmail(Email(argv[0] ? argv[0] : ""));
        pData->result.setNome(Nome(argv[1] ? argv[1] : ""));
        pData->result.setRamal(Ramal(std::stoi(argv[2] ? argv[2] : "0")));
        pData->result.setSenha(Senha(argv[3] ? argv[3] : ""));
        pData->found = true;
    } catch (const invalid_argument&) {
        return 1;
    }
    return 0;
}

PersistenciaGerente::PersistenciaGerente() {
    int rc = sqlite3_open("hotel_database.db", &this->db_connection);
    if (rc != SQLITE_OK) {
        throw runtime_error("Falha ao abrir banco SQLite para Gerente.");
    }
    const char *sql =
        "CREATE TABLE IF NOT EXISTS GERENTES("
        "EMAIL TEXT PRIMARY KEY NOT NULL,"
        "NOME TEXT NOT NULL,"
        "RAMAL TEXT NOT NULL,"
        "SENHA TEXT NOT NULL);";
    sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
}

PersistenciaGerente::~PersistenciaGerente() {
    if (this->db_connection != nullptr) {
        sqlite3_close(this->db_connection);
        this->db_connection = nullptr;
    }
}

bool PersistenciaGerente::cadastrar(const Gerente& gerente) {
    char *sql = sqlite3_mprintf(
        "INSERT INTO GERENTES (EMAIL, NOME, RAMAL, SENHA) "
        "VALUES ('%q', '%q', '%q', '%q');",
        gerente.getEmail().getEmail().c_str(),
        gerente.getNome().getNome().c_str(),
        std::to_string(gerente.getRamal().getValor()).c_str(),
        gerente.getSenha().getSenha().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    // Retorna false se houver violação de chave primária ou outro erro
    if (rc == SQLITE_CONSTRAINT) return false;
    return rc == SQLITE_OK;
}

Gerente PersistenciaGerente::consultar(const Email& email) {
    GerenteData data;
    char *sql = sqlite3_mprintf(
        "SELECT EMAIL, NOME, RAMAL, SENHA FROM GERENTES WHERE EMAIL = '%q';",
        email.getEmail().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, retrieve_gerente_data, &data, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK || !data.found)
        throw runtime_error("Gerente nao encontrado.");
    return data.result;
}
/*
bool PersistenciaGerente::autenticar(const Email& email, const Senha& senha) {
    // Logica para buscar a senha no SQLite e comparar com a senha fornecida
    return true;
}
*/

bool PersistenciaGerente::editar(const Gerente& gerente) {
    char *sql = sqlite3_mprintf(
        "UPDATE GERENTES SET NOME='%q', RAMAL='%q', SENHA='%q' WHERE EMAIL='%q';",
        gerente.getNome().getNome().c_str(),
        std::to_string(gerente.getRamal().getValor()).c_str(),
        gerente.getSenha().getSenha().c_str(),
        gerente.getEmail().getEmail().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    // Verifica se houve linhas afetadas (registro editado)
    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

bool PersistenciaGerente::excluir(const Email& email) {
   char *sql = sqlite3_mprintf(
        "DELETE FROM GERENTES WHERE EMAIL='%q';",
        email.getEmail().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    // Verifica se houve linhas afetadas (registro excluído)
    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

std::vector<Gerente> PersistenciaGerente::listarTodos() {
    // Implementação pendente: Requer callback para lista.
    throw runtime_error("Listar todos os Gerentes nao implementado.");
}
