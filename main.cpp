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

using namespace std;

int main(int argc, char** argv) {
    
    if (argc < 2) {
        cerr << "Falta indicar el dispositivo deseado a comunicarce" << endl;
    }
    if (argc > 2) {
        cerr << "Se indicaron mas de un dispositivo, el sistema solo soporta uno" << endl;
    }
    
    // Crear el objeto de la placa y asignar placa
    FRDM_Datalogger FRDM(argv[FRDM_DATALOGGER]);
        
    cout << endl;
    cout << "*******COMPLEMENTOS DE INFORMATICA*******" << endl;
    cout << endl;
    cout << "*****************************************" << endl;
    cout << "* Sistema de adquisición, clasificación *" << endl;
    cout << "*       y ordenamiento de datos         *" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
    
    int cantidad = 0;
    cout << "Ingrese la cantidad de mediciones que necesita tomar: "; 
    cin >> cantidad;
    
    FRDM.RealizarMediciones(cantidad);
    std::vector<DatosSensores> Datos = FRDM.TodasMediciones();
    maneja_archivo MiArchivo;

    char eleccion;
    string nombre;

    cout << "Para visualizar el resultado de las mediciones por pantalla";
    cout << " presione S o N " << endl;
    cin >> eleccion;
    if (eleccion == 'S' || eleccion == 's') {
        FRDM.MuestraMediciones();
    }

    cout << "¿Desea crear un archivo con las mediciones realizadas?" << endl;
    cout << "Presione S o N y luego oprima enter" << endl;
    cin >> eleccion;
    if (eleccion == 'S' || eleccion == 's') {
        cout << "Ingrese nombre y la extensión para el archivo" << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
    }
    //n
    
    Datos.clear();

    cout << "¿Quiere agregar mediciones desde un archivo ya existente?" << endl;
    cout << "presione S o N" << endl;
    cin >> eleccion;
    if (eleccion == 'S' || eleccion == 's') {
        cout << "Ingrese el nombre completo y luego presione enter" << endl;
        cin >> nombre;
        MiArchivo.lee_archivo(nombre, Datos);
        FRDM.AgregaDatos(Datos);
        //prueba para saber si me carga el archivo
        FRDM.MuestraMediciones();
        
    }
    // Busqueda acelerometro

    //Datos.clear();
    cout << "¿Desea realizar alguna búsqueda en las mediciones de acelerómetro?" << endl;
    cout << "presione S o N" << endl;
    cin >> eleccion;
    if (eleccion == 'S' || eleccion == 's') {
        float porcentaje;
        cout << "Esta función esta destinada a buscar cambios abruptos en las ";
        cout << "aceleraciones" << endl;
        cout << "Por favor ingrese el porcentaje de variación de las mediciones :";
        cin >> porcentaje;
        Datos = FRDM.BusquedaAccPorcentual(porcentaje);

        cout << "Ingrese el nombre y extensión del archivo donde desea guardar " << endl;
        cout << "los datos No ordenados" << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
        
        //FRDM.OrdenarX(Datos);
        std::sort(Datos.begin(), Datos.end(), SortY);
        cout << "Ingrese un nombre de archivo para guardar todos los datos " << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
    }

    // Busqueda temperatura

    Datos.clear();
    cout << "¿Desea realizar alguna búsqueda en las mediciones de Temperatura?" << endl;
    cout << "presione S o N" << endl;
    cin >> eleccion;
    if (eleccion == 'S' || eleccion == 's') {
        float temperatura;
        cout << "Esta función busca temperaturas mayores a un valor indicado " << endl;
        cout << "Por favor indique el valor de temperatura :";
        cin >> temperatura;
        Datos = FRDM.BusquedaTempMayor(temperatura);
        cout << endl;
        cout << "Ingrese el nombre y extensión del archivo donde lo desea guardar" << endl;
        cin >> nombre;
        maneja_archivo(nombre, Datos);
        cout << "El programa finalizó exitosamente" << endl;
    }

    return 0;
}

