#include "Carta.h"

Carta::Carta(string valor,string simbolo,string color){
	this->valor=valor;
	this->simbolo=simbolo;
	this->color=color;
}
Carta::Carta(){

}
void Carta::setValor(string valor){
	this-> valor=valor;
}
string Carta::getValor(){
	return valor;
}
void Carta::setSimbolo(string simbolo){
	this-> simbolo=simbolo;
}
string Carta::getSimbolo(){
	return simbolo;
}
void Carta::setColor(string color){
	this-> color=color;
}
string Carta::getColor(){
	return color;
}
