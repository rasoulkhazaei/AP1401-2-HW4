#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"
#include <iostream>
#include <vector>

class Account {
public:
    Account(double balance = 0);
    virtual ~Account() = default;
    Account(const Account&) = default;
    Account(Account&&) = default;
    Account& operator=(const Account&) = default;
    Account& operator=(Account&&) = default;

    void deposit(double);
    virtual bool withdraw(double);
    double get_balance() const;

    std::vector<Transaction> transactions_;

private:
    double balance_;
};

#endif