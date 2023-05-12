#ifndef SAVINGACOUNT_H
#define SAVINGACOUNT_H

#include "account.h"
#include "checkingAccount.h"
#include <iostream>
#include <vector>

class SavingsAccount : public Account {
public:
    SavingsAccount(double balance = 0, double interest_rate = 0.01);
    ~SavingsAccount() = default;
    SavingsAccount(const SavingsAccount&);
    SavingsAccount(SavingsAccount&&);
    SavingsAccount& operator=(const SavingsAccount&);
    SavingsAccount& operator=(SavingsAccount&&);
    void addInterest(double ir);
    bool withdraw(double amount) override;

    void log() override;

private:
    double interestRate;
    size_t withdrawCounts { 0 };
};

#endif