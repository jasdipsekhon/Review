#ifndef bank_h
#define bank_h

class Bank
{

public:
    double savings;
    Bank(double);
    double withdraw(double);
    double deposit(double);
    double getTotal();
};
#endif 
