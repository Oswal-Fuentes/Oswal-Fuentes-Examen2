#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador:public Persona{
protected:
    string procedencia;
    string apodo;
    int dinero;
    string estado;
public:
    Jugador(string,int,string,string,string,int,string);
    Jugador();
    string getProcedencia();
    void setProcedencia(string);

    string getApodo();
    void setApodo(string);

    int getDinero();
    void setDinero(int);

    string getEstado();
    void setEstado(string);

    void mostrar();
};
#endif