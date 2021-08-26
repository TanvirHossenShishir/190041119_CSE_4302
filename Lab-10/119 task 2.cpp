#include <iostream>
using namespace std; 

class Car
{
private:
    string model;
    int engine;
public:
    Car(string m = "", int e = 0): model(m), engine(e)
    {}
    Car(const Car &c) 
    {
        engine = c.engine;
        cout << "Copy constructor called" << endl; 
    }
    Car& operator = (const Car &c)
    {
        engine = c.engine;
        cout << "Assignment operator called" << endl;
        return *this;
    }
    void getInfo()
    {
        cout << "Car Model      : " << model << endl;
        cout << "Engine Capacity: " << engine << " CC\n\n";
    }
};

class A
{
private:
    int data;
    A(const A &c);
    A& operator = (const A &c);
public:
    A(int d = 0): data(d)
    {}
    void getData()
    {
        cout << "Data: " << data << endl;
    }
};

int main() 
{
    Car c1("Toyota Prius", 1800), c2("Toyota C-HR", 1500);
    c1.getInfo();
    c2.getInfo();

    c2 = c1; // Assignment Constructor called
    c2.getInfo();

    Car c3 = c1; // Copy Constructor called
    //Car c3(c1); // Copy Constructor called
    c3.getInfo();

    A a1(5);
    a1.getData();
    //A a2 = a1; // Restrict Copy Constructor
    return 0;
} 