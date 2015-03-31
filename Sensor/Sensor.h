/* 
 * File:   Sensor.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:28
 */

#ifndef SENSOR_H
#define	SENSOR_H
#include "Dato.h"
class Sensor {
public:
    Sensor();
    Sensor(int cDatos){
        cMediciones = 0;
        cDatosSensor = cDatos;
    };
    void NuevaMedicion(float Medicion[]){
        medicion = new Dato(cDatosSensor, Medicion);
        cMediciones++;
    };
    Sensor(const Sensor& orig);
    virtual ~Sensor();
private:
    Dato *medicion;
    int cMediciones;
    int cDatosSensor;

};

#endif	/* SENSOR_H */

