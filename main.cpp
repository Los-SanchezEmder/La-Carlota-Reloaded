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
#include <bits/stl_vector.h>
#include "Sensor/Temperatura/Temperatura.h"
#include "FRDM_Datalogger.h"
#include "maneja_archivo.h"


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
    
    FRDM_Datalogger FRDM(argv[FRDM_DATALOGGER]);
    
    FRDM.RealizarMediciones(200);
    
    std::vector<DatosSensores> Datos = FRDM.TodasMediciones();
    
    char eleccion;
    string nombre;
    cout << "¿desea crear un archivo con las mediciones?" << endl;
    cout << "presione S o N" << endl;
    cin >> eleccion;
    if(eleccion == 'S' || eleccion == 's'){
        cout << "ingrese un nombre para el archivo" << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
    }
    
    
    // Busqueda acelerometro
    
    Datos.clear();
    cout << "¿desea realizar alguna busquedaen en las mediciones de acelerometro?" << endl;
    cout << "presione S o N" << endl;
    cin >> eleccion;
    if(eleccion == 'S' || eleccion == 's'){
        float porcentaje;
        cout << "Esta funcion esta destinada  abuscar cambios abruptos en las "<< endl;
        cout << "aceleraciones"<< endl;
        cout << "Por favor ingrese el porsentaje de variacion de las mediciones :";
        cin >> porcentaje;
        Datos = FRDM.BusquedaAccPorcentual(porcentaje);
        cout << "ingrese el nombre del archivo donde lo desea guardar" << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
    }
    
    // Busqueda temperatura
    
    Datos.clear();
    cout << "¿desea realizar alguna busquedaen en las mediciones de Temperatura?" << endl;
    cout << "presione S o N" << endl;
    cin >> eleccion;
    if(eleccion == 'S' || eleccion == 's'){
        float temperatura;
        cout << "Esta funcion busca las temperaturas mayores al valor indicado "<< endl;
        cout << "Por favor indique el valor de la temperatura :";
        cin >> temperatura;
        Datos = FRDM.BusquedaTempMayor(temperatura);
        cout << "ingrese el nombre del archivo donde lo desea guardar" << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
    }
    cout << "¿desea crear un archivo con las mediciones?" << endl;
    cout << "presione S o N" << endl;
    cin >> eleccion;
    if(eleccion == 'S' || eleccion == 's'){
        cout << "ingrese un nombre para el archivo" << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
    }
    
        
    
    
    
    return 0;
}

