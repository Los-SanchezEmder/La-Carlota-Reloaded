/* 
 * File:   Sensor.cpp
 * Author: fabricio
 * 
 * Created on 25 de marzo de 2015, 17:28
 */

#include "Sensor.h"
#include "Dato.h"
#include <iostream>
#include <vector>
#include <bits/stringfwd.h>
#include "../PortSerial/PortSerial.h"
#include <stdio.h>

Sensor::Sensor() {
}
Sensor::Sensor(int cDatos) {
        medicion.resize(200);
        cMediciones = 0;
        cDatosSensor = cDatos;
        
}
Sensor::Sensor(const Sensor& orig) {
}
Sensor::~Sensor() {
}
std::vector<int> Sensor::Busqueda(float porcentaje) {
        float limiteSuperior = (100 + porcentaje)/100;
        float limiteInferior = (100 - porcentaje)/100;
        std::cout << "defini limites de busqueda!!!" << std::endl;
        std::cout << limiteSuperior << std::endl;
        std::cout << limiteInferior << std::endl;
        std::vector<int> indices;
        std::vector<int>::const_iterator cii;
        //float ultimoDato[cDatosSensor];
        //for(int i = 0; i< cDatosSensor; i++){
        //    ultimoDato[i]=medicion[0].GetDato(i);
        //}
        
        for(int i=1; i< cMediciones; i++){
            for (int j = 0; j < cDatosSensor; j++) {
                
                float uno= fabs(medicion[i-1].GetDato(j) * limiteInferior);
                float dos= fabs(medicion[i-1].GetDato(j) * limiteSuperior);                
                float comparacion = fabs(medicion[i].GetDato(j));
                
                //float uno= fabs(ultimoDato[j] * limiteInferior);
                //float dos= fabs(ultimoDato[j] * limiteSuperior);                
                //float comparacion = fabs(medicion[i].GetDato(j));
                
                if ((comparacion <= uno) || (comparacion >= dos)) {
                    //encontre un dato con las caracteristicas que busco
                    //  Guardo hubicacion del dato
                    indices.push_back(i); 
                    break;
                }

                
            }
            //for (int z = 0; z < cDatosSensor; z++) {
            //    ultimoDato[z] = medicion[i].GetDato(z);
            //}
            //Despues del break
        }
         //Termino busqueda, dentro de busqueda
        return indices;
    }


float Sensor::Lectura(std::string cd) {
    float valor;
    valor = Placa->ReadSensor(cd);
    return valor;
};

void Sensor::Escritura(unsigned long tsegundos) {
    Placa->WriteSensor(tsegundos);
}

void Sensor::NuevaMedicion(float Medicion[]) {
        Dato *nMedicion;
        nMedicion = new Dato(cDatosSensor, Medicion);
        cMediciones++;
        medicion[cMediciones]= *nMedicion;
        
    }
