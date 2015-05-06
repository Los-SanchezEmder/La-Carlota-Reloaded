/* 
 * File:   main.cpp
 * Author: fabricio
 *
 * Created on 14 de marzo de 2015, 17:14
 */

#include <cstdlib>
#include "Sensor/Acelerometro/Acelerometro.h"
#include "PortSerial/PortSerial.h"
#include <vector>
// Hola mundo
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector<int> dominguito;
    Acelerometro acc1;
    PortSerial *FRDM;
    FRDM = new PortSerial(argc, argv);
    acc1.AsignarPlaca(FRDM);
    cout << "comienzo lectura!!!" << endl;
    for(int i=0;i<100;i++){
        acc1.ObtengoDatos();
    }
    cout << "Termine lectura!!!" << endl;
    dominguito = acc1.Busqueda(50); 
    cout << "Termine lectura!!!" << endl;
    
    for(int i=0; i < dominguito.size();i++){
        cout << dominguito[i] << endl;
        cout <<acc1.Medicion(i).GetDato(0) << endl;
        cout <<acc1.Medicion(i).GetDato(1) << endl;
        cout <<acc1.Medicion(i).GetDato(2) << endl;
        cout <<acc1.Medicion(i).GetFecha() << endl;
    
    }
    
    //FRDM.ReadSensor("d1");
    //sleep(1000);
    //acc1.ObtengoDatos();

    
    //PortSerial MBED(argc, argv);
    float medicion[3]={2, 4, 7};
    
  

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
