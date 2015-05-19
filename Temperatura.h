/* 
 * File:   temperatura.h
 * Author: richisan
 *
 * Created on 18 de mayo de 2015, 23:08
 */

#ifndef TEMPERATURA_H
#define	TEMPERATURA_H
#include "Sensor/Sensor.h"
#include "Sensor/Dato.h"

class Temperatura : public Sensor {
public:
    Temperatura();
    
    Temperatura(const Temperatura& orig);
   
    void ObtengoDatos();

    friend std::ostream& operator<<(std::ostream& co, Temperatura& cd);

    virtual ~Temperatura();
private:

};

#endif	/* TEMPERATURA_H */

