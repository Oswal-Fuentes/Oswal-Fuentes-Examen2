#include <iostream>
#include <string>
#include "Repartidor.h"
#include "Jugador.h"

using namespace std;

#ifndef MESA_BLACKJACK_H
#define MESA_BLACKJACK_H

class Mesa_Blackjack{
protected:
    int numero;
    string tipo;
    Repartidor* repartidor;
    Jugador* jugador;
public:
    Mesa_Blackjack(int,string,Repartidor*,Jugador*);
    Mesa_Blackjack();

    int getNumero();
    void setNumero(int);

    string getTipo();
    void setTipo(string);

    Repartidor* getRepartidor();
    void setRepartidor(Repartidor*);

    Jugador* getJugador();
    void setJugador(Jugador*);

    void listar();

};
#endif