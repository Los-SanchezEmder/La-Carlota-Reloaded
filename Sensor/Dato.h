/* 
 * File:   Dato.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:36
 */

#ifndef DATO_H
#define	DATO_H
#include <iostream>

class Dato {
public:
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Dato();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Dato(int cVariables);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Dato(const Dato& orig);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Dato(int& cVariables, float medicion[] );

    /** \fn 
    * \brief 
    * \param
    * \return  */
    float GetDato(int indice);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    Dato& operator= (const Dato& cd);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    friend std::ostream& operator<<(std::ostream& co, Dato& cd);

    virtual ~Dato();
private:

    int cVariables;
    float *Medicion;

};

#endif	/* DATO_H */

