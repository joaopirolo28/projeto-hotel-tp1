#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED

class Reserva{
    private:
        Data chegada;
        Data partida;
        Dinheiro valor;
        Codigo codigo;

    public:
        void setChegada(Data);
        Data getChegada();

        void setPartida(Data);
        Data getPartida();

        void setValor(Dinheiro);
        Dinheiro getValor();

        void setCodigo(Codigo);
        Codigo getCodigo();
};

inline void Reserva::setChegada(Data chegada){
    this->chegada = chegada;
}

inline Data Reserva::getChegada(){
    return chegada;
}

inline void Reserva::setPartida(Data partida){
    this->partida = partida;
}

inline Data Reserva::getPartida(){
    return partida;
}

inline void Reserva::setValor(Dinheiro valor){
    this->valor = valor;
}

inline Dinheiro Reserva::getValor(){
    return valor;
}

inline void Reserva::setCodigo(Codigo codigo){
    this->codigo = codigo;
}

inline Codigo Reserva::getCodigo(){
    return codigo;
}

#endif // RESERVA_HPP_INCLUDED
