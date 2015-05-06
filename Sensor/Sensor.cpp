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
#include "../PortSerial/PortSerial.h"

Sensor::Sensor() {
}

Sensor::Sensor(int cDatos) {
    cMediciones = 0;
    cDatosSensor = cDatos;
}

Sensor::Sensor(const Sensor& orig) {
}

Sensor::~Sensor() {
}

void Sensor::AsignarPlaca(PortSerial *DDD) {
    this->Placa = DDD;
}

Dato Sensor::UltimaMedicion() {
    return this->medicion[(this->cMediciones) - 1];

}

Dato Sensor::Medicion(int indice) {
    return this->medicion[indice];
}

std::vector<int> Sensor::Busqueda(float porcentaje) {
    float limiteSuperior = (100 + porcentaje) / 100;
    float limiteInferior = (100 - porcentaje) / 100;

    std::vector<int> indices;
    std::vector<int>::const_iterator cii;
    float ultimoDato[cDatosSensor];

    for (int i = 0; i < cDatosSensor; i++) {
        ultimoDato[i] = medicion[0].GetDato(i);
    }

    std::cout << cMediciones << std::endl;

    for (int i = 1; i < cMediciones; i++) {

        for (int j = 0; j < cDatosSensor; j++) {

            float uno = ultimoDato[j] * limiteInferior;
            float dos = ultimoDato[j] * limiteSuperior;
            std::cout << "límites de búsqueda:" << std::endl;
            std::cout << uno << std::endl;
            std::cout << dos << std::endl;
            Dato prueba = medicion[i];

            float comparacion1 = prueba.GetDato(i);
            float comparacion2 = prueba.GetDato(i);
            std::cout << "justo antes del if" << std::endl;
            if ((comparacion1 <= uno) || (comparacion2 >= dos)) {
                //encontre un dato con las caracteristicas que busco

                indices.push_back(i); // = new std::vector(i);

                break;
            }
            for (int z = 0; z < cDatosSensor; z++) {
                ultimoDato[z] = medicion[i].GetDato(z);
            }


        }


    }
    return indices;
}

void Sensor::Impresion() {
    for (int k = 0; k < cMediciones; k++) {
        std::cout << cMediciones << std::endl;
        std::cout << std::endl;

        for (int l = 0; l < 3; l++) {

            float probe = this->medicion[k].GetDato(l);
            std::cout << "dato: " << probe << std::endl;
        }
    }
}

float Sensor::Lectura(std::string cd) {
    float valor;
    valor = Placa->ReadSensor(cd);
    return valor;
};

void Sensor::NuevaMedicion(float Medicion[]) {
    medicion = new Dato(cDatosSensor, Medicion);
    cMediciones++;
};