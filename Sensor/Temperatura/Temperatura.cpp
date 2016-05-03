/* 
 * File:   temperatura.cpp
 * Author: richisan
 * 
 * Created on 18 de mayo de 2015, 23:08
 */

#include "Temperatura.h"
#include "../Sensor.h"
#include "../Dato.h"
#include <iostream>


Temperatura::Temperatura() : Sensor() {
}

Temperatura::Temperatura(const Temperatura& orig) : Sensor() {
}

Temperatura::~Temperatura() {
}



void Temperatura::ObtengoDatos(float& dato) {
    dato = Lectura("tem");
}