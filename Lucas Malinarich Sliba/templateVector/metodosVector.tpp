template <typename VEC_ELEM> myVector<VEC_ELEM>::myVector(VEC_ELEM* arr, int s){
    try{
        if(!arr||s<=0)
            throw 0;
        arreglo = new VEC_ELEM[s];
        longitud = s;
        for (int i = 0; i < longitud; i++)
            arreglo[i] = arr[i];
    }
    catch(int){
        arreglo=NULL;
        longitud=0;
    }
    catch(bad_alloc&){
        cout<<"Memoria insuficiente.\n";
    }
}

template <typename VEC_ELEM> myVector<VEC_ELEM>::~myVector(){
    delete []arreglo;
}

template <typename VEC_ELEM> void myVector<VEC_ELEM>::print() const{
    for (int i = 0; i < longitud; i++)
        cout << " " << *(arreglo + i);
    cout << endl;
}

//std::ostream& operator<<(std::ostream &Cout, const myVector &vec){
//    vec.print();
//    return Cout;
//}

template <typename VEC_ELEM> int myVector<VEC_ELEM>::getLongitud()const{
    return longitud;
}

template <typename VEC_ELEM> int myVector<VEC_ELEM>::getIndexOf(VEC_ELEM& element)const{
    int position=0;
    bool encontrado=(arreglo[position]==element);
    while(!encontrado&&position<longitud){
        position++;
        encontrado=(arreglo[position]==element);
    }
    return (encontrado)? position : -1;
}

template <typename VEC_ELEM> void myVector<VEC_ELEM>::agregarElemento(VEC_ELEM& nuevoElemento){
    cambiarLongitud(longitud+1);
    arreglo[longitud-1]=nuevoElemento;
}

template <typename VEC_ELEM> void myVector<VEC_ELEM>::eliminarElemento(VEC_ELEM elemento){
    int position=getIndexOf(elemento);
    try{
        if(position<0)
            throw "El elemento no existe\n";
        for(int i=position; i<longitud-1; i++)
            arreglo[i]=arreglo[i+1];
        longitud--;
    }
    catch (const char *str){
        cout<<str;
    }
}

template <typename VEC_ELEM> void myVector<VEC_ELEM>::cambiarLongitud(int nuevaLongitud){
    VEC_ELEM* aux=new VEC_ELEM[nuevaLongitud];
    for(int i=0; i<longitud; i++) //suponiendo que nuevaLongitud>longitud
        aux[i]=arreglo[i];
    longitud=nuevaLongitud;
    delete []arreglo;
    arreglo=aux;
}

//template <typename VEC_ELEM> VEC_ELEM& myVector<VEC_ELEM>::getFirstElem(){
//    return arreglo[0];
//}
//
//template <typename VEC_ELEM> VEC_ELEM& myVector<VEC_ELEM>::VEC_ELEM& getLastElem(){
//    return arreglo[longitud-1];
//}

template <typename VEC_ELEM> VEC_ELEM& myVector<VEC_ELEM>::getElem(int position){
    return arreglo[position];
}

template <typename VEC_ELEM> VEC_ELEM& myVector<VEC_ELEM>::operator[](int position){
    return getElem(position);
}

template <typename VEC_ELEM> bool myVector<VEC_ELEM>::estaVacio()const{
    return (!arreglo)? true : false;
}

template <typename VEC_ELEM> bool myVector<VEC_ELEM>::operator!()const{
    return estaVacio();
}
