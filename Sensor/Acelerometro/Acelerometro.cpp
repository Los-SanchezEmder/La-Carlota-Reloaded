/* 
 * File:   Acelerometro.cpp
 * Author: fabricio
 * 
 * Created on 27 de marzo de 2015, 16:54
 */

#include "Acelerometro.h"

Acelerometro::Acelerometro():Sensor(3){
    
}

std::ostream& operator<<(std::ostream& co, Acelerometro& cd) {
    Dato ultimodato = cd.UltimaMedicion();
    for (int i = 0; i < 3; i++)
        co << ultimodato.GetDato(i) << std::endl;
    co << ultimodato.GetFecha()<< std::endl;
    co << std::endl;
    return co;
}

Acelerometro::Acelerometro(const Acelerometro& orig):Sensor(3) {
}

Acelerometro::~Acelerometro() {
}

