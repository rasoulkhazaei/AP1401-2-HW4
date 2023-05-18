#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <compare>
#include <iostream>
#include <unordered_map>
#include <vector>

class Account {
public:
    Account(double balance = 0);
    ~Account();
    Account(const Account& A);
    Account(Account&& A);
    Account& operator=(const Account& A);
    Account& operator=(Account&& A);

    virtual double get_balance();
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);

    std::vector<Transaction> transactions_;

private:
    double balance_;
};

#endif
