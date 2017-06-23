#include "Mesa_Blackjack.h"

Mesa_Blackjack::Mesa_Blackjack(int numero,string tipo){
	this->numero=numero;
	this->tipo=tipo;
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
