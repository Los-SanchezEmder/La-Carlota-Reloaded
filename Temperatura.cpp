/* 
 * File:   temperatura.cpp
 * Author: richisan
 * 
 * Created on 18 de mayo de 2015, 23:08
 */

#include "Temperatura.h"
#include "Sensor/Sensor.h"
#include "Sensor/Dato.h"
#include <iostream>

Temperatura::Temperatura() : Sensor(1) {
}

Temperatura::Temperatura(const Temperatura& orig) : Sensor(1) {
}

Temperatura::~Temperatura() {
}

std::ostream& operator<<(std::ostream& co, Temperatura& cd) {
    Dato ultimodato = cd.UltimaMedicion();
    co << ultimodato.GetDato(0) << std::endl;
    co << ultimodato.GetFecha() << std::endl;
    co << std::endl;
    return co;
}

void Temperatura::ObtengoDatos() {
    std::string sh = "tem";
    float medicion[1];
    medicion[0] = Lectura(sh);
    NuevaMedicion(medicion);
}