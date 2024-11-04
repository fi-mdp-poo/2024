#include <iostream>

using namespace std;

template <class T, class R> T chad(R &obj1); //inciso a


template<class J> class nashe //inciso b
{
public:
    J atributo;

};

template <class F, class M> class jorgito //inciso c
{
public:
    jorgito(F dato);
    M pedilo();
};

template<int U=10> class manolo //inciso d
{
public:
    int boca[U];
};

/*class facundito //inciso e
{
public:
    template <class T>  // Definimos `nashe` con el parámetro de plantilla `T`
    friend class nashe<T>;
};*/

template <typename T>
class ClaseAmiga;  // Declaración anticipada de la clase de plantilla amiga

template <typename U>
class MiClase
{
    friend class ClaseAmiga<U>;  // Declaración de amistad con ClaseAmiga<U>
};

template <template<class G> class H, class K> //inciso f
class pablito
{
    H<K> atributo;
};

int main()
{

    return 0;
}


