/* 
 * File:   Sensor.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:28
 */

#ifndef SENSOR_H
#define	SENSOR_H
#include <vector>
#include <math.h>
#include "../PortSerial/PortSerial.h"
#include <string>

class Sensor {
public:


    /** \fn Constructor madre de un tipo de sensor, es la estructura basica de 
     * cualquier sensor y aram una matriz dependiendo a la cantidad de variables que dispone el sensor
    * \brief 
    * \param cDatos es la cantidad de variables que va a tener el Sensor.
    * \return  */
    Sensor();

    /** \fn Funcion utilizada para clonar un sensor.
    * \brief 
    * \param El argumento es otro sensor!
    * \return  */
    Sensor(const Sensor& orig);

    
    /** \fn Esta funcion se utiliza para asignarle la direccion de un puerto de 
     * una placa al objeto sensor creado
     * \parametro Puntero que apunta a una direccion que es en la que se encuentra la placa
    * \return  void */
    void AsignarPlaca(PortSerial *Board){   this->Placa = Board;   };

    /** \fn 
    * \brief 
    * \param
    * \return  */
    virtual ~Sensor();
    
private:
    

    //Puntero a la placa asignada al sensor
    PortSerial *Placa;

protected:
    

    
    /** \fn Esta funcion se encarga de leer desde la placa un sensor indicado
    * \brief 
    * \param cd es un string que identifica el sensor, sera mandado por puerto
     *  serie para que la placa lo identifique
    * \return  float, devuelve el valor del sensor leido*/
    float Lectura(std::string cd);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void Escritura(unsigned long tsegundos);

};

#endif	/* SENSOR_H */
