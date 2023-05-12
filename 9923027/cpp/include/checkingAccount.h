#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "account.h"
#include <iostream>
#include <vector>

class CheckingAccount : public Account {
public:
    CheckingAccount(double balance = 0, double _fee = 1);
    ~CheckingAccount() = default;
    CheckingAccount(const CheckingAccount&);
    CheckingAccount(CheckingAccount&&);
    CheckingAccount& operator=(const CheckingAccount&);
    CheckingAccount& operator=(CheckingAccount&&);
    bool withdraw(double amount);
    double get_fee() const { return fee; } // ✔

    void log() override;

private:
    double fee;
};

#endif