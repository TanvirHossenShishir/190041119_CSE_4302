#include <bits/stdc++.h>
using namespace std;

int value = 100;

namespace my_namespace
{
    int value = 500;
}

int main()
{
    cout << "From Global Scope: Value = " << value << endl;
    cout << "From my_namespace Scope: value = " << my_namespace::value << endl;
    return 0;
}