#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "account.h"
#include "checkingAccount.h"
#include "creditAccount.h"
#include "currency.h"
#include "savingsAccount.h"
#include <iostream>
#include <unordered_map>
#include <vector>

class Customer {
public:
    Customer(const std::string& _name, const std::string& _password);
    Customer(const Customer& other);
    Customer(Customer&& other);
    Customer& operator=(const Customer& other);
    Customer& operator=(Customer&& other);
    ~Customer() = default;
    bool authenticate(const std::string& password);
    void addAccount(Account* account, const Currency& currency);
    std::vector<Account*>& getAccounts(const Currency& currency);
    std::string getName() { return name; }
    // for test
    void log();
    void setName(std::string a) { name = a; }

private:
    std::string name;
    std::string password;
    std::unordered_map<const Currency*, std::vector<Account*>> accounts;
};

#endif