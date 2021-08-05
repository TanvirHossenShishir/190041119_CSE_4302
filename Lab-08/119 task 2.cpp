#include <bits/stdc++.h>

using namespace std;

class Lab{
public:
    string labName;
    int capacity;

public:
    Lab(string _labName, int _capacity):
        labName(_labName), capacity(_capacity)
    { }
    string getLabName(){
        return labName;
    }
    int getCapacity(){
        return capacity;
    }
    void setLabName(string _labName){
        labName=_labName;
    }
    void setCapacity(int _capacity){
        capacity = _capacity;
    }
    void show(){
        cout << "Lab" << labName << " " << capacity << " Capacity\n";
    }
};

class LecturerRoom{
private:
    string roomName;
    int roomNo;
    int capacity;

public:
    LecturerRoom(string _roomName, int _roomNo, int _capacity){
        roomName = _roomName;
        roomNo = _roomNo;
        capacity = _capacity;
    }

    string getRoomName(){
        return roomName;
    }
    int getRoomNo(){
        return roomNo;
    }
    int getCapacity(){
        return capacity;
    }
    void setRoomName(string _roomName){
        roomName = _roomName;
    }
    void setRoomNo(int _roomNo){
        roomNo = _roomNo;
    }
    void setCapacity(int _capacity){
        capacity = _capacity;
    }
    void show(){
        cout << roomName << " " << roomNo << " " << capacity << " Capacity\n";
    }
};


class N28Building{
private:
    vector<Lab> lab;
    vector<LecturerRoom> lecturerRoom;

public:
    void setLab(Lab x){
        lab.push_back(x);
    }
    void setLecturerRoom(LecturerRoom x){
        lecturerRoom.push_back(x);
    }
    void showAllLabs(){
        cout << "Show all Labs: " << endl;
        for(auto i:lab)
            i.show();
    }
    void showAllLecturerRooms(){
        cout << "Show all Lecturer Rooms: " << endl;
        for(auto i:lecturerRoom)
            i.show();
    }
};

int main(){
    Lab l1("MPK1", 60), l2("MPK2", 60), l3("MPK3", 50), l4("MPK4", 50);
    LecturerRoom lr1("Hafiz",102,3), lr2("Shafie",105,3),
                 lr3("Aisyah",202,3), lr4("Rahim",208,3);

    cout << "Welcome to N28 Building" << endl;
    N28Building b;
    b.setLab(l1);
    b.setLab(l2);
    b.setLab(l3);
    b.setLab(l4);

    b.setLecturerRoom(lr1);
    b.setLecturerRoom(lr2);
    b.setLecturerRoom(lr3);
    b.setLecturerRoom(lr4);

    b.showAllLabs();
    b.showAllLecturerRooms();
    return 0;
}
