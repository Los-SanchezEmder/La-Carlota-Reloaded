/* 
 * File:   genera_archivo.cpp
 * Author: richisan
 * 
 * Created on 4 de mayo de 2016, 00:22
 */

#include "maneja_archivo.h"
#include "FRDM_Datalogger.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

maneja_archivo::maneja_archivo(){
    
}

/*Este método me permite crear un fichero de salida donde van a almacenarse 
 todas las mediciones realizadas*/
maneja_archivo::maneja_archivo(string nombre,std::vector<DatosSensores>& mediciones){
    std::ofstream fileout(nombre);
    int cantidad = mediciones.size();

    for (int i=0;i<cantidad;i++){
        fileout << mediciones[i];
    }

    fileout.close();
}

maneja_archivo::~maneja_archivo() {
}



/*Este método carga los datos contenidos en un ficheroy los almacena en el 
 vector de mediciones*/
void maneja_archivo::lee_archivo(string nombre,vector<DatosSensores>& mediciones){

std::ifstream filein;
filein.open(nombre, ios::in);
//int cantidad =0;
  //  cantidad = mediciones.size();
    //std::cout << "cantidad de datos antes del archivo: " << cantidad << std::endl;
    DatosSensores aux;
    
while (filein!=NULL){
    filein >> aux;
    //FRDM_Datalogger.AgregaDatos(aux);
    mediciones.push_back(aux);
}
    //cantidad = mediciones.size();
    //std::cout << "cantidad de datos totales: " << cantidad << std::endl;
filein.close();

}

