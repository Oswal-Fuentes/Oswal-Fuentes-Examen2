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
    string estado;
public:
    Repartidor(string,int,string,string,int,Baraja,string);
    Repartidor();

    string getDificultad();
    void setDificultad(string);

    int getDinero();
    void setDinero(int);

    string getEstado();
    void setEstado(string);

    void mostrar();
};
#endif