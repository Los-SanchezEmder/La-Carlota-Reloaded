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
    hour = cd.hour;
    minute = cd.minute;
    second = cd.second;
    return *this;
}

Date::~Date() {
}

