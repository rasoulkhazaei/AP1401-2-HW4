#include "../include/account.h"

Account::Account(double balance) // ✔
    : balance_ { balance }
{
}

Account::Account(const Account& a) // ✔
    : Account(a.get_balance())
{
}

Account::Account(Account&& a) // ✔
    : Account(a.get_balance())
{
    a.balance_ = 0;
}

Account& Account::operator=(const Account& a) // ✔
{
    balance_ = a.get_balance();
    return *this;
}

Account& Account::operator=(Account&& a) // ✔
{
    balance_ = a.get_balance();
    a.balance_ = 0;
    a.~Account();
    return *this;
}

void Account::deposit(double amount) // ✔
{
    balance_ += amount;
}

bool Account::withdraw(double amount) // ✔
{
    if (amount > balance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

double Account::get_balance() const // ✔
{
    return balance_;
}

// for test
void Account::log()
{
    std::cout << "  Account balance is : " << balance_ << std::endl;
    for (size_t i {}; i < transactions_.size(); i++) {
        transactions_[i].log();
    }
    std::cout << "----------------------------------------" << std::endl;
}
