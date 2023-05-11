#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "account.h"
#include <iostream>
class SavingsAccount
    : public Account {
public:
    SavingsAccount(double balance = 0, double interest_rate = 0.01);
    ~SavingsAccount() = default;
    SavingsAccount(const SavingsAccount&) = default;
    SavingsAccount(SavingsAccount&&) = default;
    SavingsAccount& operator=(const SavingsAccount&) = default;
    SavingsAccount& operator=(SavingsAccount&&) = default;
    void addInterest(double);
    virtual bool withdraw(double) override;

private:
    double interestRate;
    size_t withdrawCounts;
};

#endif