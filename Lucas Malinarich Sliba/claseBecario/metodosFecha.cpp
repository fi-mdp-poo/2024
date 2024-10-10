#include <iostream>
#include "headers/claseFecha.h"

Fecha::Fecha(unsigned dd, unsigned mm, unsigned yy){
    setDay(dd);
    setMonth(mm);
    setYear(yy);
}

Fecha::~Fecha(){  }

void Fecha::setDay(unsigned int dd){ day=dd; }
void Fecha::setMonth(unsigned int mm){ month=mm; }
void Fecha::setYear(unsigned int yy){ year=yy; }

unsigned int Fecha::getDay()const{ return day; }
unsigned int Fecha::getMonth()const{ return month; }
unsigned int Fecha::getYear()const{ return year; }
