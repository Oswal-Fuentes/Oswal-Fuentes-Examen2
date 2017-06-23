#include <iostream>
#include <string>

using namespace std;

#ifndef CARTA_H
#define CARTA_H

class Carta{
protected:
    string valor;
    string simbolo;
    string color;
public:
    Carta(string,string,string);
    Carta();
    string getValor();
    void setValor(string);

    string getSimbolo();
    void setSimbolo(string);

    string getColor();
    void setColor(string);

};
#endif