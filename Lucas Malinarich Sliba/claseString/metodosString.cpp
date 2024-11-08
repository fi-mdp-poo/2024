#include <iostream>
#include "claseString.h"

using namespace std;

myString::myString(const char* str, int lenght){
    setString(str);
    setLongitud(lenght);
}

myString::~myString(){
    delete[]theString;
}

void myString::setString(const char *str){
    try{
        if(!str)
            throw 0;
        longitud=strlen(str); //crear int longitudString(const char *);
        if(theString)
            delete[]theString;
        theString=new char[longitud+1];
        for(int i=0; i<longitud; i++)
            theString[i]=str[i];
    }
    catch(int){
        theString=NULL;
    }
    catch(bad_alloc&){
        cout<<"Meemoria insuficiente.\n";
    }
}

myString& myString::operator=(const char *str){
    setString(str);
    return *this;
}

void imprimirString(const myString &str){
    char *cadena=str.getString();
    cout<<cadena<<endl;
    delete cadena;
}

char* myString::getString()const{
    try{
        char* copia=new char[getLongitud()];
        strcpy(copia, theString);
        return copia;
    }
    catch(bad_alloc&){
        cout<<"Memoria insuficiente.\n";
        return NULL;
    }
}

void myString::setLongitud(int lenght){ longitud=lenght; }

int myString::getLongitud()const{ return longitud; }

bool myString::estaVacio(){
    return (theString)? true : false;
}

bool myString::sonIguales(const char *str){
    int longitudStr=strlen(str), i=0;
    bool iguales=(longitudStr==getLongitud());
    while(i<longitudStr&&iguales){
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
    int empieza=-1;

    return empieza;
}

void myString::copiarString(const char *str){ setString(str); }

void myString::concatenarString(const char *str){
    int nuevaLongitud=getLongitud()+strlen(str); //crear int longitudString(const char *);
    int i=0, j=0;
    char* nuevoString=new char[nuevaLongitud];
    while(i<longitud){
        nuevoString[i]=theString[i];
        i++;
    }
    while(i<nuevaLongitud+1){
        nuevoString[i]=str[j];
        i++;
        j++;
    }
    setString(nuevoString);
    setLongitud(nuevaLongitud);
}

myString& myString::operator+=(const char *str){
    concatenarString(str);
    return *this;
}
