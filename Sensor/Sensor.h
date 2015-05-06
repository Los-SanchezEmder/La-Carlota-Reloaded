/* 
 * File:   Sensor.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 17:28
 */

#ifndef SENSOR_H
#define	SENSOR_H
#include "Dato.h"
#include <vector>
#include <math.h>
#include "../PortSerial/PortSerial.h"

class Sensor {
public:
    Sensor();
    Sensor(int cDatos){
        medicion.resize(200);
        cMediciones = 0;
        cDatosSensor = cDatos;
       
    };
    //friend float ReadSensor(std::string sensor);


    Sensor(const Sensor& orig);
    
 /*   void AbrirPuerto(int argc, char** argv){
         static PortSerial Adquiridor(argc,argv);
    }*/
    virtual ~Sensor();
    void AsignarPlaca(PortSerial *DDD){
        this->Placa = DDD;
    }
    Dato UltimaMedicion(){
       return medicion[(this->cMediciones)-1];
       
    }
    
    Dato Medicion(int indice){
        return medicion[indice];
    }
    
    std::vector<int> Busqueda(float porcentaje){
        float limiteSuperior = (100 + porcentaje)/100;
        float limiteInferior = (100 - porcentaje)/100;
        std::cout << "defini limites de busqueda!!!" << std::endl;
        std::cout << limiteSuperior << std::endl;
        std::cout << limiteInferior << std::endl;
        std::vector<int> indices;
        std::vector<int>::const_iterator cii;
        float ultimoDato[cDatosSensor];
        std::cout << "antes del for!!" << std::endl;
        //std::cout << medicion[0] << std::endl;
        for(int i = 0; i< cDatosSensor; i++){
            ultimoDato[i]=medicion[0].GetDato(i);
        }
        std::cout << "defino ultimo dato antes de buscar " << std::endl;
        std::cout << cMediciones << std::endl;
        
        for(int i=1; i< cMediciones; i++){
            //std::cout << " Primer for de busqueda" << std::endl;
            for (int j = 0; j < cDatosSensor; j++) {
                //std::cout << "segundo for de busqueda" << std::endl;
                float uno= fabs(ultimoDato[j] * limiteInferior);
                float dos= fabs(ultimoDato[j] * limiteSuperior);
                //std::cout << "entro al ifff" << std::endl;
                //std::cout << i << std::endl;
                //std::cout << j << std::endl;
                //std::cout << "Primera comparacion : "<< uno << std::endl;
                //std::cout << "Segunda comparacion: " << dos << std::endl;
                //std::cout << "despues del igual" << std::endl;
                
                float comparacion = fabs(medicion[i].GetDato(j));
                //std::cout << comparacion << std::endl;
                //std::cout << "despues del igual**" << std::endl;
                if ((comparacion <= uno) || (comparacion >= dos)) {
                    //encontre un dato con las caracteristicas que busco
                    std::cout << "++Guardo Dato++" << std::endl;
                    indices.push_back(i); // = new std::vector(i);
                    //std::cout << "antes del break" << std::endl;
                    break;
                }

                
            }
            for (int z = 0; z < cDatosSensor; z++) {
                ultimoDato[z] = medicion[i].GetDato(z);
            }
            std::cout << "Despues del break" << std::endl;
            std::cout << "Termino busqueda, dentro de busqueda" << std::endl;
            
        }
        return indices;
    }
private:
    std::vector<Dato> medicion;
    int cMediciones;
    int cDatosSensor;
    PortSerial *Placa;
    

protected:

    float Lectura(std::string cd) {
        float valor;
        valor = Placa->ReadSensor(cd);
        return valor;
    };

    void NuevaMedicion(float Medicion[]) {
        Dato *nMedicion;
        nMedicion = new Dato(cDatosSensor, Medicion);
        cMediciones++;
        medicion[cMediciones]= *nMedicion;
        
    };
};

#endif	/* SENSOR_H */

