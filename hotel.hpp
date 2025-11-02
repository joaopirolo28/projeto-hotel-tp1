#ifndef HOTEL_HPP_INCLUDED
#define HOTEL_HPP_INCLUDED

#include "hotel.hpp"

class Hotel{
    private:
        Nome nome;
        Endereco endereco;
        Telefone telefone;
        Codigo codigo;

    public:
        void setNome(Nome);
        Nome getNome();

        void setEndereco(Endereco);
        Endereco getEndereco();

        void setTelefone(Telefone);
        Telefone getTelefone();

        void setCodigo(Codigo);
        Codigo getCodigo();
};

inline void Hotel::setNome(Nome nome){
    this->nome = nome;
}

inline Nome Hotel::getNome(){
    return nome;
}

inline void Hotel::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

inline Endereco Hotel::getEndereco(){
    return endereco;
}

inline void Hotel::setTelefone(Telefone telefone){
    this->telefone = telefone;
}

inline Telefone Hotel::getTelefone(){
    return telefone;
}

inline void Hotel::setCodigo(Codigo codigo){
    this->codigo = codigo;
}

inline Codigo Hotel::getCodigo(){
    return codigo;
}

#endif // HOTEL_HPP_INCLUDED
