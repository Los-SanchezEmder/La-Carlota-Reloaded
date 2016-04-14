/* 
 * File:   Dato.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:36
 */

#ifndef DATO_H
#define	DATO_H
#include <iostream>

class Dato {
public:
    Dato();
    Dato(int cVariables);
    Dato(const Dato& orig);
    Dato(int& cVariables, float medicion[] );


  
    float GetDato(int indice);

    Dato& operator= (const Dato& cd);
    
    friend std::ostream& operator<<(std::ostream& co, Dato& cd);
    
    virtual ~Dato();
private:

    int cVariables; // cantidad de variables a medir el sensor
    float *Medicion;

};

#endif	/* DATO_H */

