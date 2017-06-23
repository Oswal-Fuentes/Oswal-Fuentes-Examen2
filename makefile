Main: Main.o Persona.o Administrador.o Jugador.o Repartidor.o Baraja.o Carta.o Mesa_Blackjack.o 
	g++ Main.o Persona.o Administrador.o Jugador.o Repartidor.o Baraja.o Carta.o Mesa_Blackjack.o -o Main

Main.o: Main.cpp Persona.h Administrador.h Jugador.h Repartidor.h Baraja.h Carta.h Mesa_Blackjack.h 
	g++ -c Main.cpp
 
Persona.o: Persona.cpp Persona.h 
	g++ -c Persona.cpp 
 
Administrador.o:  Administrador.h Administrador.cpp Persona.h 
	g++ -c Administrador.cpp 
 
Jugador.o:  Jugador.h Jugador.cpp Persona.h 
	g++ -c Jugador.cpp 
 
Repartidor.o:  Repartidor.h Repartidor.cpp Persona.h 
	g++ -c Repartidor.cpp 
 
Baraja.o: Baraja.cpp Baraja.h 
	g++ -c Baraja.cpp 
 
Carta.o: Carta.cpp Carta.h 
	g++ -c Carta.cpp 
 
Mesa_Blackjack.o: Mesa_Blackjack.cpp Mesa_Blackjack.h 
	g++ -c Mesa_Blackjack.cpp 
 
clean: 
	rm -f *.0 *.main