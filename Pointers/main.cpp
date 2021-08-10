#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *p;
    p = &a;
    cout << a << endl; // value of a
    cout << &a << endl; // address of a
    cout << p << endl; // address of a
    cout << &p << endl; // adddress of p
    cout << *p << endl; // value of a
    *p = 10;
    cout << a << endl;
    int **q = &p;
    cout << *q << endl; // address of a
    cout << **q << endl; // value of a
    return 0;
} 



