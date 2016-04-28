/* 
 * File:   main.cpp
 * Author: fabricio
 *
 * Created on 14 de marzo de 2015, 17:14
 */

#include <cstdlib>
#include "Sensor/Acelerometro/Acelerometro.h"
#include "PortSerial/PortSerial.h"
#include "Date.h"
#include <vector>
#include "Sensor/Temperatura/Temperatura.h"
// Hola mundo
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    PortSerial *FRDM;
    FRDM = new PortSerial(argc, argv);
       
    vector<int> dominguito;
   
    Acelerometro acc1;
    Date RTC;
    Temperatura temp1;
    
    acc1.AsignarPlaca(FRDM);
    RTC.AsignarPlaca(FRDM);
    temp1.AsignarPlaca(FRDM);
    cout << endl;
    cout << endl;
    cout << endl;
    
    RTC.CheckRTC(); //actualizo RTC
    
    
    for (int i = 0; i < 5; i++) {
        cout<< i <<endl;
        
        acc1.ObtengoDatos();
        //cout<<"despues del acelerometro"<<endl;
        //cout << acc1.Medicion(i).GetDato(0) << endl;
        //cout<<"antes de temperatura"<<endl;
        temp1.ObtengoDatos();
        //cout<<"despues del sensor de temperatura"<<endl;
        //cout << temp1.Medicion(i).GetDato(0) << endl;
        //cout<<"antes de la RTC"<<endl;
        RTC.SetDateFromRTC();
        //cout<<"despues d ela RTC"<<endl;
    }
    
    dominguito = acc1.Busqueda(5);
    for (int i = 1; i < dominguito.size(); i++) {
        cout << i << endl;
        cout << "X :" << acc1.Medicion(i).GetDato(0) << endl;
        cout << acc1.Medicion(i).GetDato(1) << endl;
        cout << acc1.Medicion(i).GetDato(2) << endl;
        cout << "temperatura: " << temp1.Medicion(i).GetDato(0) << endl;
        //-- RTC --
        cout << RTC.Medicion(i).GetDato(2) <<':';
        cout << RTC.Medicion(i).GetDato(1) <<':';
        cout << RTC.Medicion(i).GetDato(0) << endl;
        cout << RTC.Medicion(i).GetDato(3) <<'/';
        cout << RTC.Medicion(i).GetDato(4) <<'/';
        cout << RTC.Medicion(i).GetDato(5) << endl;
        
    }

    //FRDM.ReadSensor("d1");
    //sleep(1000);
    //acc1.ObtengoDatos();


    //PortSerial MBED(argc, argv);
    //float medicion[3] = {2, 4, 7};

    return 0;
}


/*
clase madre:
Sensor{

}

RTC{
}

clases hijos:

temperatura:sensor{
}

acceleracion:sensor{
}
 * */
