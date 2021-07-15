#include<bits\stdc++.h>

using namespace std;

class FLOAT{
private :
    float floatData;

public :
    FLOAT(): floatData(0)
    { }
    FLOAT(float _floatData) :
        floatData(_floatData)
    { }
    void display(){
        cout << "Float Data: " << floatData << endl;
    }
    FLOAT operator+(FLOAT f){
        return FLOAT(floatData + f.floatData);
    }
    FLOAT operator-(FLOAT f){
        return FLOAT(floatData - f.floatData);
    }
    FLOAT operator*(FLOAT f){
        return FLOAT(floatData * f.floatData);
    }
    FLOAT operator/(FLOAT f){
        return FLOAT(floatData / f.floatData);
    }
    operator int() const{
        return floatData;
    }
    ~FLOAT()
    { }
};

int main()
{
    FLOAT f1(5.02), f2(3.87), f3;
    f1.display();

    f3 = f1*f2;
    f3.display();

    int i = f3;
    cout << "Float to Int: " << i << endl;
    return 0;
}
