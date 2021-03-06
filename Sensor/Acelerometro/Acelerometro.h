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
    Acelerometro();

    Acelerometro(const Acelerometro& orig);

    void ObtengoDatos();

    friend std::ostream& operator<<(std::ostream& co, Acelerometro& cd);

    virtual ~Acelerometro();
private:

};

#endif	/* ACELEROMETRO_H */

