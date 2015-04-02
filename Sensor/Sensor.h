/* 
 * File:   Sensor.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:28
 */

#ifndef SENSOR_H
#define	SENSOR_H
#include "Dato.h"
#include "../PortSerial/PortSerial.h"

class Sensor {
public:
    Sensor();
    Sensor(int cDatos){
        cMediciones = 0;
        cDatosSensor = cDatos;
       
    };


    Sensor(const Sensor& orig);
    
    void AbrirPuerto(int argc, char** argv){
         static PortSerial Adquiridor(argc,argv);
    }
    virtual ~Sensor();
private:
    Dato *medicion;
    int cMediciones;
    int cDatosSensor;
    

protected:

    float Lectura(std::string cd) {
        float valor;
        valor = Adquiridor.ReadSensor(cd);
        return valor;
    };

    void NuevaMedicion(float Medicion[]) {
        medicion = new Dato(cDatosSensor, Medicion);
        cMediciones++;
    };
};

#endif	/* SENSOR_H */

