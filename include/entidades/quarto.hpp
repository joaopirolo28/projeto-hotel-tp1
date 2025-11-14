/**
 * @file quarto.hpp
 * @brief Definição da classe da entidade Quarto.
 * @author [Seu Nome Aqui - Exemplo: João Pedro]
 * @date 14/11/2025
 */

#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED

// Assumindo que os includes para Domínios estão em quarto.hpp (Adicione-os conforme necessário)
// Exemplo:
// #include "dominios/numero.hpp"
// #include "dominios/capacidade.hpp"
// #include "dominios/dinheiro.hpp"
// #include "dominios/ramal.hpp"

/**
 * @brief Classe entidade que representa um Quarto no sistema hoteleiro.
 * @details Contém informações sobre o número, capacidade de hóspedes, valor da diária
 * e o ramal telefônico associado ao quarto.
 */
class Quarto{
    private:
        /**
         * @brief O número de identificação do quarto (Domínio Numero).
         */
        Numero numero;
        /**
         * @brief A capacidade máxima de hóspedes do quarto (Domínio Capacidade).
         */
        Capacidade capacidade;
        /**
         * @brief O valor da diária do quarto (Domínio Dinheiro).
         */
        Dinheiro diaria;
        /**
         * @brief O ramal telefônico do quarto (Domínio Ramal).
         */
        Ramal ramal;

    public:

        Quarto() {}
        /**
         * @brief Define o número do quarto.
         * @param numero Um objeto do tipo Numero.
         */
        void setNumero(Numero numero);
        /**
         * @brief Retorna o número do quarto.
         * @return Um objeto do tipo Numero.
         */
        Numero getNumero();

        /**
         * @brief Define a capacidade de hóspedes do quarto.
         * @param capacidade Um objeto do tipo Capacidade.
         */
        void setCapacidade(Capacidade capacidade);
        /**
         * @brief Retorna a capacidade de hóspedes do quarto.
         * @return Um objeto do tipo Capacidade.
         */
        Capacidade getCapacidade();

        /**
         * @brief Define o valor da diária do quarto.
         * @param diaria Um objeto do tipo Dinheiro.
         */
        void setDiaria(Dinheiro diaria);
        /**
         * @brief Retorna o valor da diária do quarto.
         * @return Um objeto do tipo Dinheiro.
         */
        Dinheiro getDiaria();

        /**
         * @brief Define o ramal telefônico do quarto.
         * @param ramal Um objeto do tipo Ramal.
         */
        void setRamal(Ramal ramal);
        /**
         * @brief Retorna o ramal telefônico do quarto.
         * @return Um objeto do tipo Ramal.
         */
        Ramal getRamal();

};

    inline void Quarto::setNumero(Numero numero){
        this->numero = numero;
    }

    inline Numero Quarto::getNumero(){
        return numero;
    }

    inline void Quarto::setCapacidade(Capacidade capacidade){
        this->capacidade = capacidade;
    }

    inline Capacidade Quarto::getCapacidade(){
        return capacidade;
    }

    inline void Quarto::setDiaria(Dinheiro diaria){
        this->diaria = diaria;
    }

    inline Dinheiro Quarto::getDiaria(){
        return diaria;
    }

    inline void Quarto::setRamal(Ramal ramal){
        this->ramal = ramal;
    }

    inline Ramal Quarto::getRamal(){
        return ramal;
    }

#endif // QUARTO_HPP_INCLUDED
