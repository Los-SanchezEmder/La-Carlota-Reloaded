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
#include "Sensor/Sensor.h"
#include "ctime"
#include <time.h>



//dddddd
struct Dato6i{
    int segundos;
    int minutos;
    int horas;
    int dias;
    int meses;
    int anios;
    
    friend std::ostream& operator<< (std::ostream& co,Dato6i& datoRTC);
    
    /*
    void dato(int i){
      switch(i){
        case 0:
            return segundos;
        case 1:
            return minutos;
          case 2:
              return horas;
              case 
      }  
    };*/
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
    void SetDateFromPC(Dato6i& dato);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void SetDateFromRTC(Dato6i& dato);
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
    friend  std::ostream operator<< (std::ostream&, Date&);
    




private:

};

#endif	/* DATE_H */
