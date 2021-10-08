#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(10);
    int array[] = {2, 4, 6, 8, 10};
    set<int> s;

	s.insert(1);
	s.insert(3);
	s.insert(5);
	s.insert(7);
    s.insert(9);

	merge(array, array+5, s.begin(), s.end(), v.begin());
	
    cout << "Merged Vector: ";
    for(int i=0; i<10; i++){ 
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}