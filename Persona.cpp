#include "Persona.h"

Persona::Persona(string nombre,int edad,string numero_id){
	this->nombre=nombre;
	this->edad=edad;
	this->numero_id=numero_id;
}
Persona::Persona(){

}
void Persona::setNombre(string nombre){
	this-> nombre=nombre;
}
string Persona::getNombre(){
	return nombre;
}
void Persona::setEdad(int edad){
	this-> edad=edad;
}
int Persona::getEdad(){
	return edad;
}
void Persona::setNumero_id(string numero_id){
	this-> numero_id=numero_id;
}
string Persona::getNumero_id(){
	return numero_id;
}
void Persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
	cout<<"Numero de identidad: "<<numero_id<<endl;
}

