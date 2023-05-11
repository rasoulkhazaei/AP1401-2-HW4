#include "../include/account.h"

Account::Account(double balance)
    : balance_ { balance }
{
}
void Account::deposit(double amount)
{
    balance_ += amount;
    std::cout << "account deposit : " << balance_ << std::endl;
}
bool Account::withdraw(double amount)
{
    std::cout << "account withdraw" << std::endl;
    if (balance_ < amount) {
        std::cout << "There is not enough money to withdraw" << std::endl;
        return 0;
    }
    // transactions_.push_back()
    balance_ -= amount;
    return 1;
}
double Account::get_balance() const
{
    return balance_;
}