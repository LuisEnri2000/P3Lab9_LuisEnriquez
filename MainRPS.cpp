
// Main alv :v
// LIT
#include <iostream>
#include "Jugador.cpp"
#include "HiloBatallas.cpp"
#include "HiloDinero.cpp"
#include "HiloVida.cpp"
#include <CONIO.H>

using namespace std;

int main() {
	
	string nombre;
	cout << "Ingresa tu nombre: ";
	cin >> nombre;
	cout << endl;
	
	Jugador * jug = new Jugador();
	jug->setNombre(nombre);
	
	HiloBatallas hiloB;
	hiloB.setJugador(jug);
	hiloB.run();
	HiloDinero hiloD;
	hiloD.setJugador(jug);
	hiloD.run();
	HiloVida hiloV;
	hiloV.setJugador(jug);
	hiloV.run();
	
	// Iniciar hilos
	int ganadas = 0;
	int atk, def;
	int op = 0;
		
	while (op != 3 and jug->getVida() > 0) {
		
		if (jug->getBatalla()) {
			ganadas = 0;
			
			cout << "..:: NUEVO COMBATE ::.." << endl;
			
			while (ganadas != jug->getNivel() and jug->getVida() > 0) {
				cout << "1. Piedra\n";
				cout << "2. Papel\n";
				cout << "3. Tijera\n";
				cout << "Ingresa tu opcion: ";
				cin >> atk;
				def = (rand() % 3) + 1;	
				
				if (atk == 1) { // El escogio piedra
					if (def == 1) {
						cout << "EMPATE! Sigan!" << endl;
					}
					if (def == 2) { 
						cout << "Perdiste el round!" << endl;
						jug->perder();
					}
					if (def == 3) {
						cout << "Ganaste el round!" << endl;
						ganadas++;
					}
				}
				
				if (atk == 2) {
					if (def == 1) {
						cout << "Ganaste el round!" << endl;
						ganadas++;
					}
					if (def == 2) {
						cout << "EMPATE! Sigan!" << endl;
					}
					if (def == 3) {
						cout << "Perdiste el round!" << endl;
						jug->perder();
					}
				}
				
				if (atk == 3) {
					if (def == 1) {
						cout << "Perdiste el round!" << endl;
						jug->perder();
					}
					if (def == 2) {
						cout << "Ganaste el round!" << endl;
						ganadas++;
					}
					if (def == 3) {
						cout << "EMPATE! Sigan!" << endl;
					}
				}
				
				system("pause");
				system("CLS");
			}
			
			if (jug->getVida() > 0) {
				// Gano
				cout << "GANASTE! Subes de nivel! \n+1 de vida maxima" << endl;
				jug->subirLVL();

			}else{
				// Perdio
				cout << "OOF! Perdiste!" << endl;
			}
			
			system("pause");
			system("CLS");
			jug->setBatalla(false);
		}else{
			cout << "MENU" << endl;
			cout << "1> Datos del jugador" << endl;
			cout << "2> Curar vida ($1)" << endl;
			cout << "3> Salir" << endl;
			cout << "Opcion: ";
			cin >> op;
			
			system("CLS");
			
			if (op == 1) {
				cout << "DATOS" << endl;
				cout << "Nivel: " << jug->getNivel() << endl;
				cout << "$ " << jug->getDinero() << endl;
				cout << "Vida: " << jug->getVida() << "/" << jug->getVidaMax();
				cout << endl;
				system("pause");
			}
			
			if (op == 2) {
				if (jug->getDinero() > 0) {
					if (jug->getVida() < jug->getVidaMax()) {
						// agregar 1 de dinero
						jug->addVida();
						cout << "Compraste 1 de HP!" << endl;
						cout << "-$1" << endl;
					}else{
						cout << "Ya estas en tu vida maxima!" << endl;
					}
					
				}else{
					cout << "No tienes dinero suficiente!" << endl;
				}
				
				system("pause");
			}
			
			system("CLS");
		}
				
	}
	
	
	jug->~Jugador();
	
	hiloB.stop();
	hiloD.stop();
	hiloV.stop();
	
	cout << "FIN DEL JUEGO" << endl;
		
	cout << "Nivel: " << jug->getNivel() << endl;
	cout << "$ " << jug->getDinero() << endl;
	cout << "Vida: " << jug->getVida() << "/" << jug->getVidaMax();
	cout << endl;
	system("pause");

}
