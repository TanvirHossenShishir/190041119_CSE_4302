#include<bits/stdc++.h>

using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
    RationalNumber() : numerator(1), denominator(1) {}
    void assign(int numerator_p, int denominator_q)
    {
        if(denominator_q == 0)
            cout << "Error: Denominator Cannot be 0" << endl;
        else{
            numerator = numerator_p;
            denominator = denominator_q;
        }
    }
    double convert()
    {
        return (double) numerator / denominator;
    }
    void invert()
    {
        if(numerator == 0)
            cout << "Error: Denominator Cannot be 0" << endl;
        else
            swap(numerator, denominator);
    }
    void Print()
    {
        cout << "The Rational Number is " << numerator << "/" << denominator << endl;
    }
};

int main()
{
    RationalNumber r1;
    r1.assign(3, 2);
    r1.Print();
    cout << "Decimal Equivalent is " << r1.convert() << endl;

    cout << "\nAfter Inversion: " << endl;
    r1.invert();
    r1.Print();
    cout << "Decimal Equivalent is " << r1.convert() << endl;
    return 0;
}
