#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "../include/account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(double balance = 0, double interest_rate = 0.01);
    ~SavingsAccount();

    SavingsAccount(const SavingsAccount& A);
    SavingsAccount(SavingsAccount&& A);
    SavingsAccount& operator=(const SavingsAccount& A);
    SavingsAccount& operator=(SavingsAccount&& A);

    void addInterest();
    bool withdraw(double amount) override ;

private:
    double interestRate;
    double step_interest { 0.001 }; // For increasing  interestRate
    size_t withdrawCounts { 0 };
};

#endif
