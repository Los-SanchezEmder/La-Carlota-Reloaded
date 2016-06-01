/* 
 * File:   genera_archivo.h
 * Author: richisan
 *
 * Created on 4 de mayo de 2016, 00:22
 */

#ifndef MANEJA_ARCHIVO_H
#define	MANEJA_ARCHIVO_H

#include <vector>
#include "FRDM_Datalogger.h"
using namespace std;

class maneja_archivo {
public:
    maneja_archivo();
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    maneja_archivo(string nombre,vector<DatosSensores>& mediciones);
    
    /** \fn 
    * \brief 
    * \param
    * \return  */
    void lee_archivo(string nombre,vector<DatosSensores>& mediciones);
    
    virtual ~maneja_archivo();

private:

};

#endif	/* GENERA_ARCHIVO_H */

