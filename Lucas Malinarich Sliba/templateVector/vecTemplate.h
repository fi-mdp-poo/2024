#ifndef VECTEMPLATE_H_INCLUDED
#define VECTEMPLATE_H_INCLUDED

#include <iostream>

using namespace std;

template <typename VEC_ELEM> class myVector {
private:
    VEC_ELEM* arreglo;
    int longitud;
public:
//    friend ostream& operator<<(ostream&, const myVector&);
    myVector(VEC_ELEM* arr=NULL, int s=0);
    virtual ~myVector();
    void print()const;
    int getLongitud()const;
    int getIndexOf(VEC_ELEM& element)const;
    void agregarElemento(VEC_ELEM& nuevoElemento);
    void eliminarElemento(VEC_ELEM nuevoElemento);
    void cambiarLongitud(int nuevaLongitud);
    VEC_ELEM& getElem(int position);
    VEC_ELEM& operator[](int position);
    bool estaVacio()const;
    bool operator!()const;
};

//    int getCapacidad()const;
//    void pushBack(const VEC_ELEM);
//    void popBack();
//    void ajustarLongitud(); en caso de que longitud != caapcidad

#include "metodosVector.tpp"
//los métodos de los templates van por fuera del proyecto y se incorporan de esta manera

#endif // VECTEMPLATE_H_INCLUDED
