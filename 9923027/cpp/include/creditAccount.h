#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "account.h"
#include "checkingAccount.h"
#include "creditAccount.h"
#include "currency.h"
#include "customer.h"
#include "savingsAccount.h"
#include "transaction.h"
#include <iostream>
#include <vector>

class CreditAccount : public Account {
public:
    CreditAccount(double balance = 0, double credit_limit = 500);
    ~CreditAccount() = default;
    CreditAccount(const CreditAccount& other);
    CreditAccount(CreditAccount&& other);
    bool withdraw(double amount) override;
    double getCreditLimit() const;
    double getInterestRate() const;
    double getDebt() const;
    void payDebt();

    void log() override;

private:
    double creditLimit;
    double debt { 0 };
    double interestrate { 0.1 };
};

#endif