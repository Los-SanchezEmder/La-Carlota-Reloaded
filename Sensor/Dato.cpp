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

    Dato::Dato(int& cVariables, float medicion[] ){
        this->cVariables =cVariables; 
        this->Medicion = new float[this->cVariables];
        for(int i=0;i< this->cVariables;i++)
            this->Medicion[i]= medicion[i];
        //this->fecha = fecha;
    }

Dato::Dato(const Dato& orig) {
        this->fecha = orig.fecha;
        this->cVariables = orig.cVariables;
        this->Medicion = orig.Medicion;
}
 Dato& Dato::operator= (const Dato& cd){
        this->fecha = cd.fecha;
        this->cVariables = cd.cVariables;
        this->Medicion = cd.Medicion;
        return *this;
        
    };

Dato::~Dato() {
}

