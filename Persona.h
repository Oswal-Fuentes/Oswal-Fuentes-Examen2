#include <iostream>
#include <string>

using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

class Persona{
protected:
    string nombre;
    int edad;
    string numero_id;
public:
    Persona(string,int,string);
    Persona();

    string getNombre();
    void setNombre(string);

    int getEdad();
    void setEdad(int);

    string getNumero_id();
    void setNumero_id(string);

    virtual void mostrar();
};
#endif