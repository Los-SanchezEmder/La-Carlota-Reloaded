/* 
 * File:   Date.cpp
 * Author: fabricio
 * 
 * Created on 25 de marzo de 2015, 18:13
 */


#include "Date.h"
#include "time.h"
#include "PortSerial/PortSerial.h"


Date::Date(): Sensor(){
    //SetDateFromPC();
  
};
/*Date::Date(const Date& orig): Sensor(6) {
    this->day = orig.day;
    this->month = orig.month;
    this->year = orig.year;
    this->hour = orig.hour;
    this->minute = orig.minute;
    this->second = orig.second;
}*/

void Date::SetDateFromPC(Dato6i& dato) {

    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    
        //Dato
    dato.segundos = today.tm_sec;
    dato.minutos = today.tm_min;
    dato.horas = today.tm_hour;
    dato.dias = today.tm_mday;
    dato.meses = today.tm_mon + 1;
    dato.anios = today.tm_year + 1900;
    

}

void Date::SetDateFromRTC(Dato6i& dato) {

    //Dato
    dato.segundos = Lectura("sts");
    dato.minutos = Lectura("stmi");
    dato.horas = Lectura("sth");
    dato.dias = Lectura("std");
    dato.meses = Lectura("stme") + 1;
    dato.anios = Lectura("sta") + 1900;
}

void Date::CheckRTC() {
    /*Este método permite revisar la fecha y hora de la RTC y 
     la computadora y en el caso de que sean diferentes, actualiza la RTC*/

    bool banderacambio = false;  
    
    time_t t = time(NULL);
    struct tm today; // hora que entrega la RTC luego de medicion[6]
    struct tm horapc = *localtime(&t); //hora de la pc
    
    float medicion[6] = {today.tm_sec, today.tm_min, today.tm_hour, today.tm_mday, today.tm_mon + 1, today.tm_year + 1900};

    for (int j = 0; j < 6; j++) {
        if (today.tm_sec = !horapc.tm_sec) {
            today.tm_sec = horapc.tm_sec;
            banderacambio = true;
        }
        if (today.tm_min = !horapc.tm_min) {
            today.tm_min = horapc.tm_min;
            banderacambio = true;
        }

        if (today.tm_hour = !horapc.tm_hour) {
            today.tm_hour = horapc.tm_hour;
            banderacambio = true;
        }
        if (today.tm_mday = !horapc.tm_mday) {
            today.tm_mday = horapc.tm_mday;
            banderacambio = true;
        }
        if (today.tm_mon = !horapc.tm_mon) {
            today.tm_mon = horapc.tm_mon;
            banderacambio = true;
        }
        if (today.tm_year != horapc.tm_year) {
            today.tm_year = horapc.tm_year;
            banderacambio = true;
        }

        if (banderacambio == true) {
            //si bandera cambio == true, entonces actualizo fecha RTC

            long int tsegundos=0;
            tsegundos = time(NULL); //obtiene la hora de la pc en segundos desde 1970
            tsegundos -=10800;  //diferencia horaria con el meridiano            
            Escritura(tsegundos);
        }
    }
}
/*
Date& Date::operator=(const Date& cd) {
    this->medicion[0] = cd.Medicion(0);
    month = cd.month;
    year = cd.year;
    hour = cd.hour;
    minute = cd.minute;
    second = cd.second;
    return *this;
}*/
/*
std::ostream& operator<<(std::ostream& co, Date& cd) {
    //muestra la fecha y hora
    //Dato fecha = cd.Medicion();
    co << "El dia de la medicion fue : " << cd.Medicion(i).GetDato(0) << '/' << cd.Medicion(1)  << '/' << cd.Medicion(2) << std::endl;
    co << "La hora fue : " << cd.Medicion(3)  << ':' << cd.Medicion(4)  << ':' << cd.Medicion(5)  << std::endl;
    return co;
}*/

Date::~Date() {
}

