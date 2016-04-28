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
    PortSerial();
    PortSerial(int& caracteres, char** dispositivo);
    void Inicializacion();
    float ReadSensor(std::string sensor);
    void WriteSensor(unsigned long tsegundos);
    virtual ~PortSerial();
    PortSerial& operator=(const PortSerial& cd);

private:
    SerialPort *serial_port;
};

#endif	/* PORTSERIAL_H */

