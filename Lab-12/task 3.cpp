#include <iostream>
using namespace std;
const int MAX = 3;

template <class Type>
class my_stack
{
private:
    Type st[MAX];
    int top;

public:
    class Outofelement
    {};
    my_stack(){ 
        top = -1; 
    }
    void push(Type var){ 
        st[++top] = var; 
    }
    Type pop(){ 
        if (top == -1)
            throw Outofelement();
        return st[top--]; 
    }
    Type peek(){
        return st[top];
    }
};

int main()
{
    my_stack<float> s1;
    s1.push(1111.1F);
    s1.push(2222.2F);
    s1.push(3333.3F);
    try{
        cout << "1: " << s1.pop() << " " << s1.peek() << endl;
        cout << "2: " << s1.pop() << " " << s1.peek() << endl;
        cout << "3: " << s1.pop() << " " << s1.peek() << endl;
        cout << s1.pop() << endl;
    }
    catch (my_stack<float>::Outofelement){
        cout << "Nothing is there to pop()" << endl;
    }

    my_stack<long> s2;
    s2.push(123123123L);
    s2.push(234234234L);
    s2.push(345345345L);
    cout << "1: " << s2.pop() << " " << s2.peek() << endl;
    cout << "2: " << s2.pop() << " " << s2.peek() << endl;
    cout << "3: " << s2.pop() << " " << s2.peek() << endl;
    return 0;
}