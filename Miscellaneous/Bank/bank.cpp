#include <iostream>
#include "bank.h"
using namespace std;

Bank::Bank(double savings)
{
    this->savings = savings;
}
double Bank::deposit(double money)
{
    return savings += money;
}

double Bank::withdraw(double money)
{
    return savings -= money; 
}

double Bank::getTotal()
{
    return savings;
}

