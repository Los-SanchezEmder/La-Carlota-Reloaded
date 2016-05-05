/* 
 * File:   genera_archivo.cpp
 * Author: richisan
 * 
 * Created on 4 de mayo de 2016, 00:22
 */

#include "manejo_archivo.h"
#include "FRDM_Datalogger.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>

/*Este método me permite crear un fichero de salida donde van a almacenarse 
 todas las mediciones realizadas*/
maneja_archivo::maneja_archivo(string nombre,std::vector<DatosSensores>& mediciones){
std::ofstream fileout(nombre);
int cantidad = mediciones.size();

for (int i=0;i<cantidad;i++){
    fileout << mediciones[i].datoRTC.dias << "\t" << mediciones[i].datoRTC.meses << "\t";
    fileout << mediciones[i].datoRTC.anios << "\t" << mediciones[i].datoRTC.horas << "\t";
    fileout << mediciones[i].datoRTC.minutos << "\t" << mediciones[i].datoRTC.segundos << "\t";
    fileout << mediciones[i].datoAcc.x << "\t" << mediciones[i].datoAcc.y << "\t"; 
    fileout << mediciones[i].datoAcc.z << "\t" << mediciones[i].datoTemp << std::endl;
}
fileout.close();
}

maneja_archivo::maneja_archivo(const maneja_archivo& orig) {
}

maneja_archivo::~maneja_archivo() {
}



/*Este método carga los datos contenidos en un ficheroy los almacena en el 
 vector de mediciones*/
void lee_archivo(string nombre,vector<DatosSensores>& mediciones){
ifstream filein;
DatosSensores aux;
filein.open(nombre, ios::in);
while(!EOF){
    filein >> aux.datoRTC.dias;
    filein >> aux.datoRTC.meses;
    filein >> aux.datoRTC.anios;
    filein >> aux.datoRTC.horas;
    filein >> aux.datoRTC.minutos;
    filein >> aux.datoRTC.segundos;
    filein >> aux.datoAcc.x;
    filein >> aux.datoAcc.y;
    filein >> aux.datoAcc.z;
    filein >> aux.datoTemp;
    
    mediciones.push_back(aux);
}
filein.close();
 
}


