/* 
 * File:   Dato.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:36
 */

#ifndef DATO_H
#define	DATO_H
#include "../Date.h"

class Dato {
public:
    Dato();
    Dato(int cVariables);
    Dato(const Dato& orig);
    
    Dato(int& cVariables, float medicion[] );

 /** \fn Date& GetFecha()
 * \brief Devuelve la fecha en la que fue tomada el dato
 * \param Dinguno.
 * \return Devuelve el contenido del puntero en dicha direccion  */
    Date& GetFecha(){
        return this->fecha ;}
    
     /** \fn 
 * \brief 
 * \param 
 * \return   */
    float GetDato(int indice)   {return this->Medicion[indice]; }

    //Dato(const Dato& orig);d
    Dato& operator= (const Dato& cd);
    friend std::ostream& operator<<(std::ostream& co, Dato& cd);
    virtual ~Dato();
private:
    Date fecha;
    int cVariables;
    float *Medicion;

};

#endif	/* DATO_H */

