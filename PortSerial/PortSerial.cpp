/* 
 * File:   PortSerial.cpp
 * Author: fabricio
 * 
 * Created on 27 de marzo de 2015, 19:13
 */

#include <iostream>
#include "PortSerial.h"
#include <stdio.h>
#include <string>

using namespace std;
/*
PortSerial::PortSerial() {  
    
    cout << "se la manda" << endl;
}*/

        
PortSerial::PortSerial(char* dispositivo) {

    cout << "Serial port: " << dispositivo << endl;
    cout << "Opening..." << endl;
    this->serial_port = new SerialPort(dispositivo);
    try {
        serial_port->Open(SerialPort::BAUD_9600,
                SerialPort::CHAR_SIZE_8,
                SerialPort::PARITY_NONE,
                SerialPort::STOP_BITS_1,
                SerialPort::FLOW_CONTROL_NONE);
        
    } catch (SerialPort::OpenFailed E) {
        cerr << "Error opening the serial port" << endl;
        cout << "Serial port: " << dispositivo[1] << endl;
        
    }
    
}




float PortSerial::ReadSensor(std::string sensor) {
    std::string pedido = '#' + sensor + '\n';
    //std::string pedido = '#' + sensor;
    
    //cout << pedido << endl;
    char str[50];
    string intermedio;
    bool empiezaCadena = false;
    float valor = 0;
    int i;
    //cout << "zzzzzzz" << endl;
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
        //cout << str << endl;
        sscanf(str, "##%f//", &valor);
        cout << valor << endl;
        

        
    } catch (SerialPort::ReadTimeout E) {
        cout << "TIMEOUT!"<< endl;
        return 0;
        
    }
   
    return valor;
    //-- Show the received data
}

void PortSerial::WriteSensor(std::string sensor, int& dato) {
    //mando comando para escribir
    float confirmacion= ReadSensor("CRTC");
    //recibo confirmacion
    if (confirmacion ==1){
        time_t reloj= time(NULL);
        string relojito;
        relojito = ctime(&reloj);
        serial_port->Write(relojito);
        
    }
        
    
    //envio nuevo tdato de la fecha¿
    
}


PortSerial::~PortSerial() {
    this->serial_port->Close();
}



PortSerial& PortSerial::operator= (const PortSerial& cd){
        serial_port= cd.serial_port;
        return *this;
    }