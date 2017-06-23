#include "Jugador.h"

Jugador::Jugador(string nombre,int edad,string numero_id,string procedencia,string apodo,int dinero,string estado){
	this->nombre=nombre;
	this->edad=edad;
	this->numero_id=numero_id;
	this->procedencia=procedencia;
	this->apodo=apodo;
	this->dinero=dinero;
	this->estado=estado;
}
Jugador::Jugador(){

}
void Jugador::setProcedencia(string procedencia){
	this-> procedencia=procedencia;
}
string Jugador::getProcedencia(){
	return procedencia;
}
void Jugador::setApodo(string apodo){
	this-> apodo=apodo;
}
string Jugador::getApodo(){
	return apodo;
}
void Jugador::setDinero(int dinero){
	this-> dinero=dinero;
}
int Jugador::getDinero(){
	return dinero;
}
void Jugador::setEstado(string estado){
	this-> estado=estado;
}
string Jugador::getEstado(){
	return estado;
}
void Jugador::mostrar(){
	cout<<"Jugador"<<endl;
	Persona::mostrar();
	cout<<"Procedencia: "<<procedencia<<endl;
	cout<<"Apodo: "<<apodo<<endl;
	cout<<"Dinero: "<<dinero<<endl;
	cout<<"Estado: "<<estado<<endl;
}