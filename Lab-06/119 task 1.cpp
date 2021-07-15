#include<bits\stdc++.h>

using namespace std;

class Coordinate{
private :
    float abscissa;
    float ordinate;

public :
    Coordinate(): abscissa(0), ordinate(0)
    { }
    Coordinate (float _abscissa, float _ordinate) :
        abscissa(_abscissa), ordinate(_ordinate)
    { }
    void display(){
        cout << "Abscissa: " << abscissa << endl;
        cout << "Ordinate: " << ordinate << endl << endl;
    }
    float getDistance(Coordinate c){
        return sqrt(pow(c.abscissa - abscissa, 2) + pow(c.ordinate - ordinate, 2));
    }
    float getDistance(){
        return sqrt(pow(0 - abscissa, 2) + pow(0 - ordinate, 2));
    }
    void move_x(float val){
        abscissa += val;
    }
    void move_y(float val){
        ordinate += val;
    }
    void move(float val){
        move_x(val);
        move_y(val);
    }
    bool operator>(Coordinate c){
        return this->getDistance() > c.getDistance();
    }
    bool operator<(Coordinate c){
        return this->getDistance() < c.getDistance();
    }
    bool operator>=(Coordinate c){
        return this->getDistance() >= c.getDistance();
    }
    bool operator<=(Coordinate c){
        return this->getDistance() <= c.getDistance();
    }
    bool operator==(Coordinate c){
        return this->getDistance() == c.getDistance();
    }
    bool operator!=(Coordinate c){
        return this->getDistance() != c.getDistance();
    }
    Coordinate operator++(){
        return Coordinate(++abscissa, ++ordinate);
    }
    Coordinate operator++(int){
        return Coordinate(abscissa++, ordinate++);
    }
    Coordinate operator--(){
        return Coordinate(--abscissa, --ordinate);
    }
    Coordinate operator--(int){
        return Coordinate(abscissa--, ordinate--);
    }
    ~Coordinate()
    { }
};

int main()
{
    Coordinate c1(1, 1), c2(-1, -1), c3;
    cout << "Point-1: " << endl;
    c1.display();
    cout << "Point-2: " << endl;
    c2.display();

    cout << "c1.getDistance()   - " << c1.getDistance() << endl;
    cout << "c1.getDistance(c2) - " << c1.getDistance(c2) << endl;

    cout << "c1 == c2?          - ";
    if(c1 == c2)
        cout << "Yes\n" << endl;
    else
        cout << "No\n" << endl;

    c3 = c1++;
    cout << "c3 = c1++\n" << endl;

    cout << "Point-3: " << endl;
    c1.display();
    return 0;
}
