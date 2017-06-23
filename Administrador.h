#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador:public Persona{
protected:
    int xp;
    string rango;
    int sueldo;
public:
    Administrador(string,int,string,int,string,int);
    Administrador();

    int getXp();
    void setXp(int);

    string getRango();
    void setRango(string);

    int getSueldo();
    void setSueldo(int);

    void mostrar();
};
#endif