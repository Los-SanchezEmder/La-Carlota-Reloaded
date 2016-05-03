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


FRDM_Datalogger::~FRDM_Datalogger() {
}

