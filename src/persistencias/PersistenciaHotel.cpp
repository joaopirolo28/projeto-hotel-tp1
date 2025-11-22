/**
 * @file PersistenciaHotel.cpp
 * @brief Implementação da lógica de CRUD para a entidade Hotel usando SQLite.
 */
#include "persistencias/PersistenciaHotel.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>
#include <iostream>
#include <sqlite3.h>
#include <vector>

using namespace std;

struct HotelData {
    Hotel result;
    bool found = false;
};

static int retrieve_hotel_data(void *data, int argc, char **argv, char **azColName) {
    HotelData *pData = (HotelData*)data;

    try {
        pData->result.setCodigo(Codigo(argv[0] ? argv[0] : ""));
        pData->result.setNome(Nome(argv[1] ? argv[1] : ""));
        pData->result.setEndereco(Endereco(argv[2] ? argv[2] : ""));
        pData->result.setTelefone(Telefone(argv[3] ? argv[3] : ""));
        pData->found = true;
    } catch (const invalid_argument&) {
        return 1;
    }
    return 0;
}

static int listar_hoteis_callback(void *data, int argc, char **argv, char **azColName) {
    vector<Hotel> *lista = reinterpret_cast<vector<Hotel>*>(data);
    Hotel h;

    try {
        h.setCodigo(Codigo(argv[0] ? argv[0] : ""));
        h.setNome(Nome(argv[1] ? argv[1] : ""));
        h.setEndereco(Endereco(argv[2] ? argv[2] : ""));
        h.setTelefone(Telefone(argv[3] ? argv[3] : ""));
    } catch (const invalid_argument&) {
        return 1;
    }

    lista->push_back(h);
    return 0;
}

PersistenciaHotel::PersistenciaHotel() {
    int rc = sqlite3_open("hotel_database.db", &this->db_connection);
    if (rc != SQLITE_OK) {
        throw runtime_error("Falha ao abrir banco SQLite para Hotel.");
    }
    const char *sql =
        "CREATE TABLE IF NOT EXISTS HOTEIS("
        "CODIGO TEXT PRIMARY KEY NOT NULL,"
        "NOME TEXT NOT NULL,"
        "ENDERECO TEXT NOT NULL,"
        "TELEFONE TEXT NOT NULL);";
    sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
}

PersistenciaHotel::~PersistenciaHotel() {
    if (this->db_connection != nullptr) {
        sqlite3_close(this->db_connection);
        this->db_connection = nullptr;
    }
}

bool PersistenciaHotel::cadastrar(const Hotel& hotel) {
    char *sql = sqlite3_mprintf(
        "INSERT INTO HOTEIS (CODIGO, NOME, ENDERECO, TELEFONE) "
        "VALUES ('%q', '%q', '%q', '%q');",
        hotel.getCodigo().getValor().c_str(),
        hotel.getNome().getNome().c_str(),
        hotel.getEndereco().getEndereco().c_str(),
        hotel.getTelefone().getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);
    if (rc == SQLITE_CONSTRAINT) return false;
    return rc == SQLITE_OK;
}

Hotel PersistenciaHotel::consultar(const Codigo& codigo) {
    HotelData data;
    char *sql = sqlite3_mprintf(
        "SELECT CODIGO, NOME, ENDERECO, TELEFONE FROM HOTEIS WHERE CODIGO = '%q';",
        codigo.getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, retrieve_hotel_data, &data, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK || !data.found)
        throw runtime_error("Hotel nao encontrado.");
    return data.result;
}

bool PersistenciaHotel::editar(const Hotel& hotel) {
    char *sql = sqlite3_mprintf(
        "UPDATE HOTEIS SET NOME='%q', ENDERECO='%q', TELEFONE='%q' WHERE CODIGO='%q';",
        hotel.getNome().getNome().c_str(),
        hotel.getEndereco().getEndereco().c_str(),
        hotel.getTelefone().getValor().c_str(),
        hotel.getCodigo().getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);
    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

bool PersistenciaHotel::excluir(const Codigo& codigo) {
    char *sql = sqlite3_mprintf(
        "DELETE FROM HOTEIS WHERE CODIGO='%q';",
        codigo.getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);
    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

std::vector<Hotel> PersistenciaHotel::listarTodos() {
    vector<Hotel> lista;
    const char *sql = "SELECT CODIGO, NOME, ENDERECO, TELEFONE FROM HOTEIS;";

    int rc = sqlite3_exec(this->db_connection, sql, listar_hoteis_callback, &lista, nullptr);

    if (rc != SQLITE_OK) {
        throw runtime_error("Erro ao listar todos os hoteis.");
    }
    return lista;
}
