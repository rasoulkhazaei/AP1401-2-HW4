#include "../include/backingSystem.h"
#include <algorithm>
#include <compare>
#include <iostream>
#include <string>
#include <typeinfo>

BankingSystem::BankingSystem() { }

BankingSystem::~BankingSystem()
{
    for (auto& customer : customers_) {
        delete customer;
    }
}

// copy constructor
BankingSystem::BankingSystem(const BankingSystem& other)
{
    // Deep copy of customers and currencies
    for (auto& customer : other.customers_) {
        customers_.push_back(new Customer(*customer));
    }
    currencies_ = other.currencies_;
}

// move constuctor
BankingSystem::BankingSystem(BankingSystem&& other)
{
    customers_ = other.customers_;
    currencies_ = other.currencies_;

    // Reset the other object
    other.customers_.clear();
    other.currencies_.clear();
}

// copy version
BankingSystem& BankingSystem::operator=(const BankingSystem& other)
{
    if (this == &other) {
        return *this;
    }

    // Free the memory of the old customers
    for (auto& customer : customers_) {
        delete customer;
    }

    customers_.clear();
    currencies_.clear();

    // Deep copy of customers and currencies
    for (auto& customer : other.customers_) {
        customers_.push_back(new Customer(*customer));
    }
    currencies_ = other.currencies_;

    return *this;
}

// move version
BankingSystem& BankingSystem::operator=(BankingSystem&& other)
{
    if (this == &other) {
        return *this;
    }

    // Free the memory of the old customers
    for (auto& customer : customers_) {
        delete customer;
    }

    customers_ = other.customers_;
    currencies_ = other.currencies_;

    // Reset the other object
    other.customers_.clear();
    other.currencies_.clear();

    return *this;
}

void BankingSystem::addCustomer(Customer* customer)
{
    customers_.push_back(customer);

    // Add customer's currencies to the BankingSystem's currencies
    for (const auto& currency : customer->getCurrencies()) {
        if (std::find(currencies_.begin(), currencies_.end(), currency) == currencies_.end()) {
            currencies_.push_back(currency);
        }
    }
}

bool BankingSystem::transfer(Customer* sender, Account* sender_account,
    Customer* receiver, Account* receiver_account,
    double amount, const Currency& currency)
{
    // Check if both customers are part of the BankingSystem
    if (std::find(customers_.begin(), customers_.end(), sender) == customers_.end() || std::find(customers_.begin(), customers_.end(), receiver) == customers_.end()) {
        return false;
    }

    // Check if the sender has enough funds
    if (!sender_account->withdraw(amount, currency)) {
        return false;
    }

    // Convert the amount to the receiver's currency
    double converted_amount = convert(amount, currency, receiver_account->getCurrency());

    // Deposit the converted amount to the receiver's account
    if (!receiver_account->deposit(converted_amount)) {
        // Refund the sender if the deposit fails
        sender_account->deposit(amount);
        return false;
    }

    return true;
}

double BankingSystem::convert(double amount, const Currency& from_currency,
    const Currency& to_currency) const
{
    double exchange_rate = from_currency.getExchangeRate(to_currency);
    return amount * exchange_rate;
}
