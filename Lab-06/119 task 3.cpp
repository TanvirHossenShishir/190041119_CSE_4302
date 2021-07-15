#include<bits\stdc++.h>

using namespace std;

class ZooAnimal{
private :
    string nameOfAnimal;
    int birthYear;
    int cageNumber;
    float weightData;
    int height;

public :
    ZooAnimal() :
        nameOfAnimal("unknown"), birthYear(2021), cageNumber(0), weightData(0), height(0)
    { }
    ZooAnimal (string n, int b, int c, float w, int h) :
        nameOfAnimal(n), birthYear(b), cageNumber(c), weightData(w), height(h)
    { }
    void setNameOfAnimal(string nameOfAnimal){
        this->nameOfAnimal = nameOfAnimal;
    }
    void setBirthYear(int birthYear){
        this->birthYear = birthYear;
    }
    void setCageNumber(int cageNumber){
        this->cageNumber = cageNumber;
    }
    void setWeightData(float weightData){
        this->weightData = weightData;
    }
    void setHeight(int height){
        this->height = height;
    }
    string getNameOfAnimal(){
        return nameOfAnimal;
    }
    int getBirthYear(){
        return birthYear;
    }
    int getCageNumber(){
        return cageNumber;
    }
    float getWeightData(){
        return weightData;
    }
    int getHeight(){
        return height;
    }
    int operator==(int data){
        return weightData == data;
    }
    void operator--(int dec){
        height -= dec;
    }
    void getAge(){
        cout << "Age        : " << 2021-birthYear << endl;
    }
    void getInformation(){
        cout << "Name       : " << nameOfAnimal << endl;
        cout << "Birth Year : " << birthYear << endl;
        cout << "Cage No    : " << cageNumber << endl;
        cout << "Weight     : " << weightData << endl;
        cout << "Height     : " << height << endl << endl;
    }
    ~ZooAnimal()
    { }
};

int main()
{
    ZooAnimal a1("Tiger", 2015, 12, 120, 80);
    a1.getInformation();
    cout << "a1 == 120? - ";
    if(a1 == 120)
        cout << "Yes\n" << endl;
    else
        cout << "No\n" << endl;

    a1.operator--(20);
    cout << "a1.operator--(20)" << endl;
    cout << "Height: " << a1.getHeight() << endl;
    return 0;
}
