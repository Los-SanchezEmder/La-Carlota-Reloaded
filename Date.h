/* 
 * File:   Date.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 18:13
 */

#ifndef DATE_H
#define	DATE_H
#include <iostream>

class Date {
public:
    Date(){
        day=19;
        month=12;
        year=1986;
        hour= 0;
        minute= 0;
        second= 23;
        //GetMomentoPC();
    };
    Date(const Date& orig);
    int GetYear(){
        return this->year;
    };
    /*Date GetDate(){
        return *this;
    };*/
    void GetMomentoPC();
    //Date& operator* (const Date& cd);
    Date& operator= (const Date&);
    virtual ~Date();
    
friend    std::ostream& operator<<(std::ostream&, Date&);
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
};

#endif	/* DATE_H */