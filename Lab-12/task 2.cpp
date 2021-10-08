#include<bits\stdc++.h>
using namespace std;

template <class type>
int amax(type* array, int size, int n)
{
    sort(array, array+size);
    return array[size-n];
}

int main()
{
    int intArray[] = {10, 7, 1, 5, 4};
    char charArray[] = {'a', 'c', 'x', 's', 'p'};
    double doubleArray[] = {5.0, 3.0, 10.0, 4.0, 7.0};

    cout << amax(intArray,  5, 1) << endl;
    cout << (char)amax(charArray,  5, 1) << endl;
    cout << amax(doubleArray,  5, 1) << endl;
    return 0;
}