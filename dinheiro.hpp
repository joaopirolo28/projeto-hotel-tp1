#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

using namespace std;

class Dinheiro{

    private:
    long int valorCentavos;
    void validar(double valor) const;
    public:
    void setValor(double valor);
    double getValor() const;
    Dinheiro(const double &valor);
};

#endif //DINHEIRO_HPP