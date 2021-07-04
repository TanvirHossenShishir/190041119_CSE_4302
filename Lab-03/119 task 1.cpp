#include <bits/stdc++.h>

using namespace std;

class Counter
{
private:
    int count;
    int step;
public:
    Counter() : count(0), step(0) {}
    void setIncrementStep(int step_val)
    {
        step = step_val;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count += step;
    }
    void resetCount()
    {
        count = 0;
    }
};

int main()
{
    Counter c1;
    cout << "Count = " << c1.getCount() << endl;
    c1.setIncrementStep(5);
    c1.increment();
    cout << "Count = " << c1.getCount() << endl;
    c1.resetCount();
    cout << "Count = " << c1.getCount() << endl;
    return 0;
}
