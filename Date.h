/* 
 * File:   Date.h
 * Author: fabricio
 *
 * Created on 25 de marzo de 2015, 18:13
 */

#ifndef DATE_H
#define	DATE_H

#include <iostream>
#include "PortSerial/PortSerial.h"
#include "Sensor/Dato.h"
#include "Sensor/Sensor.h"
#include "ctime"
#include <time.h>

class Date : public Sensor{
public:
    Date();
        
    Date(const Date& orig);
    
    int GetYear();
    
    void SetDateFromPC();
    void SetDateFromRTC();
    void CheckRTC();
    Date& operator= (const Date&);
    virtual ~Date();
    friend  std::ostream& operator<< (std::ostream&, Date&);


private:

};

#endif	/* DATE_H */