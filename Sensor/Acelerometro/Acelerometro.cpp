/* 
 * File:   Acelerometro.cpp
 * Author: fabricio
 * 
 * Created on 27 de marzo de 2015, 16:54
 */

#include "Acelerometro.h"
#include "../Sensor.h"
#include "../Dato.h"
#include <iostream>

Acelerometro::Acelerometro() : Sensor(3) {
}

Acelerometro::Acelerometro(const Acelerometro& orig) : Sensor(3) {
}

Acelerometro::~Acelerometro() {
}

std::ostream& operator<<(std::ostream& co, Acelerometro& cd) {
    Dato ultimodato = cd.UltimaMedicion();
    for (int i = 0; i < 3; i++)
        co << ultimodato.GetDato(i) << std::endl;
    co << std::endl;
    return co;
}

void Acelerometro::ObtengoDatos() {
    std::string sh[3] = {"sax", "say", "saz"};
    float medicion[3];
    for (int i = 0; i < 3; i++)
        medicion[i] = Lectura(sh[i]);

    NuevaMedicion(medicion);
}