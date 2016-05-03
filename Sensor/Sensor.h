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
    //friend float ReadSensor(std::string sensor);

    /** \fn Funcion utilizada para clonar un sensor.
    * \brief 
    * \param El argumento es otro sensor!
    * \return  */
    Sensor(const Sensor& orig);
    

    //virtual void ObtengoDatos();

    
    /** \fn Esta funcion se utiliza para asignarle la direccion de un puerto de 
     * una placa al objeto sensor creado
     * \parametro Puntero que apunta a una direccion que es en la que se encuentra la placa
    * \return  void */
    void AsignarPlaca(PortSerial *Board){   this->Placa = Board;   };
    
 

 

    /** \fn esta funcion encuentra las mediciones que variaron con respecto a la 
     * anterior un determinado porcentaje. Sirve para identificar eventos en los
     *  que profujeron una variacion brusca en algun sensor. 
     * 
    * \parametro Se le asigna un porcentaje de 0% a 100%, con el cual se 
     * clasificaran losvalores qu sean iguales o superen este porcentage de 
     * variacion con respecto al dato anterior.
    * \return  devuelve un vector de los indices de los sensores que cumplen con la condicion */
    //std::vector<int> Busqueda(float porcentaje);

    /** \fn 
    * \brief 
    * \param
    * \return  */
    virtual ~Sensor();
    
private:
    

    //Puntero a la placa asignada al sensor
    PortSerial *Placa;

protected:
    
    /** \fn Devuelve el valor de una medicion especifica.
    * \brief 
    * \param se le pasa la ubicacion de la medicion
    * \return  devuelve el dato especificado por la ubicacion
    Dato Medicion(int indice){  return medicion[indice];}

    */
    
    /** \fn Esta funcion se encarga de leer desde la placa un sensor indicado
    * \brief 
    * \param cd es un string que identifica el sensor, sera mandado por puerto
     *  serie para que la placa lo identifique
    * \return  float, devuelve el valor del sensor leido*/
    float Lectura(std::string cd);
    
    
    void Escritura(unsigned long tsegundos);

    /** \fn esta funcion se encarga de agrgar un nuevo vector Dato de mediciones
     * (guarda el vector completo de la medicion)
    * \brief 
    * \param
    * \return  */
    void NuevaMedicion(float Medicion[]);
};

#endif	/* SENSOR_H */
