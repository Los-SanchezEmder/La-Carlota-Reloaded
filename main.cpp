/* 
 * File:   main.cpp
 * Author: fabricio
 *
 * Created on 14 de marzo de 2015, 17:14
 */

#include <cstdlib>
#include "Sensor/Acelerometro/Acelerometro.h"
#include "PortSerial/PortSerial.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Acelerometro acc1;
    PortSerial MBED(argc, argv);
    float medicion[3]={2, 4, 7};
    
    acc1.NuevaMedicion(medicion);

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