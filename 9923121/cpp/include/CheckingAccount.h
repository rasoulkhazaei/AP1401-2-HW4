#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "../include/account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(double balance = 0, double fee = 1);
    ~CheckingAccount();
    CheckingAccount(const CheckingAccount&);
    CheckingAccount(CheckingAccount&&);
    CheckingAccount& operator=(const CheckingAccount&);
    CheckingAccount& operator=(CheckingAccount&&);

    bool withdraw(double amount) override;

private:
    double fee;
};

#endif
