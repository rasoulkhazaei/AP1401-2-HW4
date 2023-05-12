#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include "account.h"
#include "checkingAccount.h"
#include "creditAccount.h"
#include "currency.h"
#include "customer.h"
#include "savingsAccount.h"
#include "transaction.h"
#include <iostream>
#include <vector>

class BankingSystem {
public:
    BankingSystem() = default;
    ~BankingSystem() = default;
    BankingSystem(const BankingSystem& other);
    BankingSystem(BankingSystem&& other);
    BankingSystem& operator=(const BankingSystem& other);
    BankingSystem& operator=(BankingSystem&& other);
    void addCustomer(Customer* customer);
    bool transfer(Customer* sender, Account* sender_account,
        Customer* receiver, Account* receiver_account,
        double amount, const Currency& currency);
    double convert(double amount, const Currency& from_currency,
        const Currency& to_currency) const;

    void log();

private:
    std::vector<Customer*> customers_;
    std::vector<Currency> currencies_ {};
};

#endif