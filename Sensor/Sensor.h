/* 
 * File:   Sensor.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:28
 */

#ifndef SENSOR_H
#define	SENSOR_H
#include "Dato.h"
#include <iostream>
#include <vector>
#include "../PortSerial/PortSerial.h"

class Sensor {
public:
    Sensor();
    Sensor(int cDatos);
    Sensor(const Sensor& orig);
    virtual ~Sensor();
    void AsignarPlaca(PortSerial *DDD);
    Dato UltimaMedicion();
    Dato Medicion(int indice);
    std::vector<int> Busqueda(float porcentaje);
    void Impresion();

private:
    Dato *medicion; //puntero a medicion
    int cMediciones; // cantidad de mediciones realizadas (total)
    int cDatosSensor; //cantidad de datos del sensor
    PortSerial *Placa;


protected:

    float Lectura(std::string cd);
    void NuevaMedicion(float Medicion[]);
};

#endif	/* SENSOR_H */

