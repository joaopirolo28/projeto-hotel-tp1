#include "persistencias/PersistenciaHospede.hpp"
#include "entidades/hospede.hpp" 
#include "dominios/email.hpp"
#include "dominios/nome.hpp" 
#include "dominios/endereco.hpp" 
#include "dominios/cartao.hpp" 

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sqlite3.h>

using namespace std;

static sqlite3 *db_connection = nullptr;


struct HospedeData {
    Hospede result;
    bool found = false;
};

static int retrieve_hospede_data(void *data, int argc, char **argv, char **azColName) {
    HospedeData *pData = (HospedeData*)data;

    try {
        pData->result.setEmail(Email(argv[0] ? argv[0] : ""));
        pData->result.setNome(Nome(argv[1] ? argv[1] : ""));
        pData->result.setEndereco(Endereco(argv[2] ? argv[2] : ""));
        pData->result.setCartao(Cartao(argv[3] ? argv[3] : ""));

        pData->found = true;

    } catch (const invalid_argument&) {
        return 1;  
    }

    return 0;
}


PersistenciaHospede::PersistenciaHospede() {
    int rc = sqlite3_open("hotel_database.db", &db_connection);
    if (rc != SQLITE_OK) {
        throw runtime_error("Falha ao abrir banco SQLite.");
    }

    const char *sql =
        "CREATE TABLE IF NOT EXISTS HOSPEDES("
        "EMAIL TEXT PRIMARY KEY NOT NULL,"
        "NOME TEXT NOT NULL,"
        "ENDERECO TEXT NOT NULL,"
        "CARTAO TEXT NOT NULL);";

    sqlite3_exec(db_connection, sql, nullptr, nullptr, nullptr);
}


PersistenciaHospede::~PersistenciaHospede() {
    if (db_connection != nullptr) {
        sqlite3_close(db_connection);
        db_connection = nullptr;
    }
}

// Callback para listar todos os hospedes
static int listar_hospedes_callback(void *data, int argc, char **argv, char **azColName) {
    vector<Hospede> *lista = reinterpret_cast<vector<Hospede>*>(data);
    Hospede h;

    try {
        h.setEmail(Email(argv[0] ? argv[0] : ""));
        h.setNome(Nome(argv[1] ? argv[1] : ""));
        h.setEndereco(Endereco(argv[2] ? argv[2] : ""));
        h.setCartao(Cartao(argv[3] ? argv[3] : ""));
    } catch (const invalid_argument&) {
        return 1;
    }

    lista->push_back(h);
    return 0;
}

bool PersistenciaHospede::cadastrar(const Hospede& hospede) {
    char *sql = sqlite3_mprintf(
        "INSERT INTO HOSPEDES (EMAIL, NOME, ENDERECO, CARTAO) "
        "VALUES ('%q', '%q', '%q', '%q');",
        hospede.getEmail().getEmail().c_str(),
        hospede.getNome().getNome().c_str(),
        hospede.getEndereco().getEndereco().c_str(),
        hospede.getCartao().getValor().c_str()
    );

    int rc = sqlite3_exec(db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    if (rc == SQLITE_CONSTRAINT) return false;
    return rc == SQLITE_OK;
}


Hospede PersistenciaHospede::consultar(const Email& email) {
    HospedeData data;

    char *sql = sqlite3_mprintf(
        "SELECT EMAIL, NOME, ENDERECO, CARTAO FROM HOSPEDES WHERE EMAIL = '%q';",
        email.getEmail().c_str()
    );

    int rc = sqlite3_exec(db_connection, sql, retrieve_hospede_data, &data, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK || !data.found)
        throw runtime_error("Hospede nao encontrado.");

    return data.result;
}


bool PersistenciaHospede::editar(const Hospede& hospede) {
    char *sql = sqlite3_mprintf(
        "UPDATE HOSPEDES SET NOME='%q', ENDERECO='%q', CARTAO='%q' WHERE EMAIL='%q';",
        hospede.getNome().getNome().c_str(),
        hospede.getEndereco().getEndereco().c_str(),
        hospede.getCartao().getValor().c_str(),
        hospede.getEmail().getEmail().c_str()
    );

    int rc = sqlite3_exec(db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    return rc == SQLITE_OK && sqlite3_changes(db_connection) > 0;
}



bool PersistenciaHospede::excluir(const Email& email) {
    char *sql = sqlite3_mprintf(
        "DELETE FROM HOSPEDES WHERE EMAIL='%q';",
        email.getEmail().c_str()
    );

    int rc = sqlite3_exec(db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    return rc == SQLITE_OK && sqlite3_changes(db_connection) > 0;
}

vector<Hospede> PersistenciaHospede::listarTodos() {
    vector<Hospede> lista;
    
    const char *sql = "SELECT EMAIL, NOME, ENDERECO, CARTAO FROM HOSPEDES;";

    int rc = sqlite3_exec(db_connection, sql, listar_hospedes_callback, &lista, nullptr);

    if (rc != SQLITE_OK) {
        throw runtime_error("Erro ao listar todos os hospedes.");
    }

    return lista;
}
