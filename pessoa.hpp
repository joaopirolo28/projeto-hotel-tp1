#ifndef PESSOA_HPP
#define PESSOA_HPP

#include"nome.hpp"
#include"email.hpp"

class Pessoa{
protected:
    Nome nome;
    Email email;
public:
    void setNome(const Nome&nome);
    Nome getNome()const;

    void setEmail(const Email&email);
    Email getEmail() const;
};

#endif //PESSOA_HPP