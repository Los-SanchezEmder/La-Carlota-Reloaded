/* 
 * File:   PortSerial.cpp
 * Author: fabricio
 * 
 * Created on 27 de marzo de 2015, 19:13
 */

#include <iostream>
#include "PortSerial.h"
#include <stdio.h>

using namespace std;

PortSerial::PortSerial() {  

}
        
PortSerial::PortSerial(int& caracteres, char** dispositivo) {

    if (caracteres < 2) {
        cerr << "No serial device name is given" << endl;
       
    }

    cout << "Serial port: " << dispositivo[1] << endl;
    cout << "Opening..." << endl;
    this->serial_port = new SerialPort(dispositivo[1]);
    try {
        serial_port->Open(SerialPort::BAUD_9600,
                SerialPort::CHAR_SIZE_8,
                SerialPort::PARITY_NONE,
                SerialPort::STOP_BITS_1,
                SerialPort::FLOW_CONTROL_NONE);
    } catch (SerialPort::OpenFailed E) {
        cerr << "Error opening the serial port" << endl;
        
    }
    
}

PortSerial::PortSerial(const PortSerial& orig) {

}

float PortSerial::ReadSensor(std::string sensor) {
    std::string pedido = '#' + sensor + '\n';


    char str[50];
    string intermedio;
    bool empiezaCadena = false;
    float valor = 0;
    int i;
    try {
        serial_port->Write(pedido);

        intermedio = serial_port->ReadLine(500, '\n');
        i = 0;
        for (int ii = 0; ii < intermedio.size(); ii++) {
            if ((intermedio[ii] == '#')&& !empiezaCadena) {
                empiezaCadena = true;
            }

            if (empiezaCadena) {
                str[i] = intermedio[ii];
                i++;
            }
        }

        sscanf(str, "##%f//", &valor);
       
        
    } catch (SerialPort::ReadTimeout E) {
        cout << "TIMEOUT!";
        return 0;
        
    }
   
    return valor;
    //-- Show the received data
}

void PortSerial::WriteSensor(std::string sensor, int& dato) {
    //mando comando para escribir
    float confirmacion= ReadSensor("CRTC");
    //recibo confirmacion
    if (confirmacion ==1)
        
    
    //envio nuevo tdato de la fecha¿
    
}


PortSerial::~PortSerial() {
    this->serial_port->Close();
}



PortSerial& PortSerial::operator= (const PortSerial& cd){
        serial_port= cd.serial_port;
        return *this;
    }