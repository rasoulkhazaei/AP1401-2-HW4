#include "../include/banckingSystem.h"

BankingSystem::BankingSystem(const BankingSystem& other) // ✔
    : currencies_ { other.currencies_ }
    , customers_ { other.customers_ }
{
    // for (size_t i { 0 }; i < other.currencies_.size(); i++) {
    //     currencies_.push_back(other.currencies_[i]);3
    // }
    // for (size_t i { 0 }; i < other.customers_.size(); i++) {
    //     customers_.push_back(other.customers_[i]);
    // }
}

BankingSystem::BankingSystem(BankingSystem&& other) // ✔
    : currencies_ { std::move(other.currencies_) }
    , customers_ { std::move(other.customers_) }
{
}

BankingSystem& BankingSystem::operator=(const BankingSystem& other) // ✔
{
    this->currencies_ = other.currencies_;
    this->customers_ = other.customers_;
    return *this;
}

BankingSystem& BankingSystem::operator=(BankingSystem&& other) // ✔
{
    this->currencies_ = std::move(other.currencies_);
    this->customers_ = std::move(other.customers_);
    return *this;
}

void BankingSystem::addCustomer(Customer* customer) // ✔
{
    customers_.push_back(customer);
}

bool BankingSystem::transfer(Customer* sender, Account* sender_account, Customer* receiver, Account* receiver_account, double amount, const Currency& currency) // this function have some nonsense erors
{
    if (sender_account->withdraw(amount)) {
        receiver_account->deposit(amount);
        sender_account->transactions_.push_back(Transaction(sender->getName(), receiver->getName(), amount, currency.getName()));
        receiver_account->transactions_.push_back(Transaction(sender->getName(), receiver->getName(), amount, currency.getName()));
        return true;
    }
    return false;
}

double BankingSystem::convert(double amount, const Currency& from_currency, const Currency& to_currency) const // ✔
{
    return amount * from_currency.getExchangeRate() / to_currency.getExchangeRate();
}

void BankingSystem::log()
{
    std::cout << "Banking System log:" << std::endl;
    for (size_t i { 0 }; i < customers_.size(); i++) {
        customers_[i]->log();
    }
    for (size_t i { 0 }; i < currencies_.size(); i++) {
        currencies_[i].log();
    }
}
