/* 
 * File:   Date.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 18:13
 */

#ifndef DATE_H
#define	DATE_H

#include <iostream>
#include <fstream>
#include "PortSerial/PortSerial.h"
#include "Sensor/Sensor.h"
#include "ctime"
#include <time.h>


struct Dato6i{
    int segundos;
    int minutos;
    int horas;
    int dias;
    int meses;
    int anios;
    friend std::ostream& operator<< (std::ostream& co,Dato6i& datoRTC);
    friend std::ofstream& operator<< (std::ofstream& co,Dato6i& datoRTC);
    friend std::ifstream& operator>> (std::ifstream& cin,Dato6i& datoRTC);
    
};

class Date : public Sensor{
public:
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Date();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void SetDateFromPC(Dato6i& dato);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void SetDateFromRTC(Dato6i& dato);
    void CheckRTC();

    /** \fn 
    * \brief 
    * \param
    * \return  */
    virtual ~Date();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    friend  std::ostream operator<< (std::ostream&, Date&);

private:

};

#endif	/* DATE_H */
