/* 
 * File:   genera_archivo.h
 * Author: richisan
 *
 * Created on 4 de mayo de 2016, 00:22
 */

#ifndef GENERA_ARCHIVO_H
#define	GENERA_ARCHIVO_H

#include <vector>
#include "FRDM_Datalogger.h"
using namespace std;

class maneja_archivo {
public:
    maneja_archivo(string nombre,vector<DatosSensores>& mediciones);
    maneja_archivo(const maneja_archivo& orig);
    void lee_archivo(string nombre,vector<DatosSensores>& mediciones);
    virtual ~maneja_archivo();
private:

};

#endif	/* GENERA_ARCHIVO_H */

