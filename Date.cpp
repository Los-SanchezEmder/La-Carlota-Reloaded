/* 
 * File:   Date.cpp
 * Author: fabricio
 * 
 * Created on 25 de marzo de 2015, 18:13
 */

#include <time.h>

#include "Date.h"
#include "ctime"

void Date::GetMomentoPC(){
    
    time_t t=time(NULL);
    struct tm today = *localtime(&t);
    day = today.tm_mday;
    month = today.tm_mon + 1;
    year = today.tm_year + 1900;
    hour = today.tm_hour;
    minute = today.tm_min;
    second = today.tm_sec;
}

Date::Date(const Date& orig) {
}
Date& Date::operator= (const Date& cd){
    day = cd.day;
    month = cd.month;
    year = cd.year;
   std::cout << "El dia de la medicion fue : "<< cd.day <<'/'<< cd.month << '/' << cd.year << std::endl;
    hour = cd.hour;
    minute = cd.minute;
    second = cd.second;
    return *this;
}
/*Date& Date::operator* ( const Date& cd){
    this->day *= cd.day;
    this->month *= cd.month;
    this->year *= cd.year;
    this->hour *= cd.hour;
    this->minute *= cd.minute;
    this->second *= cd.second;

    return *this;
}*/

// imprime cualquier cosa!!
std::ostream& operator<<(std::ostream& co,  Date& cd) {
    Date fecha = cd;
    //fecha.minute = 16;
    //co << "El dia de la medicion fue : "<< std::endl;
    co << "El dia de la medicion fue : "<< fecha.day <<'/'<< fecha.month << '/' << fecha.GetYear() << std::endl;
    co << "La hora fue : " << fecha.hour<<':'<<fecha.minute<<':' <<fecha.second <<std::endl;
    return co;
}

Date::~Date() {
}

