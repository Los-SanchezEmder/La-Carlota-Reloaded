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
#include "../PortSerial/PortSerial.h"

class Sensor {
public:
    Sensor();
    Sensor(int cDatos){
        cMediciones = 0;
        cDatosSensor = cDatos;
       
    };
    //friend float ReadSensor(std::string sensor);


    Sensor(const Sensor& orig);
    
 /*   void AbrirPuerto(int argc, char** argv){
         static PortSerial Adquiridor(argc,argv);
    }*/
    virtual ~Sensor();
    void AsignarPlaca(PortSerial *DDD){
        this->Placa = DDD;
    }
    Dato UltimaMedicion(){
       return this->medicion[(this->cMediciones)-1];
       
    }
    
    Dato Medicion(int indice){
        return this->medicion[indice];
    }
    
    std::vector<int> Busqueda(float porcentaje){
        float limiteSuperior = (100 + porcentaje)/100;
        float limiteInferior = (100 - porcentaje)/100;
        std::vector<int> indices;
        float ultimoDato[cDatosSensor];
        
        for(int i = 0; i< cDatosSensor; i++){
            ultimoDato[i]=medicion[0].GetDato(i);
        }
        
        for(int i=1; i< cMediciones; i++){
            for(int j = 0; j< cDatosSensor; j++){
                if((medicion[i].GetDato(j)<ultimoDato[j]*limiteInferior)||(medicion[i].GetDato(j)>ultimoDato[j]*limiteSuperior)){
                    //encontre un dato con las caracteristicas que busco
                    indices.push_back(i);// = new std::vector(i);
                    break;
                }
                
            }
            
        }
        return indices;
    }
private:
    Dato *medicion;
    int cMediciones;
    int cDatosSensor;
    PortSerial *Placa;
    

protected:

    float Lectura(std::string cd) {
        float valor;
        valor = Placa->ReadSensor(cd);
        return valor;
    };

    void NuevaMedicion(float Medicion[]) {
        medicion = new Dato(cDatosSensor, Medicion);
        cMediciones++;
    };
};

#endif	/* SENSOR_H */

