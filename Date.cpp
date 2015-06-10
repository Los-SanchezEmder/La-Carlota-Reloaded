/* 
 * File:   Date.cpp
 * Author: fabricio
 * 
 * Created on 25 de marzo de 2015, 18:13
 */


#include "Date.h"


Date::Date(): Sensor(6){
    SetDateFromRTC();
};
/*
Date::Date(const Date& orig): Sensor(6) {
    this->day = orig.day;
    this->month = orig.month;
    this->year = orig.year;
    this->hour = orig.hour;
    this->minute = orig.minute;
    this->second = orig.second;
}*/

void Date::SetDateFromPC() {

    time_t t = time(NULL);
    struct tm today = *localtime(&t);
    float medicion[6] = {today.tm_sec, today.tm_min, today.tm_hour, today.tm_mday, today.tm_mon+1, today.tm_year+1900};
    /*float medicion[6];
    medicion[0] = today.tm_sec;
    medicion[1] = today.tm_min;
    medicion[2] = today.tm_hour;
    medicion[3]= today.tm_mday; 
    medicion[4] = today.tm_mon + 1;
    medicion[5] = today.tm_year + 1900;*/
    NuevaMedicion(medicion);
    
    
}
void Date::SetDateFromRTC() {
    std::string sh[6] = {"sts", "stmi", "sth", "std", "stme", "sta"};
    float medicion[6];
    for (int i = 0; i < 6; i++)
        medicion[i] = Lectura(sh[i]);
    medicion[5]+=1900;
    NuevaMedicion(medicion);
}
/*void Date::CheckRTC(){
    time_t t = time(NULL);
    struct tm today = *localtime(&t);
    float medicion[6] = {today.tm_sec, today.tm_min, today.tm_hour, today.tm_mday, today.tm_mon+1, today.tm_year+1900};
    if

    
}
 * */
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

