#include <iostream>
#include <string>

using namespace std;

#ifndef MESA_BLACKJACK_H
#define MESA_BLACKJACK_H

class Mesa_Blackjack{
protected:
    int numero;
    string tipo;
public:
    Mesa_Blackjack(int,string);
    Mesa_Blackjack();
    
    int getNumero();
    void setNumero(int);

    string getTipo();
    void setTipo(string);

};
#endif