#include<bits\stdc++.h>

#define lineBreak cout << "--------------------------------------------------" << endl;

using namespace std;

class Calculator{
private :
    int currentValue;

public :
    Calculator(): currentValue(0)
    {}
    Calculator (int val): currentValue(val)
    {}
    void add(int Value)
    {
        lineBreak
        cout << "add " << Value << endl;
        currentValue += Value;
    }
    void subtract(int Value)
    {
        lineBreak
        cout << "subtract " << Value << endl;
        currentValue -= Value;
    }
    void multiply(int Value)
    {
        lineBreak
        cout << "multiply " << Value << endl;
        currentValue *= Value;
    }
    void divideBy(int Value)
    {
        lineBreak
        cout << "divide by " << Value << endl;
        if(Value == 0)
            cout << "Error : divide by 0 is undefined." << endl;
        else
            currentValue /= Value;
    }
    void setValue(int value)
    {
        currentValue = value;
    }
    void getValue() const
    {
        cout << "Calculator display: " << currentValue << endl;
    }
    void Clear()
    {
        lineBreak
        cout << "clear" << endl;
        currentValue = 0;
    }
    ~Calculator()
    {
        cout << "Calculator object is destroyed." << endl;
    }
};

int main()
{
    Calculator c;

    c.add(10);
    c.getValue();
    c.add(7);
    c.getValue();

    c.multiply(31);
    c.getValue();

    c.subtract(42);
    c.getValue();

    c.divideBy(7);
    c.getValue();
    c.divideBy(0);
    c.getValue();

    c.add(3);
    c.getValue();

    c.subtract(1);
    c.getValue();

    c.Clear();
    c.getValue();
    return 0;
}
