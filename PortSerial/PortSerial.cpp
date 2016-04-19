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
    
    cout << "se la manda" << endl;
    

}
        
PortSerial::PortSerial(int& caracteres, char** dispositivo) {

    if (caracteres < 2) {
        cerr << "No serial device name is given" << endl;
       
    }

    cout << "Serial port: " << dispositivo[1] << endl;
    cout << "Opening..." << endl;
    this->serial_port = new SerialPort(dispositivo[1]);
     cout << serial_port->IsOpen() << endl << serial_port << endl;
    try {
        serial_port->Open(SerialPort::BAUD_9600,
                SerialPort::CHAR_SIZE_8,
                SerialPort::PARITY_NONE,
                SerialPort::STOP_BITS_1,
                SerialPort::FLOW_CONTROL_NONE);
        
        cout << serial_port->IsOpen() << endl << serial_port << endl;
    } catch (SerialPort::OpenFailed E) {
        cerr << "Error opening the serial port" << endl;
        cout << "Serial port: " << dispositivo[1] << endl;
        
    }
    
}


float PortSerial::ReadSensor(std::string sensor) {
    std::string pedido = '#' + sensor + '\n';
    //std::string pedido = '#' + sensor;

    cout << pedido << endl;
    char str[50];
    string intermedio;
    bool empiezaCadena = false;
    float valor = 0;
    int i;
    cout << "zzzzzzz" << endl;
    try {
        try{
        cout << "antes de pedir el dato" << endl;
        serial_port->Write(pedido);
        cout << "despues de pedir el dato" << endl;
        }catch(SerialPort::NotOpen){
            cerr << "No se puede escribir el dato" << endl;
            
        }

        intermedio = serial_port->ReadLine(500, '\n');
        cout << intermedio << endl;
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
        cout << str << endl;
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