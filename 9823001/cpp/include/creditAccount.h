#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "account.h"
#include "savingsAccount.h"

class CreditAccount
    : public Account {

public:
    CreditAccount(double balance = 0, double credit_limit = 500);
    ~CreditAccount() = default;
    CreditAccount(const CreditAccount&) = default;
    CreditAccount(CreditAccount&&) = default;
    virtual bool withdraw(double) override;
    double getCreditLimit();
    // double getInterestRate();
    double getDebt();
    void payDebt();

private:
    double creditLimit;
    double debt;
};

#endif