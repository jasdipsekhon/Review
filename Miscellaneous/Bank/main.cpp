#include <iostream>
#include "bank.h"
#include "bank.cpp"
using namespace std;

int main()
{
    Bank account(50);
    account.deposit(100);
    account.withdraw(50);
    cout << account.getTotal() << endl;
    return 0;
}
