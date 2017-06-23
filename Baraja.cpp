#include "Baraja.h"

Baraja::Baraja(){

}
vector<Carta> Baraja::getCartas(){
	return cartas;
}
void Baraja::setCartas(vector<Carta>cartas){
	this->cartas=cartas;
}

void Baraja::addCarta(Carta carta){
	this->cartas.push_back(carta);
}