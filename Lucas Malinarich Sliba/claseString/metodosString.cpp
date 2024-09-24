#include <iostream>
#include "claseString.h"

myString::myString(){
    theString=NULL;
    longitud=0;
}

myString::myString(const char *str){
    longitud=sizeof(str);
    theString=new char[longitud];
    strcpy(theString, str);
}

myString::~myString(){
    delete[]theString;
}

void myString::setString(const char *str){
    longitud=sizeof(str);
    if(theString)
        delete[]theString;
    theString = new char[longitud];
    strcpy(theString, str);
}

myString* myString::operator=(const char *str){
    setString(str);
    return this;
}

void imprimirString(myString &str){ std::cout<<str.theString<<std::endl; }

char* myString::getString(){
    char* copia=new char[longitud];
    strcpy(copia, theString);
    return copia;
}

int myString::getLongitud(){ return longitud; }

void myString::concatenarString(const char *str){ //hay un error oculto en esta función
    strcat(theString, str);
}

myString* myString::operator+=(const char *str){
    strcat(theString, str);
    return this;
}

bool myString::estaVacio(){
    return (theString)? true : false;
}

bool myString::sonIguales(const char *str){
    int longitudStr=sizeof(str), i=0;
    bool iguales=(longitudStr==longitud);
    while(i<longitud&&iguales){
        iguales=(theString[i]==str[i]);
        i++;
    }
    return iguales;
}

bool myString::operator==(const char *str){
    bool resultado=sonIguales(str);
    return resultado;
}

int myString::encontrarSubString(const char *str){ //actualmente incompleta
    int position=0;

    return position;
}
