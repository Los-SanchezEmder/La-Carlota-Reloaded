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

#define FRDM_DATALOGGER 1
// Hola mundo
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Falta indicar el dispositivo deseado a comunicarce" << endl;
    }
    if (argc > 2) {
        cerr << "Se indicaron mas de un dispositivo, el sistema solo soporta uno" << endl;
    }
    
    //FRDM_Datalogger FRDM(argv[FRDM_DATALOGGER]);
    
    
    
    
    
    
    PortSerial *FRDM;
    FRDM = new PortSerial(argv[FRDM_DATALOGGER]);
    //FRDM = new PortSerial(argc, argv);

    Acelerometro acc1;
    Date RTC;
    Temperatura temp1;
    acc1.AsignarPlaca(FRDM);
    //cout<<"2222"<<endl;
    RTC.AsignarPlaca(FRDM);
    temp1.AsignarPlaca(FRDM);
    RTC.CheckRTC();
    //cout<<"33333dddd"<<endl;
    for (int i = 0; i < 20; i++) {
        cout<< i <<endl;
        acc1.ObtengoDatos();
        temp1.ObtengoDatos();
        cout << temp1.Temp(i) << endl;
        RTC.SetDateFromRTC();
        
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
    
    
    
    
    
    
        cout<<"000"<<endl;
    vector<int> dominguito;
    

    
    dominguito = acc1.Busqueda(5);
    for (int i = 1; i < dominguito.size(); i++) {
        cout << i << endl;
        cout << "X :" << acc1.x(dominguito[i]) << endl;
        cout << "Y :" << acc1.y(dominguito[i]) << endl;
        cout << "Z :" << acc1.z(dominguito[i])<< endl;
        cout << "temperatura: " << temp1.Temp(dominguito[i]) << endl;
        //-- RTC --
        cout << RTC.horas(dominguito[i])<<':';
        cout << RTC.minutos(dominguito[i]) <<':';
        cout << RTC.segundos(dominguito[i]) << endl;
        cout << RTC.dias(dominguito[i]) <<'/';
        cout << RTC.meses(dominguito[i]) <<'/';
        cout << RTC.anos(dominguito[i]) << endl;
        
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
