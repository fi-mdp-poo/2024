template <class ST, int cnt> ST pila<ST, cnt>::operator[](int indice)
{
    if(indice && indice<tam)
    {
        return st[indice];
    }
    else
    {
        cout << "Indice = " << indice << " excede el maximo ("
             << tam << "). Se retorna el ultimo valor = ";
        return st[tam-1];
    }
}

template <class ST, int t> ostream& operator<< (ostream& co, pila<ST, t>& obj)
{
    cout << endl << endl;
    for(int i=0; i<obj.tos; i++)
    {
       cout << "Valor [" << i << "] = " << obj.st[i] << endl;
    }
    cout << "Tamano = " << obj.tam << "\n\n";

    return co;
}

template <class ST, int cnt> pila<ST, cnt>::pila()
{
    tos = 0;
    tam = cnt;
    st = new ST[tam];
}

template <class ST, int cnt> pila<ST, cnt>::~pila()
{
    delete [] st;
}

template <class ST, int cnt> void pila<ST, cnt>::push(ST obj)
{
    if(tos == tam)
    {
        cout << "La pila esta completa.\n";
        return;
    }
    st[tos] = obj;
    tos++;
}

template <class ST, int cnt> ST pila<ST, cnt>::pop()
{
    if( !tos )
    {
        cout << "La pila esta vacia.\n\n";
        return 0;                       // return null
    }
    tos--;

    return st[tos];
}
