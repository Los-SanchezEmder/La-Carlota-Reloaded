/* 
 * File:   Dato.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:36
 */

#ifndef DATO_H
#define	DATO_H
#include "../Date.h"

class Dato {
public:
    Dato();
    Dato(int cVariables);
    Dato(int& cVariables, float medicion[] ){
        this->cVariables =cVariables; 
        this->Medicion = new float[this->cVariables];
        for(int i=0;i< this->cVariables;i++)
            this->Medicion[i]= medicion[i];
        //this->fecha = fecha;
    }
    Date GetFecha(){ return this->fecha ;}
    
    float GetDato(int indice){
        return this->Medicion[indice];
    }

    //Dato(const Dato& orig);
    Dato& operator= (const Dato& cd){
        this->fecha = cd.fecha;
        this->cVariables = cd.cVariables;
        this->Medicion = cd.Medicion;
        return *this;
        
    };
    virtual ~Dato();
private:
    Date fecha;
    int cVariables;
    float *Medicion;

};

#endif	/* DATO_H */

