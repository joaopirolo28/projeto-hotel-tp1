/**
 * @file data.hpp
 * @brief Definição da classe de domínio Data.
 * @author João Pedro
 * @date 14 de novembro de 2025
 */

#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED
#include <map>
#include <string>
#include <stdexcept>

using namespace std;
/**
 * @brief Classe para armazenar e validar uma data no formato dia-mês-ano.
 * @details A data deve ser valida, considerando meses com diferentes números de dias e anos bissextos.
 * O ano deve estar entre 2000 e 2999.
 */
class Data{
    private:
        /**
         * @brief Mapa que associa o nome abreviado do mês (string) ao número de dias (int).
         */
        map<string, int> MES_DIA = {{"JAN", 31}, {"FEV", 28}, {"MAR", 31}, {"ABR", 30}, {"MAI", 31}, {"JUN", 30}, {"JUL", 31}, {"AGO", 31}, {"SET", 30}, {"OUT", 31}, {"NOV", 30}, {"DEZ", 31}};
        /**
         * @brief Armazena o dia (1 a 31).
         */
        int dia;
        /**
         * @brief Armazena o mês (ex: "JAN", "FEV").
         */
        string mes;
        /**
         * @brief Armazena o ano (2000 a 2999).
         */
        int ano;
        /**
         * @brief Verifica se um determinado ano é bissexto.
         * @param ano O ano a ser verificado.
         * @return True se for bissexto, False caso contrário.
         */
        bool bissexto(int);
        /**
         * @brief Valida se a combinação dia, mês e ano forma uma data válida.
         * @param dia O dia a ser validado.
         * @param mes O mês a ser validado (string abreviada).
         * @param ano O ano a ser validado.
         * @throw invalid_argument Se a data for inválida (dia, mês ou ano fora dos limites).
         */
        void validar(int, string, int);

    public:
        /**
         * @brief Construtor padrão da classe Data.
        * @details Inicializa o objeto com um valor padrão (string vazia).
        * Necessário para a criação de entidades (como Reserva) que contêm este domínio.
        */
        Data();
        /**
        * @brief Construtor com valor da classe Data (por componentes).
        * @details Inicializa o objeto com dia, mês e ano, que são imediatamente validados.
        * @param dia O dia (inteiro, ex: 15).
        * @param mes O mês (string, ex: "OUT").
        * @param ano O ano (inteiro, ex: 2025).
        * @throw invalid_argument Se a data não atender aos critérios de validação.
        */
        Data(int,string,int);
        /**
         * @brief Define a data completa após validação.
         * @param dia O dia (1-31).
         * @param mes O mês (ex: "JAN").
         * @param ano O ano (2000-2999).
         * @throw invalid_argument Se o dia, mês ou ano for inválido ou se a data não existir (ex: 30 de FEV).
         */
        void setData(int, string, int);

        /**
         * @brief Retorna o dia.
         * @return O valor inteiro do dia.
         */
        int getDia() const;
        /**
         * @brief Retorna o mês.
         * @return O mês em formato de string abreviada.
         */
        string getMes() const;
        /**
         * @brief Retorna o ano.
         * @return O valor inteiro do ano.
         */
        int getAno() const;
        /**
         * @brief Retorna a data.
         * @return O valor em string da data.
         */
        string getData() const;

        /**
         * @brief Sobrecarga do operador menor ou igual (<=) para comparar duas datas.
         * @param outra A outra data a ser comparada.
         * @return true se a data atual for anterior ou igual a 'outra'.
         */
        bool operator<=(const Data& outra) const;

        /**
         * @brief Sobrecarga do operador maior ou igual (>=) para comparar duas datas.
         * @param outra A outra data a ser comparada.
         * @return true se a data atual for posterior ou igual a 'outra'.
         */
        bool operator>=(const Data& outra) const;

        bool operator<(const Data& outra) const;
};

inline int Data::getDia() const{
    return dia;
}
inline string Data::getMes() const{
    return mes;
}
inline int Data::getAno() const{
    return ano;
}
inline string Data::getData() const{
    return to_string(dia) + "-" + mes + "-" + to_string(ano);
}

inline int getMesNumerico(const std::string& mes) {
    if (mes == "JAN") return 1;
    if (mes == "FEV") return 2;
    // ... e assim por diante para todos os 12 meses
    if (mes == "DEZ") return 12;
    return 0; // Erro ou placeholder
}

// Assinatura do operador < (útil para implementar <= e >=)
inline bool Data::operator<(const Data& outra) const {
    if (ano != outra.ano) {
        return ano < outra.ano;
    }
    // Implementação ideal: usar getMesNumerico para evitar comparação de string alfabética.
    int thisMes = getMesNumerico(mes);
    int outraMes = getMesNumerico(outra.mes);

    if (thisMes != outraMes) {
        return thisMes < outraMes;
    }
    return dia < outra.dia;
}

// Implementação do operador <=
inline bool Data::operator<=(const Data& outra) const {
    return (*this < outra) || (this->ano == outra.ano && this->mes == outra.mes && this->dia == outra.dia);
}

// Implementação do operador >=
inline bool Data::operator>=(const Data& outra) const {
    return !(*this < outra); // Se não for menor, é maior ou igual
}

#endif // DATA_HPP_INCLUDED
