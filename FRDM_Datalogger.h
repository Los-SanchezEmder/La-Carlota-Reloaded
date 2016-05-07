/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FRDM_Datalogger.h
 * Author: fabricio
 *
 * Created on 26 de abril de 2016, 21:30
 */

#ifndef FRDM_DATALOGGER_H
#define FRDM_DATALOGGER_H

#include "Sensor/Acelerometro/Acelerometro.h"
#include "PortSerial/PortSerial.h"
#include "Date.h"
#include "Sensor/Temperatura/Temperatura.h"

#include <iostream>
#include <algorithm>
#include <vector>

struct DatosSensores{
    Dato3f datoAcc;
    Dato6i datoRTC;
    float datoTemp;
    
};

bool SortX(const DatosSensores& b1, const DatosSensores& b2);
bool SortX(const DatosSensores& b1, const DatosSensores& b2);
bool SortX(const DatosSensores& b1, const DatosSensores& b2);
bool SortX(const DatosSensores& b1, const DatosSensores& b2);

class FRDM_Datalogger {
public:
    FRDM_Datalogger();
    FRDM_Datalogger(char* dispositivo);
    FRDM_Datalogger(const FRDM_Datalogger& orig);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    //friend std::ostream& operator<<(std::ostream& co, FRDM_Datalogger& cd);
    
    std::vector<DatosSensores> TodasMediciones(){return mediciones;};
    
    
    std::vector<DatosSensores> BusquedaAccPorcentual(float porcentaje);
    std::vector<DatosSensores> BusquedaTempMayor(float temperatura);
    
    //void OrdenarX(std::vector<DatosSensores>& Datos);
    
    //template<typename _Funcion>
    //void Ordenar(std::vector<DatosSensores>& AOrdenar, _Funcion AImplementar);
    /*
    void OrdenarAccX(DatosSensores& Datos, bool funcion);
    void OrdenarAccY(DatosSensores& Datos, bool funcion);
    void OrdenarAccZ(DatosSensores& Datos, bool funcion);
    void OrdenarTemp(DatosSensores& Datos, bool funcion);
     */
    
    void RealizarMediciones(int cantidad);
    virtual ~FRDM_Datalogger();


private:
    
    Acelerometro acc1;
    Date RTC;
    Temperatura temp1;

    
    
    std::vector<DatosSensores> mediciones;
    
};

#endif /* FRDM_DATALOGGER_H */

