/* 
 * File:   Date.cpp
 * Author: fabricio
 * 
 * Created on 25 de marzo de 2015, 18:13
 */

#include <time.h>
#include <iostream>
#include "Date.h"
#include "ctime"
#include "Sensor/Dato.h"
Date::Date(){
    GetMomentoPC();
};

Date::Date(const Date& orig) {
    this->day = orig.day;
    this->month = orig.month;
    this->year = orig.year;
    this->hour = orig.hour;
    this->minute = orig.minute;
    this->second = orig.second;
}

void Date::GetMomentoPC() {

    time_t t = time(NULL);
    struct tm today = *localtime(&t);
    day = today.tm_mday;
    month = today.tm_mon + 1;
    year = today.tm_year + 1900;
    hour = today.tm_hour;
    minute = today.tm_min;
    second = today.tm_sec;
}

int Date::GetYear(){
        return this->year;
    };
Date& Date::operator=(const Date& cd) {
    day = cd.day;
    month = cd.month;
    year = cd.year;
    hour = cd.hour;
    minute = cd.minute;
    second = cd.second;
    return *this;
}

std::ostream& operator<<(std::ostream& co, Date& cd) {
    /*muestra la fecha y hora*/
    co << "El dia de la medicion fue : " << cd.day << '/' << cd.month << '/' << cd.year << std::endl;
    co << "La hora fue : " << cd.hour << ':' << cd.minute << ':' << cd.second << std::endl;
    return co;
}

Date::~Date() {
}

