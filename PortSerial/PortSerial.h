/* 
 * File:   PortSerial.h
 * Author: fabricio
 *
 * Created on 27 de marzo de 2015, 19:13
 */

#ifndef PORTSERIAL_H
#define	PORTSERIAL_H
#include <SerialPort.h>
#include <string>
#include <vector>
#include <time.h>


class PortSerial {
public:
    //PortSerial();
    /** \fn 
    * \brief 
    * \param ddddd
    * \return  dddddd */
    PortSerial(char* dispositivo);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void Inicializacion();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float ReadSensor(std::string sensor);
    
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void WriteSensor(unsigned long tsegundos);
    virtual ~PortSerial();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    PortSerial& operator=(const PortSerial& cd);

private:
    SerialPort *serial_port;
};

#endif	/* PORTSERIAL_H */

