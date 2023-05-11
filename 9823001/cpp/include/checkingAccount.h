#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "account.h"
class CheckingAccount
    : public Account {
public:
    CheckingAccount(double balance = 0, double fee = 1);
    virtual ~CheckingAccount() override = default;
    CheckingAccount(const CheckingAccount&) = default;
    CheckingAccount(CheckingAccount&&) = default;
    CheckingAccount& operator=(const CheckingAccount&) = default;
    CheckingAccount& operator=(CheckingAccount&&) = default;
    virtual bool withdraw(double) override;

private:
    double fee;
};

#endif