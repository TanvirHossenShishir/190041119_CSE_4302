#include<bits/stdc++.h>

using namespace std;

class Product
{
private:
    char name[100];
    double unitPrice;
    double  discountPercent;

public:
    Product() : unitPrice(10), discountPercent(0.5) {}
    void assignName(char name_p[])
    {
        strcpy(name, name_p);
    }
    void setPrice(double price)
    {
        unitPrice = price;
    }
    void setDiscPercent(double percent)
    {
        if(percent >= 0 && percent <= 10)
            discountPercent = percent;
    }
    double getSellingPrice(int nos)
    {
        return (unitPrice-(discountPercent/100)*unitPrice) * nos;
    }
    void display()
    {
        cout << name << " has a unit price BDT " << unitPrice
             << ". Current discount " << discountPercent << "%" << endl;
    }
};

int main()
{
    Product p1;
    p1.assignName("Cocola noodle");
    p1.setPrice(10);
    p1.setDiscPercent(10);
    p1.display();
    cout << "Selling Price of 5pcs is " << p1.getSellingPrice(5) << "." << endl;

}
