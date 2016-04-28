/* 
 * File:   Acelerometro.h
 * Author: fabricio
 *
 * Created on 27 de marzo de 2015, 16:54
 */

#ifndef ACELEROMETRO_H
#define	ACELEROMETRO_H
#include "../Sensor.h"
#include "../Dato.h"


class Acelerometro : public Sensor {
public:
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Acelerometro();

    /** \fn 
    * \brief 
    * \param
    * \return  */
    Acelerometro(const Acelerometro& orig);

    /** \fn 
    * \brief 
    * \param
    * \return  */
    void ObtengoDatos();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float x(int &i){ return Medicion(i).GetDato(0);};
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float y(int &i){ return Medicion(i).GetDato(1);};
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    float z(int &i){ return Medicion(i).GetDato(2);};

    /** \fn 
    * \brief 
    * \param
    * \return  */
    friend std::ostream& operator<<(std::ostream& co, Acelerometro& cd);

    virtual ~Acelerometro();
private:

};

#endif	/* ACELEROMETRO_H */

