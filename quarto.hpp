#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED

class Quarto{
    private:
        Numero numero;
        Capacidade capacidade;
        Dinheiro diaria;
        Ramal ramal;

    public:
        void setNumero(Numero);
        Numero getNumero();

        void setCapacidade(Capacidade);
        Capacidade getCapacidade();

        void setDiaria(Dinheiro);
        Dinheiro getDiaria();

        void setRamal(Ramal);
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
