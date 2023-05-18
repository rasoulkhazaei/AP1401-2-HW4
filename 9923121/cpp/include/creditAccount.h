#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "../include/account.h"

class CreditAccount : public Account {
public:
    CreditAccount(double balance = 0, double credit_limit = 500);
    ~CreditAccount();
    CreditAccount(const CreditAccount& other);
    CreditAccount(CreditAccount&& other);
    bool withdraw(double amount) override;
    double getCreditLimit();
    double getInterestRate();
    double getDebt() const;
    void payDebt();

private:
    double creditLimit;
    double debt;
};

#endif
