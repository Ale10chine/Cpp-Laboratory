#include <iostream>
using namespace std;

class One
{
public:
    int F() { return 2; }
    virtual int G() { return 3; }
};

class Two : public One
{
public:
    int F() { return 4; }
    int G() { return 5; }
};

class Three : public Two
{
public:
    int G() { return 7; }
};

int main()
{
    One *p1;
    One ob1;
    Two ob2;
    Three ob3;

    p1 = &ob1;
    cout << p1->F() * p1->G();
    cout << endl;
    p1 = &ob2;
    cout << p1->F() * p1->G();
    cout << endl;
    p1 = &ob3;
    cout << p1->F() * p1->G();
    cout << endl;
    Two *p2;
    p2 = &ob3;
    cout << p2->F() * p2->G();
    cout << endl;
    return 0;
}