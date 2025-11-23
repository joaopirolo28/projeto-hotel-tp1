#include "persistencias/PersistenciaReserva.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>
#include <iostream>
#include <sqlite3.h>
#include <vector>

using namespace std;

struct ReservaData {
    Reserva result;
    bool found = false;
};

static int listar_reservas_callback(void *data, int argc, char **argv, char **azColName) {
    vector<Reserva> *lista = reinterpret_cast<vector<Reserva>*>(data);
    Reserva r;

    try {
        r.setCodigo(Codigo(argv[0] ? argv[0] : ""));

        Data tempChegada;
        tempChegada.setValorDB(argv[1] ? argv[1] : "01-JAN-2000");
        r.setChegada(tempChegada);

        Data tempPartida;
        tempPartida.setValorDB(argv[2] ? argv[2] : "01-JAN-2000");
        r.setPartida(tempPartida);

        r.setValor(Dinheiro(std::stod(argv[3] ? argv[3] : "0.0")));

        r.setEmailHospede(Email(argv[4] ? argv[4] : ""));
        r.setCodigoHotel(Codigo(argv[5] ? argv[5] : ""));
        r.setNumeroQuarto(Numero(std::stoi(argv[6] ? argv[6] : "0")));

    } catch (const exception&) {
        return 1;
    }

    lista->push_back(r);
    return 0;
}


static int retrieve_reserva_data(void *data, int argc, char **argv, char **azColName) {
    ReservaData *pData = (ReservaData*)data;

    try {
        pData->result.setCodigo(Codigo(argv[0] ? argv[0] : ""));

        Data tempChegada;
        tempChegada.setValorDB(argv[1] ? argv[1] : "01-JAN-2000");
        pData->result.setChegada(tempChegada);

        Data tempPartida;
        tempPartida.setValorDB(argv[2] ? argv[2] : "01-JAN-2000");
        pData->result.setPartida(tempPartida);

        pData->result.setValor(Dinheiro(std::stod(argv[3] ? argv[3] : "0.0")));

        pData->result.setEmailHospede(Email(argv[4] ? argv[4] : ""));
        pData->result.setCodigoHotel(Codigo(argv[5] ? argv[5] : ""));
        pData->result.setNumeroQuarto(Numero(std::stoi(argv[6] ? argv[6] : "0")));
        pData->found = true;
    } catch (const exception&) {
        return 1;
    }
    return 0;
}

PersistenciaReserva::PersistenciaReserva() {
    int rc = sqlite3_open("hotel_database.db", &this->db_connection);
    if (rc != SQLITE_OK) {
        throw runtime_error("Falha ao abrir banco SQLite para Reserva.");
    }
    const char *sql =
        "CREATE TABLE IF NOT EXISTS RESERVAS("
        "CODIGO TEXT PRIMARY KEY NOT NULL,"
        "DATA_CHEGADA TEXT NOT NULL,"
        "DATA_PARTIDA TEXT NOT NULL,"
        "VALOR TEXT NOT NULL,"
        "EMAIL_HOSPEDE TEXT NOT NULL,"
        "CODIGO_HOTEL TEXT NOT NULL,"
        "NUMERO_QUARTO TEXT NOT NULL,"
        "FOREIGN KEY (EMAIL_HOSPEDE) REFERENCES HOSPEDES(EMAIL),"
        "FOREIGN KEY (CODIGO_HOTEL, NUMERO_QUARTO) REFERENCES QUARTOS(CODIGO_HOTEL, NUMERO));";
    sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
}

PersistenciaReserva::~PersistenciaReserva() {
    if (this->db_connection != nullptr) {
        sqlite3_close(this->db_connection);
    }
}

bool PersistenciaReserva::cadastrar(const Reserva& reserva) {

    char *sql = sqlite3_mprintf(
        "INSERT INTO RESERVAS (CODIGO, DATA_CHEGADA, DATA_PARTIDA, VALOR, EMAIL_HOSPEDE, CODIGO_HOTEL, NUMERO_QUARTO) "
        "VALUES ('%q', '%q', '%q', '%q', '%q', '%q', '%q');",
        reserva.getCodigo().getValor().c_str(),
        reserva.getChegada().getData().c_str(),
        reserva.getPartida().getData().c_str(),
        std::to_string(reserva.getValor().getValor()).c_str(),
        reserva.getEmailHospede().getEmail().c_str(),
        reserva.getCodigoHotel().getValor().c_str(),
        std::to_string(reserva.getNumeroQuarto().getValor()).c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    if (rc == SQLITE_CONSTRAINT) return false;
    return rc == SQLITE_OK;
}

Reserva PersistenciaReserva::consultar(const Codigo& codigo) {
    ReservaData data;
    char *sql = sqlite3_mprintf(
        "SELECT CODIGO, DATA_CHEGADA, DATA_PARTIDA, VALOR, EMAIL_HOSPEDE, CODIGO_HOTEL, NUMERO_QUARTO FROM RESERVAS WHERE CODIGO = '%q';",
        codigo.getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, retrieve_reserva_data, &data, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK || !data.found)
        throw runtime_error("Reserva nao encontrada.");
    return data.result;
}

bool PersistenciaReserva::editar(const Reserva& reserva) {
    char *sql = sqlite3_mprintf(
        "UPDATE RESERVAS SET DATA_CHEGADA='%q', DATA_PARTIDA='%q', VALOR='%q', EMAIL_HOSPEDE='%q', CODIGO_HOTEL='%q', NUMERO_QUARTO='%q' WHERE CODIGO='%q';",
        reserva.getChegada().getData().c_str(),
        reserva.getPartida().getData().c_str(),
        std::to_string(reserva.getValor().getValor()).c_str(),
        reserva.getEmailHospede().getEmail().c_str(),
        reserva.getCodigoHotel().getValor().c_str(),
        std::to_string(reserva.getNumeroQuarto().getValor()).c_str(),
        reserva.getCodigo().getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

bool PersistenciaReserva::excluir(const Codigo& codigo) {
    char *sql = sqlite3_mprintf(
        "DELETE FROM RESERVAS WHERE CODIGO='%q';",
        codigo.getValor().c_str()
    );
    int rc = sqlite3_exec(this->db_connection, sql, nullptr, nullptr, nullptr);
    sqlite3_free(sql);

    return rc == SQLITE_OK && sqlite3_changes(this->db_connection) > 0;
}

std::vector<Reserva> PersistenciaReserva::listarPorHospede(const Email& emailHospede) {
    std::vector<Reserva> lista;
    char *sql = sqlite3_mprintf(
        "SELECT CODIGO, DATA_CHEGADA, DATA_PARTIDA, VALOR, EMAIL_HOSPEDE, CODIGO_HOTEL, NUMERO_QUARTO FROM RESERVAS WHERE EMAIL_HOSPEDE = '%q';",
        emailHospede.getEmail().c_str()
    );

    int rc = sqlite3_exec(this->db_connection, sql, listar_reservas_callback, &lista, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK) {
        throw runtime_error("Erro ao listar reservas por hospede.");
    }
    return lista;
}

std::vector<Reserva> PersistenciaReserva::listarReservasPorQuarto(const Codigo& codigoHotel, const Numero& numeroQuarto) {
    std::vector<Reserva> lista;
    char *sql = sqlite3_mprintf(
        "SELECT CODIGO, DATA_CHEGADA, DATA_PARTIDA, VALOR, EMAIL_HOSPEDE, CODIGO_HOTEL, NUMERO_QUARTO FROM RESERVAS WHERE CODIGO_HOTEL = '%q' AND NUMERO_QUARTO = '%q';",
        codigoHotel.getValor().c_str(),
        std::to_string(numeroQuarto.getValor()).c_str()
    );

    int rc = sqlite3_exec(this->db_connection, sql, listar_reservas_callback, &lista, nullptr);
    sqlite3_free(sql);

    if (rc != SQLITE_OK) {
        throw runtime_error("Erro ao listar reservas por quarto.");
    }
    return lista;
}
