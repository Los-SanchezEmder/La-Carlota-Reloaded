/* 
 * File:   Sensor.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:28
 */


#ifndef SENSOR_H
#define	SENSOR_H
#include "Dato.h"
#include <vector>
#include <math.h>
#include "../PortSerial/PortSerial.h"

class Sensor {
public:
    Sensor();
    Sensor(int cDatos);
    //friend float ReadSensor(std::string sensor);


    Sensor(const Sensor& orig);
    
 /*   void AbrirPuerto(int argc, char** argv){
         static PortSerial Adquiridor(argc,argv);
    }*/
    virtual ~Sensor();
    void AsignarPlaca(PortSerial *DDD){   this->Placa = DDD;   };
    Dato UltimaMedicion()   {  return medicion[(this->cMediciones)-1];  };
    
    Dato Medicion(int indice){  return medicion[indice];}
    
    std::vector<int> Busqueda(float porcentaje);
private:
    std::vector<Dato> medicion;
    int cMediciones;
    int cDatosSensor;
    PortSerial *Placa;
    

protected:

    float Lectura(std::string cd);

    void NuevaMedicion(float Medicion[]);
};

#endif	/* SENSOR_H */
