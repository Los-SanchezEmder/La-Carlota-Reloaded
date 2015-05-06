/* 
 * File:   Dato.cpp
 * Author: fabricio
 * 
 * Created on 25 de marzo de 2015, 17:36
 */

#include "Dato.h"
#include "Acelerometro/Acelerometro.h"

Dato::Dato() {

}

Dato::Dato(int& cVariables, float medicion[]) {

    this->cVariables = cVariables;
    this->Medicion = new float[this->cVariables];
    for (int i = 0; i< this->cVariables; i++)

        this->Medicion[i] = medicion[i];
}

Dato::Dato(const Dato& orig) {
    this->fecha = orig.fecha;
    this->cVariables = orig.cVariables;
    this->Medicion = orig.Medicion;
}

std::ostream& operator<<(std::ostream& co, Dato& cd) {

    for (int i = 0; i < cd.cVariables; i++)
        co << cd.GetDato(i) << std::endl;
    co << std::endl;
    return co;
}

Dato& Dato::operator=(const Dato& cd) {
    this->fecha = cd.fecha;
    this->cVariables = cd.cVariables;
    this->Medicion = cd.Medicion;
    return *this;
};

Dato::~Dato() {
}

/** \fn Date& GetFecha()
 * \brief Devuelve la fecha en la que fue tomada el dato
 * \param Dinguno.
 * \return Devuelve el contenido del puntero en dicha direccion  */
Date& Dato::GetFecha() {
    return this->fecha;
}

/** \fn 
 * \brief 
 * \param 
 * \return   */
float Dato::GetDato(int indice) {
    return this-> Medicion[indice];
}