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

struct DatosSensores {
    Dato3f datoAcc;
    Dato6i datoRTC;
    float datoTemp;
    friend std::ostream& operator<<(std::ostream& co ,DatosSensores& medicion );
    friend std::ofstream& operator<<(std::ofstream& co ,DatosSensores& medicion );
    friend std::ifstream& operator>>(std::ifstream& cin ,DatosSensores& aux );
    
};

/** \fn 
 * \brief 
 * \param
 * \return  */
bool SortX(const DatosSensores& b1, const DatosSensores& b2);

/** \fn 
 * \brief 
 * \param
 * \return  */
bool SortY(const DatosSensores& b1, const DatosSensores& b2);

/** \fn 
 * \brief 
 * \param
 * \return  */
bool SortZ(const DatosSensores& b1, const DatosSensores& b2);

/** \fn 
 * \brief 
 * \param
 * \return  */
bool SortTemp(const DatosSensores& b1, const DatosSensores& b2);

class FRDM_Datalogger {
public:
    FRDM_Datalogger();

    /** \fn 
     * \brief 
     * \param
     * \return  */
    FRDM_Datalogger(char* dispositivo);

    /** \fn 
     * \brief 
     * \param
     * \return  */
    FRDM_Datalogger(const FRDM_Datalogger& orig);

    /** \fn 
     * \brief 
     * \param
     * \return  */
    std::vector<DatosSensores> TodasMediciones() {
        return mediciones;
    };

    /** \fn 
     * \brief 
     * \param
     * \return  */
    std::vector<DatosSensores> BusquedaAccPorcentual(float porcentaje);

    /** \fn 
     * \brief 
     * \param
     * \return  */
    std::vector<DatosSensores> BusquedaTempMayor(float temperatura);
    void MuestraMediciones();
   
    
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

    void AgregaDatos(std::vector<DatosSensores> aux);
    
   
    virtual ~FRDM_Datalogger();


private:
    //
    Acelerometro acc1;

    //
    Date RTC;

    //
    Temperatura temp1;

    //
    std::vector<DatosSensores> mediciones;

};


#endif /* FRDM_DATALOGGER_H */

