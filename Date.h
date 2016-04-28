/* 
 * File:   Date.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 18:13
 */

#ifndef DATE_H
#define	DATE_H

#include <iostream>
#include "PortSerial/PortSerial.h"
#include "Sensor/Dato.h"
#include "Sensor/Sensor.h"
#include "ctime"
#include <time.h>



//dddddd



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
    Date(const Date& orig);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    int GetYear();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void SetDateFromPC();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void SetDateFromRTC();
    void CheckRTC();
    
    //void CheckRTC();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Date& operator= (const Date&);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    virtual ~Date();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    friend  std::ostream& operator<< (std::ostream&, Date&);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float segundos(int &i){return Medicion(i).GetDato(0);};
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float minutos(int &i){return Medicion(i).GetDato(1);};
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float horas(int &i){return Medicion(i).GetDato(2);};
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float dias(int &i){return Medicion(i).GetDato(3);};
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float meses(int &i){return Medicion(i).GetDato(4);};
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float anos(int &i){return Medicion(i).GetDato(5);};


private:

};

#endif	/* DATE_H */
