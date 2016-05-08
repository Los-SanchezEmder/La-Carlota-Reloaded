/* 
 * File:   Acelerometro.cpp
 * Author: fabricio
 * 
 * Created on 27 de marzo de 2015, 16:54
 */

#include "Acelerometro.h"
#include "../Sensor.h"
#include <iostream>

Acelerometro::Acelerometro() : Sensor() {
}

Acelerometro::Acelerometro(const Acelerometro& orig) : Sensor() {
}

Acelerometro::~Acelerometro() {
}


void Acelerometro::ObtengoDatos(Dato3f& dato) {
    
    dato.x = Lectura("sax");
    dato.y = Lectura("say");
    dato.z = Lectura("saz");

}

std::ostream& operator<< (std::ostream& co,Dato3f& datoAcc){
	
        co << datoAcc.x << "\t";
        co << datoAcc.y<< "\t";
	co << datoAcc.z;
	
	return co;
}

