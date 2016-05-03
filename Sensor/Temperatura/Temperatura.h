/* 
 * File:   temperatura.h
 * Author: richisan
 *
 * Created on 18 de mayo de 2015, 23:08
 */

#ifndef TEMPERATURA_H
#define	TEMPERATURA_H
#include "../Sensor.h"

class Temperatura : public Sensor {
public:
    
    /** \fn Constructor de un sensor de temperatura, llama al constructor sensor 
     * con una variable
    * \brief 
    * \param
    * \return  */
    Temperatura();
    
    /** \fn Funcion utilizada para clonar un objeto
    * \brief 
    * \param
    * \return  */
    Temperatura(const Temperatura& orig);
   
    /** \fn Funcion destinada a obtener los datos del sensor de Temperatura
     *  y los guarda
    * \brief 
    * \param
    * \return  */
    void ObtengoDatos(float& dato);
    

    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    virtual ~Temperatura();
private:

};

#endif	/* TEMPERATURA_H */

