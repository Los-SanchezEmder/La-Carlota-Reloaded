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
        //return 1;
    }

    cout << "Serial port: " << dispositivo[1] << endl;
    cout << "Opening..." << endl;
    this->serial_port= new SerialPort(dispositivo[1]);
    try {
        serial_port->Open(SerialPort::BAUD_9600,
                SerialPort::CHAR_SIZE_8,
                SerialPort::PARITY_NONE,
                SerialPort::STOP_BITS_1,
                SerialPort::FLOW_CONTROL_NONE);
    } 
    catch (SerialPort::OpenFailed E) {
        cerr << "Error opening the serial port" << endl;
        //return 1;
    }
    //serial_port.Close();
}

PortSerial::PortSerial(const PortSerial& orig) {
}

void PortSerial::ReadSensor(std::string sensor) {
    std::string pedido = '#' + sensor;
    
    //SerialPort::DataBuffer buffer;
    char str[50];
    string intermedio;
    bool empiezaCadena = false;
    float x, y, z;
    int i;
    try {
        serial_port->Write(pedido);
        intermedio = serial_port->ReadLine(500, '\n');
        i = 0;
        for (int ii = 0; ii < intermedio.size(); ii++) {
            if ((intermedio[ii] == '#')&& !empiezaCadena) {
                empiezaCadena = true;
            }
            cout << intermedio[ii];
            if (empiezaCadena) {
                str[i] = intermedio[ii];
                i++;
            }
        }
        cout << "------------" << endl;

        sscanf(str, "##%f//%f//%f//", &x, &y, &z);

    } catch (SerialPort::ReadTimeout E) {
        cout << "TIMEOUT!";
        //return 1;
    }
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    //-- Show the received data
    
    
}

PortSerial::~PortSerial() {
}

