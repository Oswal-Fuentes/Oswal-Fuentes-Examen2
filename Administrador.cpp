#include "Administrador.h"

Administrador::Administrador(string nombre,int edad,string numero_id,int xp,string rango,int sueldo){
	this->nombre=nombre;
	this->edad=edad;
	this->numero_id=numero_id;
	this->xp=xp;
	this->rango=rango;
	this->sueldo=sueldo;
}
Administrador::Administrador(){

}
void Administrador::setXp(int xp){
	this-> xp=xp;
}
int Administrador::getXp(){
	return xp;
}
void Administrador::setRango(string rango){
	this-> rango=rango;
}
string Administrador::getRango(){
	return rango;
}
void Administrador::setSueldo(int sueldo){
	this-> sueldo=sueldo;
}
int Administrador::getSueldo(){
	return sueldo;
}
void Administrador::mostrar(){
	cout<<"Administrador"<<endl;
	Persona::mostrar();
	cout<<"Experiencia laboral: "<<xp<<endl;
	cout<<"Rango de Administrador: "<<rango<<endl;
	cout<<"Sueldo: "<<sueldo<<endl;
}

