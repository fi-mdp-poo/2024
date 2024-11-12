#include <iostream>

using namespace std;

template <class T>
class InstanceCounter
{
public:
    InstanceCounter()
    {
        ++count;
    }
    ~InstanceCounter()
    {
        --count;
    }

    static int GetCount()
    {
        return count;
    }

private:
    static int count;
};

template <class T>
int InstanceCounter<T>::count = 0;

class MyClass : public InstanceCounter<MyClass> {};


int main()
{
    MyClass a, b;
    std::cout << MyClass::GetCount();  // Imprime "2"

    return 0;
}

