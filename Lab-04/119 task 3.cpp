#include<bits\stdc++.h>

using namespace std;

class ZooAnimal{
private :
    string nameOfAnimal;
    int birthYear;
    int cageNumber;
    float weight;
    int height;

public :
    ZooAnimal(): nameOfAnimal("unknown"), birthYear(2021), cageNumber(0), weight(0), height(0)
    {}
    ZooAnimal (string aName, int bYear, int cNo, float aWeight, int aHeight){
        nameOfAnimal = aName;
        birthYear = bYear;
        cageNumber = cNo;
        weight = aWeight;
        height = aHeight;
    }
    void setter(string aName, int bYear, int cNo, float aWeight, int aHeight){
        nameOfAnimal = aName;
        if(bYear <= 2021 && bYear >= 1920)
            birthYear = bYear;
        cageNumber = cNo;
        weight = aWeight;
        height = aHeight;
    }
    void getAge(){
        cout << "Age        : " << 2021-birthYear << endl;
    }
    void getInformation(){
        cout << "Name       : " << nameOfAnimal << endl;
        cout << "Birth Year : " << birthYear << endl;
        cout << "Cage No    : " << cageNumber << endl;
        cout << "Weight     : " << weight << endl;
        cout << "Height     : " << height << endl << endl;
    }
    ~ZooAnimal(){
    }
};

int main()
{
    ZooAnimal a1("Tiger", 2015, 12, 120, 80);
    a1.getInformation();

    a1.getAge();
    a1.getInformation();
    return 0;
}

