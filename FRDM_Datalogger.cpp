/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.cpp
 * Author: fabricio
 * 
 * Created on 26 de abril de 2016, 21:30
 */

#include "FRDM_Datalogger.h"

FRDM_Datalogger::FRDM_Datalogger() {
}

FRDM_Datalogger::FRDM_Datalogger(char* dispositivo) {
    PortSerial *FRDM;
    FRDM = new PortSerial(dispositivo);
    acc1.AsignarPlaca(FRDM);
    RTC.AsignarPlaca(FRDM);
    temp1.AsignarPlaca(FRDM);
    
    RTC.CheckRTC();
    
}

FRDM_Datalogger::FRDM_Datalogger(const FRDM_Datalogger& orig) {
}

void FRDM_Datalogger::RealizarMediciones(int cantidad){
    DatosSensores aux;
    for (int i = 0; i < cantidad; i++) {
            
        acc1.ObtengoDatos(aux.datoAcc);
        temp1.ObtengoDatos(aux.datoTemp);
        RTC.SetDateFromRTC(aux.datoRTC);
        
        mediciones.push_back(aux);
        
    }
    
}

std::vector<DatosSensores> FRDM_Datalogger::BusquedaAccPorcentual(float porcentaje) {
    
    float limiteSuperior = (100 + porcentaje) / 100;
    float limiteInferior = (100 - porcentaje) / 100;
    
    std::vector<DatosSensores> resultados;

    for (int i = 1; i < mediciones.size(); i++) {


        float uno = fabs(mediciones[i - 1].datoAcc.x * limiteInferior);
        float dos = fabs(mediciones[i - 1].datoAcc.x * limiteSuperior);
        float comparacion = fabs(mediciones[i].datoAcc.x);

        if ((comparacion <= uno) || (comparacion >= dos)) {
            //encontre un dato con las caracteristicas que busco
            //  Guardo el dato
            resultados.push_back(mediciones[i]);
            uno = fabs(mediciones[i - 1].datoAcc.y * limiteInferior);
            dos = fabs(mediciones[i - 1].datoAcc.y * limiteSuperior);
            comparacion = fabs(mediciones[i].datoAcc.y);
        }
        else if ((comparacion <= uno) || (comparacion >= dos)) {
            //encontre un dato con las caracteristicas que busco
            //  Guardo el dato
            resultados.push_back(mediciones[i]);

            uno = fabs(mediciones[i - 1].datoAcc.z * limiteInferior);
            dos = fabs(mediciones[i - 1].datoAcc.z * limiteSuperior);
            comparacion = fabs(mediciones[i].datoAcc.z);

        }            // Chequeo eje Z
        else if ((comparacion <= uno) || (comparacion >= dos)) {
            //encontre un dato con las caracteristicas que busco
            //  Guardo el dato
            resultados.push_back(mediciones[i]);
        }
    }
    //Termino busqueda
    return resultados;
}

std::vector<DatosSensores> FRDM_Datalogger::BusquedaTempMayor(float temperatura) {

    std::vector<DatosSensores> resultados;

    for (int i = 1; i < mediciones.size(); i++) {

        if (temperatura < mediciones[i].datoTemp) {
            resultados.push_back(mediciones[i]);
        }

    }
    //Termino busqueda, dentro de busqueda
    return resultados;
}

bool SortX(const DatosSensores& b1, const DatosSensores& b2) {
	//return (b1.GetV() < b2.GetV());
	return (b1.datoAcc.x > b2.datoAcc.x);
}

bool SortY(const DatosSensores& b1, const DatosSensores& b2) {
	//return (b1.GetY() < b2.GetY());
	return (b1.datoAcc.y > b2.datoAcc.y);
}

bool SortZ(const DatosSensores& b1, const DatosSensores& b2) {
	//return (b1.GetV() < b2.GetV());
	return (b1.datoAcc.z > b2.datoAcc.z);
}

bool SortTemp(const DatosSensores& b1, const DatosSensores& b2) {
	//return (b1.GetY() < b2.GetY());
	return (b1.datoTemp > b2.datoTemp);
}


FRDM_Datalogger::~FRDM_Datalogger() {
}


std::ostream& operator<<(std::ostream& co, DatosSensores& medicion){
    co << medicion.datoRTC << "\t" << medicion.datoAcc << "\t" << medicion.datoTemp << std::endl;
    return co;
}

