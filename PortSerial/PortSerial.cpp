/* 
 * File:   PortSerial.cpp
 * Author: fabricio
 * 
 * Created on 27 de marzo de 2015, 19:13
 */

#include <iostream>
#include <fstream>
#include "PortSerial.h"
#include <stdio.h>
#include <string>

using namespace std;

/*
PortSerial::PortSerial() {  
    
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

    string pedido = '#' + sensor + '\n';
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
        
        cout << "TIMEOUT!" << endl;
        cout << "REINTENTANDO!" << endl;
        this->ReadSensor(sensor);
        return 0;
    }

    return valor;
    //-- Show the received data
}

void PortSerial::WriteSensor(unsigned long tsegundos) {
    //Este metodo permite actualizar fecha y hora rtc
    string sensor = "set";
    string pedido = '#' + sensor + '\n';
    std::string tsecond = std::to_string(tsegundos);


    try {
        serial_port->Write(pedido);

    } catch (SerialPort::NotOpen) {
        cerr << "No se puede escribir el dato" << endl;
    }

    try {
        serial_port->Write(tsecond);

    } catch (SerialPort::ReadTimeout E) {
        cout << "TIMEOUT!" << endl;
        cout << "REINTENTANDO!" << endl;
        this->WriteSensor(tsegundos);
        //return 0;
    }


    //-- Show the received data
}


PortSerial::~PortSerial() {
    this->serial_port->Close();
}

PortSerial& PortSerial::operator=(const PortSerial& cd) {
    serial_port = cd.serial_port;
    return *this;
}
