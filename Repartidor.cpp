#include "Repartidor.h"

Repartidor::Repartidor(string nombre,int edad,string numero_id,string dificultad,int dinero,Baraja baraja,string estado){
	this->nombre=nombre;
	this->edad=edad;
	this->numero_id=numero_id;
	this->dificultad=dificultad;
	this->dinero=dinero;
	this->baraja=baraja;
	this->estado=estado;
}
Repartidor::Repartidor(){

}
void Repartidor::setDificultad(string dificultad){
	this-> dificultad=dificultad;
}
string Repartidor::getDificultad(){
	return dificultad;
}
void Repartidor::setDinero(int dinero){
	this-> dinero=dinero;
}
int Repartidor::getDinero(){
	return dinero;
}

string Repartidor::getEstado(){
	return estado;
}

void Repartidor::setEstado(string estado){
	this->estado=estado;
}

void Repartidor::mostrar(){
	cout<<"Repartidor"<<endl;
	Persona::mostrar();
	cout<<"Dificultad: "<<dificultad<<endl;
	cout<<"Dinero: "<<dinero<<endl;
	cout<<"Estado: "<<estado<<endl;	
}