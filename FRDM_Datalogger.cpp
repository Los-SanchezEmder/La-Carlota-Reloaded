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

/*
std::ostream& operator<<(std::ostream& co, FRDM_Datalogger& cd) {
    
    this->
    co << "X :" << acc1-><< endl;
    co << "Y :" << acc1.y(dominguito[i]) << endl;
    co << "Z :" << acc1.z(dominguito[i])<< endl;
    co << "temperatura: " << temp1.Temp(dominguito[i]) << endl;
    //-- RTC --
    acc1.
    co << RTC.horas(dominguito[i])<<':';
    co << RTC.minutos(dominguito[i]) <<':';
    co << RTC.segundos(dominguito[i]) << endl;
    co << RTC.dias(dominguito[i]) <<'/';
    co << RTC.meses(dominguito[i]) <<'/';
    co << RTC.anos(dominguito[i]) << endl;

    return co;
}
 */

std::vector<DatosSensores> FRDM_Datalogger::BusquedaAccPorcentual(float porcentaje) {
    float limiteSuperior = (100 + porcentaje) / 100;
    float limiteInferior = (100 - porcentaje) / 100;
    std::cout << "defini limites de busqueda!!!" << std::endl;
    std::cout << limiteSuperior << std::endl;
    std::cout << limiteInferior << std::endl;
    std::vector<DatosSensores> resultados;


    for (int i = 1; i < mediciones.size(); i++) {

        float uno = fabs(mediciones[i - 1].datoAcc.x * limiteInferior);
        float dos = fabs(mediciones[i - 1].datoAcc.x * limiteSuperior);
        float comparacion = fabs(mediciones[i].datoAcc.x);

        if ((comparacion <= uno) || (comparacion >= dos)) {
            //encontre un dato con las caracteristicas que busco
            //  Guardo hubicacion del dato
            resultados.push_back(mediciones[i]);
            break;
        }

        // Chequeo eje Y

        uno = fabs(mediciones[i - 1].datoAcc.y * limiteInferior);
        dos = fabs(mediciones[i - 1].datoAcc.y * limiteSuperior);
        comparacion = fabs(mediciones[i].datoAcc.y);

        if ((comparacion <= uno) || (comparacion >= dos)) {
            //encontre un dato con las caracteristicas que busco
            //  Guardo hubicacion del dato
            resultados.push_back(mediciones[i]);
            break;
        }

        // Chequeo eje Z

        uno = fabs(mediciones[i - 1].datoAcc.z * limiteInferior);
        dos = fabs(mediciones[i - 1].datoAcc.z * limiteSuperior);
        comparacion = fabs(mediciones[i].datoAcc.z);

        if ((comparacion <= uno) || (comparacion >= dos)) {
            //encontre un dato con las caracteristicas que busco
            //  Guardo hubicacion del dato
            resultados.push_back(mediciones[i]);
            break;
        }

    }
    //Termino busqueda, dentro de busqueda
    return resultados;
}

std::vector<DatosSensores> FRDM_Datalogger::BusquedaTempMayor(float temperatura) {

    std::vector<DatosSensores> resultados;

    for (int i = 1; i < mediciones.size(); i++) {
        
        if (temperatura < mediciones[i].datoTemp){
            resultados.push_back(mediciones[i]);
            
        }
        
    }
 
    //Termino busqueda, dentro de busqueda
    return resultados;
}


FRDM_Datalogger::~FRDM_Datalogger() {
}

