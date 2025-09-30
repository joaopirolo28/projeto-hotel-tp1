#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED
#include <map>
#include <string>

using namespace std;

class Data{
    private:
        map<string, int> MES_DIA = {{"JAN", 31}, {"FEV", 28}, {"MAR", 31}, {"ABR", 30}, {"MAI", 31}, {"JUN", 30}, {"JUL", 31}, {"AGO", 31}, {"SET", 30}, {"OUT", 31}, {"NOV", 30}, {"DEZ", 31}};
        int dia;
        string mes;
        int ano;
        bool bissexto(int);
        bool validar(int, string, int);

    public:
        bool setData(int, string, int);

        int getDia();
        string getMes();
        int getAno();
};

inline int Data::getDia(){
    return dia;
}
inline string Data::getMes(){
    return mes;
}
inline int Data::getAno(){
    return ano;
}

#endif // DATA_HPP_INCLUDED
