#include <iostream>
#include "claseString.h"

using namespace std;

int main(){
    myString *string1= new myString(), *string2=new myString("Hola Mundo");
    string1->setString("Hola mundo");
    char *texto=string2->getString();
    cout<<texto<<endl;
    delete string1;
    delete string2;
    delete[]texto;
    return 0;
}

/**
void myString::copiarString(const char *str){
    longitud=sizeof(str);
    if(theString)
        delete[]theString; //a la hora de ejecutar esta línea el programa se traba
    theString=new char[longitud];
    for(int i=0; i<longitud; i++)
        theString[i]=str[i];
}

void myString::concatenarString(const char *str){
    int nuevaLongitud=longitud+sizeof(str), i=0, j=0;
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
    delete[]theString; //a la hora de ejecutar esta línea el programa se traba
    theString=nuevoString;
    longitud=nuevaLongitud;
}
**/
