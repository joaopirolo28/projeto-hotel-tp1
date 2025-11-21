/**
 * @file PersistenciaQuarto.cpp
 * @brief Implementação da lógica de CRUD para a entidade Quarto usando SQLite.
 */
#include "persistencias/PersistenciaQuarto.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>
#include <iostream>
#include <sqlite3.h>
#include <vector>

using namespace std;

struct QuartoData {
    Quarto result;
    bool found = false;
};

static int retrieve_quarto_data(void *data, int argc, char **argv, char **azColName) {
    QuartoData *pData = (QuartoData*)data;

    try {
        pData->result.setNumero(Numero(argv[0] ? argv[0] : ""));
        pData->result.setCapacidade(Capacidade(stoi(argv[1]))); // Assume Capacidade aceita int
        pData->result.setDiaria(Dinheiro(stod(argv[2])));      // Assume Dinheiro aceita double/string
        pData->result.setRamal(Ramal(argv[3] ? argv[3] : ""));
        pData->found = true;
    } catch (const invalid_argument&) {
        return 1;
    }
    return 0;
}

static int listar_quartos_callback(void *data, int argc, char **argv, char **azColName) {
    vector<Quarto> *lista = reinterpret_cast<vector<Quarto>*>(data);
    Quarto q;

    try {
        q.setNumero(Numero(argv[0] ? argv[0] : ""));
        q.setCapacidade(Capacidade(stoi(argv[1])));
        q.setDiaria(Dinheiro(stod(argv[2])));
        q.setRamal(Ramal(argv[3] ? argv[3] : ""));
    } catch (const invalid_argument&) {
        return 1;
    }

    lista->push_back(q);
    return 0;
}

PersistenciaQuarto::PersistenciaQuarto() {
    int rc = sqlite3_open("hotel_database.db", &this->db_connection);
    if (rc != SQLITE_OK) {
        throw runtime_error("Falha ao abrir banco SQLite para Quarto.");
    }
    const char *sql =
        "CREATE TABLE IF NOT EXISTS QUARTOS("
        "CODIGO_HOTEL TEXT NOT NULL,"
        "NUMERO TEXT NOT NULL,"
        "CAPACIDADE INTEGER NOT NULL,"
        "DIARIA TEXT NOT NULL,"
        "RAMAL TEXT NOT NULL,"
        "PRIMARY KEY (CODIGO_HOTEL, NUMERO),"
        "FOREIGN KEY (CODIGO_HOTEL) REFERENCES HOTEIS(CODIGO));"; // FK para Hotel
    sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
}

PersistenciaQuarto::~PersistenciaQuarto() {
    if (this->db_connection != nullptr) {
        sqlite3_close(this->db_connection);
    }
}

bool PersistenciaQuarto::cadastrar(const Codigo& codigoHotel, const Quarto& quarto) {
    char *sql = sqlite3_mprintf(
        "INSERT INTO QUARTOS (CODIGO_HOTEL, NUMERO, CAPACIDADE, DIARIA, RAMAL) "
        "VALUES ('%q', '%q', %d, '%q', '%q');",
        codigoHotel.getValor().c_str(),
        quarto.getNumero().getValor().c_str(),
        quarto.getCapacidade().getValor(),
        quarto.getDiaria().getValorString().c_str(),
        quarto.getRamal().getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);
    if (rc == SQLITE_CONSTRAINT) return false;
    return rc == SQLITE_OK;
}

Quarto PersistenciaQuarto::consultar(const Codigo& codigoHotel, const Numero& numeroQuarto) {
    QuartoData data;
    char *sql = sqlite3_mprintf(
        "SELECT NUMERO, CAPACIDADE, DIARIA, RAMAL FROM QUARTOS WHERE CODIGO_HOTEL = '%q' AND NUMERO = '%q';",
        codigoHotel.getValor().c_str(),
        numeroQuarto.getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, retrieve_quarto_data, &data, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK || !data.found)
        throw runtime_error("Quarto nao encontrado para este hotel.");
    return data.result;
}

bool PersistenciaQuarto::editar(const Codigo& codigoHotel, const Quarto& quarto) {
    char *sql = sqlite3_mprintf(
        "UPDATE QUARTOS SET CAPACIDADE=%d, DIARIA='%q', RAMAL='%q' WHERE CODIGO_HOTEL='%q' AND NUMERO='%q';",
        quarto.getCapacidade().getValor(),
        quarto.getDiaria().getValorString().c_str(),
        quarto.getRamal().getValor().c_str(),
        codigoHotel.getValor().c_str(),
        quarto.getNumero().getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);
    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

bool PersistenciaQuarto::excluir(const Codigo& codigoHotel, const Numero& numeroQuarto) {
    char *sql = sqlite3_mprintf(
        "DELETE FROM QUARTOS WHERE CODIGO_HOTEL='%q' AND NUMERO='%q';",
        codigoHotel.getValor().c_str(),
        numeroQuarto.getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);
    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

std::vector<Quarto> PersistenciaQuarto::listarQuartos(const Codigo& codigoHotel) {
    vector<Quarto> lista;
    char *sql = sqlite3_mprintf(
        "SELECT NUMERO, CAPACIDADE, DIARIA, RAMAL FROM QUARTOS WHERE CODIGO_HOTEL = '%q';",
        codigoHotel.getValor().c_str()
    );

    int rc = sqlite3_exec(this->db_connection, sql, listar_quartos_callback, &lista, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK) {
        throw runtime_error("Erro ao listar quartos por hotel.");
    }
    return lista;
}
