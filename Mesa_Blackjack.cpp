#include "Mesa_Blackjack.h"

Mesa_Blackjack::Mesa_Blackjack(int numero,string tipo,Repartidor* repartidor,Jugador* jugador){
	this->numero=numero;
	this->tipo=tipo;
	this->repartidor=repartidor;
	this->jugador=jugador;	
}
Mesa_Blackjack::Mesa_Blackjack(){

}
void Mesa_Blackjack::setNumero(int numero){
	this-> numero=numero;
}
int Mesa_Blackjack::getNumero(){
	return numero;
}
void Mesa_Blackjack::setTipo(string tipo){
	this-> tipo=tipo;
}
string Mesa_Blackjack::getTipo(){
	return tipo;
}
Repartidor* Mesa_Blackjack::getRepartidor(){
	return repartidor;
}
void Mesa_Blackjack::setRepartidor(Repartidor* repartidor){
	this->repartidor=repartidor;
}

Jugador* Mesa_Blackjack::getJugador(){
	return jugador;
}
void Mesa_Blackjack::setJugador(Jugador* jugador){
	this->jugador=jugador;
}

void Mesa_Blackjack::listar(){
	cout<<"Mesa"<<endl;
	cout<<"Numero: "<<numero<<endl;
	cout<<"Tipo: "<<tipo<<endl;
	cout<<"Repartidor: "<<repartidor->getNombre()<<endl;
	cout<<"Jugador: "<<jugador->getNombre()<<endl;
}
