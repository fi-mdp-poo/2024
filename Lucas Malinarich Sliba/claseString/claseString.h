#ifndef CLASESTRING_H_INCLUDED
#define CLASESTRING_H_INCLUDED

#include <cstring>
#include <iostream>

class myString{
private:
    char *theString;
    int longitud;
public:
    friend std::istream operator>>(std::istream&, myString&);
    friend std::ofstream operator<<(std::ofstream&, myString&);

    myString(const char* str=NULL, int lenght=0);
    ~myString();
    void setString(const char*);
    myString& operator=(const char*);

    char* getString()const; //reserva memoria en el heap
    void setLongitud(int);
    int getLongitud()const;
    void copiarString(const char*);
    void concatenarString(const char*);
    myString& operator+=(const char*);
    bool estaVacio();
    bool sonIguales(const char*);
    bool operator==(const char*);
    int encontrarSubString(const char*); //actualmente incompleta
    /*
    char at(const int&);
    char operator[](const int&);
    */
};

void imprimirString(const myString&);

#endif // CLASESTRING_H_INCLUDED
