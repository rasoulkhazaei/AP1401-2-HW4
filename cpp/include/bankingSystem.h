#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include "account.h"
#include "currency.h"
#include "customer.h"
#include <iostream>
#include <vector>

class BankingSystem {
public:
    BankingSystem() = default;
    ~BankingSystem() = default;
    BankingSystem(const BankingSystem&) = default;
    BankingSystem(BankingSystem&&) = default;
    BankingSystem& operator=(const BankingSystem&) = default;
    BankingSystem& operator=(BankingSystem&&) = default;
    // void addCustomer(Customer*, Account*, Customer*, Account*, double, Currency&);
    double convert(double, const Currency&, const Currency&) const;

private:
    std::vector<Customer*> customers_;
    std::vector<Currency> currencies_;
};

#endif