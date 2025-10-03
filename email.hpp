#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <string>
#include <stdexcept>
using namespace std;
class Email {
private:
    string email;
    void validar(const string& email);
    void validarParteLocal(const string& parteLocal);
    void validarDominio(const string& dominio);

public:
    static constexpr int TAMANHO_MAX_LOCAL = 64;
    static constexpr int TAMANHO_MAX_DOMINIO = 255;

    Email(const string& email);
    void setEmail(const string& email);
    string getEmail() const;
};

inline string Email::getEmail() const {
    return this->email;
}

#endif // EMAIL_HPP_INCLUDED