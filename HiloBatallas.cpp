
// Hilo batalla

#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include "Jugador.cpp"

#ifndef HILOBATALLAS_CPP
#define HILOBATALLAS_CPP

using namespace std;

class HiloBatallas {
	private:
		
		bool vive;
		string texto;
		int espera;
		int prob;
		int lvl;
		Jugador * jug;
		bool primera;
		
	public:
		Hilo() {
			
		}
		
		void setJugador(Jugador * j) {
			jug = j;
			espera = 10000;
			vive = true;
			lvl = 1;
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
			_beginthread(&HiloBatallas::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o) {
			static_cast<HiloBatallas*>(o)->runnerEstatico();
		}
		
		void runnerEstatico() {
			
			while (vive) {
				
				if (!primera) {
					
					if (jug->getBatalla()) {
						// Esta en batalla
					}else{
						srand(time(0));
						prob = rand() % 10 + 1;
						
						if (prob <= 5) {
							jug->setBatalla(true);
						}else{
							jug->setBatalla(false);
						}	
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
