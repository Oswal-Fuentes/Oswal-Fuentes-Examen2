#include <iostream>
#include <string>
#include "Persona.h"
#include "Baraja.h"

using namespace std;

#ifndef REPARTIDOR_H
#define REPARTIDOR_H

class Repartidor:public Persona{
protected:
    string dificultad;
    int dinero;
    Baraja baraja;
public:
    Repartidor(string,int,string,string,int,Baraja);
    Repartidor();

    string getDificultad();
    void setDificultad(string);

    int getDinero();
    void setDinero(int);

    void mostrar();
};
#endif