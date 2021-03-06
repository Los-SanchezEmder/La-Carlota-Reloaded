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

class PortSerial {
public:
    PortSerial();
    PortSerial(int& caracteres, char** dispositivo);
    PortSerial(const PortSerial& orig);
    void Inicializacion();
    float ReadSensor(std::string sensor);
    virtual ~PortSerial();
    PortSerial& operator=(const PortSerial& cd);

private:
    SerialPort *serial_port;
};

#endif	/* PORTSERIAL_H */

