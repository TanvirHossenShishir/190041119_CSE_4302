#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;

enum computer_type
{
    tdesktop,
    tlaptop
};

class Computer
{
private:
    string processor;
    int ram;
    static int n;
    static Computer *arrap[];
    
public:
	virtual void getdata()
    {
        cout << " Enter Processor Model : ";
        cin >> processor;
        cout << " Enter Ram Size : ";
        cin >> ram;
    }
    virtual void putdata()
    {
        cout << "\n Processor Model : " << processor;
        cout << "\n Ram Size : " << ram;
    }
    virtual computer_type get_type();
    static void add(int choice);
    static void display();  
    static void read();
    static void write();
};

int Computer::n;
Computer *Computer::arrap[100];

class Desktop: public Computer
{
private:
    string motherboard;
public:
	void getdata()
    {
        Computer::getdata();
        cout << " Enter Motherboard Model : ";
        cin >> motherboard;
    }
    void putdata()
    {
        Computer::putdata();
        cout << "\n Motherboard Model : " << motherboard;
    }
};

class Laptop: public Computer
{
private:
    double battery;
public:
	void getdata()
    {
        Computer::getdata();
        cout << " Enter Battery Capacity : ";
        cin >> battery;
    }
    void putdata()
    {
        Computer::putdata();
        cout << "\n Battery Capacity : " << battery;
    }
};

computer_type Computer::get_type()
{
    if (typeid(*this) == typeid(Desktop))
        return tdesktop;
    if (typeid(*this) == typeid(Laptop))
        return tlaptop;
}

void Computer::add(int choice)
{
    if(choice == 1)
        arrap[n] = new Desktop;
    if(choice == 2)
        arrap[n] = new Laptop;
    arrap[n++]->getdata();
}

void Computer::display()
{
    Computer::read();
    for (int j = 0; j < n; j++)
    {
        cout << (j + 1);
        switch (arrap[j]->get_type())
        {
        case tdesktop:
            cout << ".Type : Desktop";
            break;
        case tlaptop:
            cout << ".Type : Laptop";
            break;
        default:
            cout << ".Unknown type";
        }
        arrap[j]->putdata();
        cout << endl;
    }
}

void Computer::write()
{
    int size;
    ofstream ouf;
    computer_type ctype;
    ouf.open("COMPUTER.DAT", ios::trunc | ios::binary);
    if (!ouf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    for (int j = 0; j < n; j++)
    {
        ctype = arrap[j]->get_type();
        ouf.write((char *)&ctype, sizeof(ctype));
        switch (ctype)
        {
        case tdesktop:
            size = sizeof(Desktop);
            break;
        case tlaptop:
            size = sizeof(Laptop);
            break;
        }
        ouf.write((char *)(arrap[j]), size);
        if (!ouf)
        {
            cout << "\nCan't write to file\n";
            return;
        }
    }
}

void Computer::read()
{
    int size;
    computer_type ctype;
    ifstream inf;
    inf.open("COMPUTER.DAT", ios::binary);
    if (!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while (true)
    {
        inf.read((char *)&ctype, sizeof(ctype));
        if (inf.eof())
            break;
        if (!inf)
        {
            cout << "\nCan’t read type from file\n";
            return;
        }
        switch (ctype)
        { 
        case tdesktop:
            arrap[n] = new Desktop;
            size = sizeof(Desktop);
            break;
        case tlaptop:
            arrap[n] = new Laptop;
            size = sizeof(Laptop);
        }
        inf.read((char *)arrap[n], size);
        if (!inf)
        {
            cout << "\nCan’t read data from file\n";
            return;
        }
        n++;
    }
}

int main()
{
    Computer::add(1);
    Computer::write();
    Computer::display();
	return 0;
}