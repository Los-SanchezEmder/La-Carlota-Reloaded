/* 
 * File:   Acelerometro.h
 * Author: fabricio
 *
 * Created on 27 de marzo de 2015, 16:54
 */

#ifndef ACELEROMETRO_H
#define	ACELEROMETRO_H
#include "../Sensor.h"

class Acelerometro:public Sensor{
public:
    Acelerometro();
    
    Acelerometro(const Acelerometro& orig);
    void ObtengoDatos(){
        std::string sh[3]={"sax", "say", "saz"};
        float medicion[3];
        for (int i=0; i<3; i++)
            medicion[i] = Lectura(sh[i]);
        NuevaMedicion(medicion);
    }
    virtual ~Acelerometro();
private:

};

#endif	/* ACELEROMETRO_H */

