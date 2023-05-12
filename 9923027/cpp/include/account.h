#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"
#include <iostream>
#include <string>
#include <vector>

class Account {
public:
    Account(double balance = 0);
    virtual ~Account() = default; // it has to be virtual because when we use polymorphism we should run derived classes destructors first then run base destructor unless the compiler will not destruct drived destructors.
    Account(const Account&);
    Account(Account&&);
    Account& operator=(const Account&);
    Account& operator=(Account&&);

    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual double get_balance() const;
    // virtual void set_balance(double a) { balance_ = a; } // this function shouldn't be created

    std::vector<Transaction> transactions_;

    virtual void log();

private:
    double balance_;
};

#endif