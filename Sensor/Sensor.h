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
#include "../PortSerial/PortSerial.h"

class Sensor {
public:
    Sensor();
    Sensor(int cDatos){
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
       return this->medicion[(this->cMediciones)-1];
       
    }
    
    Dato Medicion(int indice){
        return this->medicion[indice];
    }
    
    std::vector<int> Busqueda(float porcentaje){
        float limiteSuperior = (100 + porcentaje)/100;
        float limiteInferior = (100 - porcentaje)/100;
        std::cout << "defini limites de busqueda!!!" << std::endl;
        std::vector<int> indices;
        std::vector<int>::const_iterator cii;
        float ultimoDato[cDatosSensor];
        
        for(int i = 0; i< cDatosSensor; i++){
            ultimoDato[i]=medicion[0].GetDato(i);
        }
        std::cout << "defino ultimo dato antes de buscar " << std::endl;
        std::cout << cMediciones << std::endl;
        
        for(int i=1; i< cMediciones; i++){
            std::cout << " Primer for de busqueda" << std::endl;
            for (int j = 0; j < cDatosSensor; j++) {
                std::cout << "segundo for de busqueda" << std::endl;
                float uno=ultimoDato[j] * limiteInferior;
                float dos=ultimoDato[j] * limiteSuperior;
                std::cout << "entro al ifff" << std::endl;
                std::cout << uno << std::endl;
                std::cout << dos << std::endl;
                Dato caca = medicion[i];
                std::cout << "despues del igual" << std::endl;
                //std::cout << caca.GetDato(0) << std::endl;
                float comparacion1 =caca.GetDato(j);
                float comparacion2 =caca.GetDato(j);
                std::cout << "despues del igual**" << std::endl;
                if ((comparacion1 <= uno) || (comparacion2 >= dos)) {
                    //encontre un dato con las caracteristicas que busco
                    std::cout << "antes de meter el indice" << std::endl;
                    indices.push_back(i); // = new std::vector(i);
                    std::cout << "antes del break" << std::endl;
                    break;
                }
                for (int z = 0; z < cDatosSensor; z++) {
                    ultimoDato[z] = medicion[i].GetDato(z);
                }
                std::cout << "Despues del break" << std::endl;
                
            }
            std::cout << "Termino busqueda, dentro de busqueda" << std::endl;
            
        }
        return indices;
    }
private:
    Dato *medicion;
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
        medicion = new Dato(cDatosSensor, Medicion);
        cMediciones++;
    };
};

#endif	/* SENSOR_H */

