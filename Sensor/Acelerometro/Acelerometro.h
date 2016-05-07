/* 
 * File:   Acelerometro.h
 * Author: fabricio
 *
 * Created on 27 de marzo de 2015, 16:54
 */

#ifndef ACELEROMETRO_H
#define	ACELEROMETRO_H
#include "../Sensor.h"

struct Dato3f{
    float x;
    float y;
    float z;
    friend std::ostream& operator<< (std::ostream& co,Dato3f& datoAcc);
   
};

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
    void ObtengoDatos(Dato3f& dato);
    

    virtual ~Acelerometro();
    

private:
    


};

#endif	/* ACELEROMETRO_H */

