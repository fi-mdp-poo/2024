#include "vecTemplate.h"

int main(){
    int arr[5] = { 1, 2, 3, 4, 5 };
    myVector<int> a(arr, 5);
    a.print();
    cout<<a[2]<<endl;
    return 0;
}

