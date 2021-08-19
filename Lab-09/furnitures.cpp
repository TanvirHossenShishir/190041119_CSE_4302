#include <iostream>
#include <string>
#define LINE0 cout << "-------------------------------------\n";
#define LINE1 cout << "#####################################\n";
using namespace std;

enum class Material
{
    Wood,
    Board,
    Steel,
    foam
};

class Furniture
{
protected:
    string productName;
    double price;
    double discount;
    Material madeof;

public:
    Furniture(double p, double d, Material m) : price(0), discount(0), madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setProductName(string name)
    {
        productName = name;
    }
    void setPrice(double val)
    {
        if (val > 0)
            price = val;
    }
    void setDiscount(double val)
    {
        if (val <= price)
            discount = val;
    }
    void setDiscountPercentage(double val)
    {
        discount = price * val / 100.0;
    }
    void setMadeof(Material val)
    {
        madeof = val;
    }
    string getProductName()
    {
        return productName;
    }
    double getPrice()
    {
        return price;
    }
    double getDiscountPrice()
    {
        return price - discount;
    }
    string getMadeof()
    {
        if (madeof == Material::Wood)
            return string("Wood");
        else if (madeof == Material::Board)
            return string("Board");
        else if (madeof == Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    void getInfo()
    {
        cout << "Product Name: " << getProductName();
        cout << "\nRegular Price: " << getPrice();
        cout << "\nDiscounted Price: " << getDiscountPrice();
        cout << "\nMaterial: " << getMadeof();
    }
    virtual void productDetails() = 0;
    virtual ~Furniture() {}
};

enum class BedSize
{
    Single,
    SemiDouble,
    Double
};

class Bed : public Furniture
{
private:
    BedSize bedSize;

public:
    Bed() : Furniture(0, 0, Material::Wood), bedSize(BedSize::Single) {}
    Bed(double p, double d, Material m, BedSize b) : Furniture(p, d, m), bedSize(b)
    {
    }
    void setBedSize(BedSize val)
    {
        bedSize = val;
    }
    string getBedSize()
    {
        if (bedSize == BedSize::Single)
            return string("Single");
        else if (bedSize == BedSize::SemiDouble)
            return string("Semi-Double");
        else if (bedSize == BedSize::Double)
            return string("Double");
        else
            return string("");
    }
    void productDetails()
    {
        LINE0
        getInfo();
        cout << "\nBed Size: " << getBedSize() << endl;
        LINE1
    }
};

enum class SofaSize
{
    One,
    Two,
    Three,
    Four,
    Five
};

class Sofa : public Furniture
{
private:
    SofaSize sofaSize;

public:
    Sofa(double p, double d, Material m, SofaSize s) : Furniture(p, d, m), sofaSize(s)
    {
    }
    Furniture *f;
    void a()
    {
        f = new Bed();
    }
    void setSofaSize(SofaSize val)
    {
        sofaSize = val;
    }
    string getSofaSize()
    {
        if (sofaSize == SofaSize::One)
            return string("One");
        else if (sofaSize == SofaSize::Two)
            return string("Two");
        else if (sofaSize == SofaSize::Three)
            return string("Three");
        else if (sofaSize == SofaSize::Four)
            return string("Four");
        else if (sofaSize == SofaSize::Five)
            return string("Five");
        else
            return string("");
    }
    void productDetails()
    {
        LINE0
        getInfo();
        cout << "\nSofa Size: " << getSofaSize() << endl;
        LINE1
    }
    ~Sofa()
    {
        delete f;
    }
};

enum class AlmirahSize
{
    Two,
    Three,
    Four
};

class Almirah : public Furniture
{
private:
    AlmirahSize almirahSize;

public:
    Almirah(double p, double d, Material m, AlmirahSize a) : Furniture(p, d, m), almirahSize(a)
    {
    }
    void setAlmirahSize(AlmirahSize val)
    {
        almirahSize = val;
    }
    string getAlmirahSize()
    {
        if (almirahSize == AlmirahSize::Two)
            return string("Two");
        else if (almirahSize == AlmirahSize::Three)
            return string("Three");
        else if (almirahSize == AlmirahSize::Four)
            return string("Four");
        else
            return string("");
    }
    void productDetails()
    {
        LINE0
        getInfo();
        cout << "\nAlmirah Size: " << getAlmirahSize() << endl;
        LINE1
    }
};

void sort_furniture_discount(Furniture *furnitures[], int no_of_furnitures)
{
    for (int i = 0; i < no_of_furnitures; i++)
    {
        for (int j = i + 1; j < no_of_furnitures; j++)
            if (furnitures[i]->getDiscountPrice() < furnitures[j]->getDiscountPrice())
            {
                swap(furnitures[i], furnitures[j]);
            }
    }
};

int main()
{
    Furniture *f_list[100];

    for (int i = 0; i <= 100; i++)
        f_list[i] = nullptr;
    f_list[0] = new Bed(10000, 123, Material::Wood, BedSize::Single);
    f_list[1] = new Sofa(11000, 234, Material::Steel, SofaSize::Five);
    f_list[2] = new Almirah(13000, 345, Material::Wood, AlmirahSize::Two);
    f_list[3] = new Bed(10090, 123, Material::Wood, BedSize::Single);

    f_list[2]->setProductName("Bahari Bed");

    f_list[2]->setDiscountPercentage(30);
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->productDetails();
    }

    cout << "\n\nSorted Furniture List:" << endl;
    sort_furniture_discount(f_list, 4);
    for (int i = 0; i < 4; i++)
    {
        f_list[i]->productDetails();
    }

    for (int i = 0; i <= 100; i++)
        delete f_list[i];
}
