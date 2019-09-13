
#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include "Jugador.cpp"

#ifndef HILOVIDA_CPP
#define HILOVIDA_CPP

using namespace std;

class HiloVida {
	private:
		
		bool vive;
		bool primera;
		string texto;
		int espera;
		int prob;
		Jugador * jug;
		
	public:
		Hilo(Jugador * j) {
			espera = 6000;
			vive = true;
			jug = j;
			primera = true;
		}
		
		void setJugador(Jugador * j) {
			espera = 6000;
			vive = true;
			jug = j;
			primera = true;
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
			_beginthread(&HiloVida::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o) {
			static_cast<HiloVida*>(o)->runnerEstatico();
		}
		
		void runnerEstatico() {
			
			while (vive) {
				
				if (!primera) {
					if (jug->getVida() < jug->getVidaMax() and !(jug->getBatalla())) {
						// agregar 1 de dinero
						jug->addVida();
					}						
				}else{
					primera = false;
				}
					
				
				Sleep(espera);
				if (!vive) {
					_endthread();
				}
			}
			
			//cout << "Se salio del hilo :v" << endl;
		}
		
		
		 
};

#endif
