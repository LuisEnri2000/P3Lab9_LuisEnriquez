
// Hilo batalla

#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include "Jugador.cpp"

#ifndef HILODINERO_CPP
#define HILODINERO_CPP

using namespace std;

class HiloDinero {
	private:
		
		bool vive;
		string texto;
		int espera;
		int prob;
		bool primera;
		Jugador * jug;
		
	public:
		Hilo(Jugador * j) {
			espera = 7000;
			vive = true;
			primera = true;
			jug = j;
		}
		
		void setJugador(Jugador * j) {
			espera = 7000;
			vive = true;
			primera = true;
			jug = j;
		}
		
		void setVive(bool v) {
			vive = v;
		}
					
		void setEspera(int e) {
			espera = e;
		}
		
		void stop() {
			vive=false;
		}
		
		void run() {
			_beginthread(&HiloDinero::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o) {
			static_cast<HiloDinero*>(o)->runnerEstatico();
		}
		
		void runnerEstatico() {
			
			while (vive) {
				
				if (!primera) {
					if (!(jug->getBatalla())) {
						// agregar 1 de dinero
						jug->addDinero();
					}
				}else{
					primera = false;
				}
					
				
				Sleep(espera);
				if (!vive) {
					_endthread();
				}
			}
			
			cout << "Se salio del hilo :v" << endl;
		}
		
		
		 
};

#endif
