#include "../include/Customer.h"
#include <compare>
#include <iostream>
#include <string>
#include <typeinfo>

Customer::Customer(const std::string& name_, const std::string& password_)
{
    name = name_;
    password = password_;
}

Customer::Customer(const Customer& other)
{
    name = other.name;
    password = other.password;
}

Customer::Customer(Customer&& other)
{
    name = other.name;
    password = other.password;

    other.name = "";
    other.password = "";
}

Customer& Customer::operator=(const Customer& other)
{
    name = other.name;
    password = other.password;
}

Customer& Customer::operator=(Customer&& other)
{
    name = other.name;
    password = other.password;

    other.name = "";
    other.password = "";
}

Customer::~Customer()
{
    name = "";
    password = "";
}

bool Customer::authenticate(const std::string& password_)
{
    if (password == password_) {
        return true;
    } else {
        return false;
    }
}

void Customer::addAccount(Account* account, const Currency& currency)
{
    auto it = accounts.find(&currency);
    if (it != accounts.end()) {
        // Currency already exists, add account to existing vector
        it->second.push_back(account);
    } else {
        // Currency does not exist, create new vector
        std::vector<Account*> v { account };
        accounts.insert({ &currency, v });
    }
}

std::vector<Account*>& Customer::getAccounts(const Currency& currency)
{
    auto it = accounts.find(&currency);
    if (it != accounts.end()) {
        // Currency exists, return corresponding vector
        return it->second;
    } else {
        // Currency does not exist, return empty vector
        static std::vector<Account*> empty_vector;
        return empty_vector;
    }
}
