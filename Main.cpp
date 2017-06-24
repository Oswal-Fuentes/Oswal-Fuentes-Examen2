#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Persona.h"
#include "Administrador.h"
#include "Repartidor.h"
#include "Jugador.h"
#include "Baraja.h"
#include "Carta.h"
#include "Mesa_Blackjack.h"

using namespace std;

int menu();
int menuAgregarPersona();
int menuAdministrador();
Baraja generador_Barajas();

int main(){
	vector<Persona*>personas;
	vector<Mesa_Blackjack*>mesas;
	//Admin por defecto
	Persona* def_admin = new Administrador("El_Admin",30,"1234",5,"Gerente Tiempo Completo",20000);
	personas.push_back(def_admin);
	//Repartidor por defecto
	Persona* def_repartidor = new Repartidor("El_Repartidor",25,"5678","Intermedio",30000,generador_Barajas(),"Sin mesa");
	personas.push_back(def_repartidor);
	//Jugador por defecto
	Persona* def_jugador = new Jugador("El_Jugador",35,"9012","New Vegas","The_Gambler",40000,"Sin mesa");
	personas.push_back(def_jugador);
	//--------------
	bool salir=false;
	while (!salir) {
		switch (menu()) {
			case 1:{
				switch (menuAgregarPersona()) {
					case 1:{
						string nombre;
						int edad;
						string numero_id;
						int xp;
						string rango;
						int sueldo;
						cout<<"Ingrese nombre del administrador: "<<endl;
						cin>>nombre;
						cout<<"Ingrese edad del administrador: "<<endl;
						cin>>edad;
						cout<<"Ingrese numero de identidad del administrador: "<<endl;
						cin>>numero_id;
						cout<<"Ingrese años de experiencia laboral del administrador: "<<endl;
						cin>>xp;
						cout<<"Ingrese rango del administrador: "<<endl;
						cin>>rango;
						cout<<"Ingrese sueldo del administrador: "<<endl;
						cin>>sueldo;
						Persona* admin = new Administrador(nombre,edad,numero_id,xp,rango,sueldo);
						personas.push_back(admin);
						break;
					}//Fin Case 1 agregar
					case 2:{
						string nombre;
						int edad;
						string numero_id;
						string dificultad;
						int dinero;
						cout<<"Ingrese nombre del repartidor: "<<endl;
						cin>>nombre;
						cout<<"Ingrese edad del repartidor: "<<endl;
						cin>>edad;
						cout<<"Ingrese numero de identidad del repartidor: "<<endl;
						cin>>numero_id;
						cout<<"Ingrese dificultad del repartidor: "<<endl;
						cin>>dificultad;
						cout<<"Ingrese dinero del repartidor: "<<endl;
						cin>>dinero;
						Persona* repartidor = new Repartidor(nombre,edad,numero_id,dificultad,dinero,generador_Barajas(),"Sin mesa");
						personas.push_back(repartidor);
						break;
					}//Fin Case 2 agregar
					case 3:{
						string nombre;
						int edad;
						string numero_id;
						string procedencia;
						string apodo;
						int dinero;
						cout<<"Ingrese nombre del jugador: "<<endl;
						cin>>nombre;
						cout<<"Ingrese edad del jugador: "<<endl;
						cin>>edad;
						cout<<"Ingrese numero de identidad del jugador: "<<endl;
						cin>>numero_id;
						cout<<"Ingrese procedencia del jugador: "<<endl;
						cin>>procedencia;
						cout<<"Ingrese apodo del jugador: "<<endl;
						cin>>apodo;
						cout<<"Ingrese dinero del jugador: "<<endl;
						cin>>dinero;
						Persona* jugador = new Jugador(nombre,edad,numero_id,procedencia,apodo,dinero,"Sin mesa");
						personas.push_back(jugador);
						break;
					}//Fin Case 3 agregar
				}
				break;
			}//FIN CASE 1
			case 2:{
				string name;
				string id;
				cout<<"Bienvenido a la autenticacion!"<<endl;
				cout<<"Nombre: ";
				cin>>name;
				cout<<"Identidad: ";
				cin>>id;
				int tipo=0;//0 Nada |1 Admin | 2 Jugador
				int posicion_user;
				for (int i = 0; i < personas.size(); i++)
				{
					if((personas[i]->getNombre()==name)&&(personas[i]->getNumero_id()==id)){
						if(typeid(*personas[i])==typeid(Administrador)){
							posicion_user=i;
							tipo=1;
							cout<<"Entro un admin!"<<endl;
						}
						if(typeid(*personas[i])==typeid(Jugador)){
							posicion_user=i;
							tipo=2;
							cout<<"Entro un jugador!"<<endl;
						}
						if(tipo==1){
							bool salir=false;
							while (!salir) {
								switch (menuAdministrador()) {
									case 1:{
										int cant_repartidores=0;
										int cant_jugadores=0;
										for (int i = 0; i < personas.size(); ++i)
										{
											if(typeid(*personas[i])==typeid(Repartidor)){
												Repartidor* repartidor = dynamic_cast<Repartidor*>(personas[i]);
												if(repartidor->getEstado()=="Sin mesa"){
													cant_repartidores++;
												}												
											}
											if(typeid(*personas[i])==typeid(Jugador)){
												Jugador* jugador = dynamic_cast<Jugador*>(personas[i]);
												if(jugador->getEstado()=="Sin mesa"){
													cant_jugadores++;
												}
											}
										}
										if((cant_repartidores>=1)&&(cant_jugadores>=1)){
											int numero;
											string tipo;
											cout<<"Numero de mesa: ";
											cin>>numero;
											cout<<"Tipo de mesa: ";
											cin>>tipo;
											int pos1,pos2;
											cout<<"Posicion del repartidor: ";
											cin>>pos1;
											cout<<"Posicion del jugador: ";
											cin>>pos2;
											Repartidor* repartidor = dynamic_cast<Repartidor*>(personas[pos1]);
											Jugador* jugador = dynamic_cast<Jugador*>(personas[pos2]);
											Mesa_Blackjack* mesa = new Mesa_Blackjack(numero,tipo,repartidor,jugador);
											mesas.push_back(mesa);
											repartidor->setEstado("Con mesa");
											jugador->setEstado("Con mesa");													
										}else{
											cout<<"No hay suficientes personas disponibles"<<endl;
										}
										break;
									}//fin case 1
									case 2:{
										//mod
										if(mesas.size()>=1){
											int pos;
											cout<<"Ingrese la posicion de la mesa que desea modificar: "<<endl;
											cin>>pos;
											mesas[pos]->getRepartidor()->setEstado("Sin mesa");
											mesas[pos]->getJugador()->setEstado("Sin mesa");
											int numero;
											string tipo;
											cout<<"Nuevo numero de mesa: ";
											cin>>numero;
											cout<<"Nuevo tipo de mesa: ";
											cin>>tipo;
											int pos1,pos2;
											cout<<"Posicion del repartidor: ";
											cin>>pos1;
											cout<<"Posicion del jugador: ";
											cin>>pos2;
											mesas[pos]->setNumero(numero);
											mesas[pos]->setTipo(tipo);
											Repartidor* repartidor = dynamic_cast<Repartidor*>(personas[pos1]);
											Jugador* jugador = dynamic_cast<Jugador*>(personas[pos2]);
											mesas[pos]->setRepartidor(repartidor);
											mesas[pos]->setJugador(jugador);
											repartidor->setEstado("Con mesa");
											jugador->setEstado("Con mesa");	
										}else{
											cout<<"No hay mesas creadas. No puede modificar"<<endl;
										}
										break;
									}//fin case 2
									case 3:{
										int pos;
										cout<<"Ingrese la posicion de la mesa que desea eliminar: "<<endl;
										cin>>pos;
										mesas[pos]->getRepartidor()->setEstado("Sin mesa");
										mesas[pos]->getJugador()->setEstado("Sin mesa");
										mesas.erase(mesas.begin()+pos);
										break;
									}//fin case 3
									case 4:{
										salir=true;
										break;
									}//fin case 4
								}
							}
						}
						if(tipo==2){

						}
					}	
				}
				break;
			}//FIN CASE 2
			case 3:{

				break;
			}//FIN CASE 3
			case 4:{
				cout<<"\n";
				cout<<"Listando..."<<endl;
				cout<<"\n";
				for (int i = 0; i < personas.size(); i++)
				{
					personas[i]->mostrar();
					cout<<"\n";
				}
				break;
			}//FIN CASE 4
			case 5:{
				cout<<"\n";
				cout<<"Listando..."<<endl;
				cout<<"\n";
				for (int i = 0; i < mesas.size(); i++)
				{
					mesas[i]->listar();
					cout<<"\n";
				}
				break;
			}//FIN CASE 6
			case 6:{
				salir=true;
				break;
			}//FIN CASE 6
			return 0;
		}//Fin swtich
	}//Fin While
}//Fin Main

int menu() {
	int opcion;
	bool valido = false;
	do {
		cout << "-----MENU-----" << endl
		<< "1.- Agregar Personas" << endl
		<< "2.- Autenticacion" << endl
		<< "3.- Jugar Blackjack" << endl
		<< "4.- Listar Personas" << endl
		<< "5.- Listar Mesas" << endl
		<< "6.- Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin>>opcion;
		if (opcion > 0 && opcion <= 6)
			valido = true;
		else {
			cout << "Opcion no valida, intente de nuevo..." << endl;
		}

	} while (!valido);
	return opcion;
}

int menuAgregarPersona() {
	int opcion;
	bool valido = false;
	do {
		cout << "-----MENU AGREGAR-----" << endl
		<< "1.- Administrador" << endl
		<< "2.- Repartidor" << endl
		<< "3.- Jugador" << endl;
		cout << "Ingrese una opcion: ";
		cin>>opcion;
		if (opcion > 0 && opcion <= 3)
			valido = true;
		else {
			cout << "Opcion no valida, intente de nuevo..." << endl;
		}

	} while (!valido);
	return opcion;
}

int menuAdministrador() {
	int opcion;
	bool valido = false;
	do {
		cout << "-----MENU ADMINISTRADOR-----" << endl
		<< "1.- Crear Mesa" << endl
		<< "2.- Modificar Mesa" << endl
		<< "3.- Eliminar Mesa" << endl
		<< "4.- Log out" << endl;
		cout << "Ingrese una opcion: ";
		cin>>opcion;
		if (opcion > 0 && opcion <= 4)
			valido = true;
		else {
			cout << "Opcion no valida, intente de nuevo..." << endl;
		}

	} while (!valido);
	return opcion;
}

Baraja generador_Barajas(){
	Baraja baraja;
	Carta carta;
	string valor="";
	string simbolo="";
	string color="";
	for (int i = 0; i < 13; ++i)
	{
		color="Negro";
		simbolo="♠";
		if(i==0){
			valor="A";
		}
		if(i>=1&&i<=9){
			valor=i;
		}
		if(i==10){
			valor="J";
		}
		if(i==11){
			valor="Q";
		}
		if(i==12){
			valor="K";
		}
		baraja.addCarta(carta);
	}
	for (int i = 0; i < 13; ++i)
	{
		color="Rojo";
		simbolo="♦";
		if(i==0){
			valor="A";
		}
		if(i>=1&&i<=9){
			valor=i;
		}
		if(i==10){
			valor="J";
		}
		if(i==11){
			valor="Q";
		}
		if(i==12){
			valor="K";
		}
		baraja.addCarta(carta);	
	}
	for (int i = 0; i < 13; ++i)
	{
		color="Negro";
		simbolo="♣";
		if(i==0){
			valor="A";
		}
		if(i>=1&&i<=9){
			valor=i;
		}
		if(i==10){
			valor="J";
		}
		if(i==11){
			valor="Q";
		}
		if(i==12){
			valor="K";
		}
		baraja.addCarta(carta);	
	}
	for (int i = 0; i < 13; ++i)
	{
		color="Rojo";
		simbolo="♥";
		if(i==0){
			valor="A";
		}
		if(i>=1&&i<=9){
			valor=i;
		}
		if(i==10){
			valor="J";
		}
		if(i==11){
			valor="Q";
		}
		if(i==12){
			valor="K";
		}
		baraja.addCarta(carta);	
	}
	return baraja;
}