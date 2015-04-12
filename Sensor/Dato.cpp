/* 
 * File:   Dato.cpp
 * Author: fabricio
 * 
 * Created on 25 de marzo de 2015, 17:36
 */

#include "Dato.h"
#include "Acelerometro/Acelerometro.h"

Dato::Dato() {
    
}

Dato::Dato(const Dato& orig) {
        this->fecha = orig.fecha;
        this->cVariables = orig.cVariables;
        this->Medicion = orig.Medicion;
}


Dato::~Dato() {
}

