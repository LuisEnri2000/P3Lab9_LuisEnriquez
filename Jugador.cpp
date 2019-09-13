
#include <iostream>
#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <fstream>

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

using namespace std;

class Jugador {
	
	private:
		string nombre;
		int dinero, vida, vidaMax, nivel;
		bool batalla;
		
	public:
		
		Jugador() {
			dinero = 0;
			vida = 1;
			vidaMax = 3;
			nivel = 1;
			batalla = false;
		}
		
		bool getBatalla() {
			return batalla;
		}
		
		bool setBatalla(bool v) {
			batalla = v;
		}
		
		void setNombre(string n) {
			nombre = n;
		}
		
		void addDinero() {
			string texto = "Se sumo +$1 de dinero";
			MessageBox(0,texto.c_str(), "Hey! Listen!", MB_OK);
			dinero ++;
		}
		
		void subirLVL() {
			vidaMax++;
			nivel++;
		}
		
		void perder() {
			vida--;
		}
		
		int getNivel() {
			return nivel;
		}
		
		int getVida() {
			return vida;
		}
		
		int getVidaMax() {
			return vidaMax;
		}
		
		int getDinero() {
			return dinero;
		}
		
		void addVida() {
			
			string texto = "Se sumo +1 de vida";
			MessageBox(0,texto.c_str(), "Hey! Listen!", MB_OK);
			vida++;
			
		}
		
		~Jugador() {
		}
			
};

#endif


