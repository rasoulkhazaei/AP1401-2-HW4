#include "../include/checkingAccount.h"

CheckingAccount::CheckingAccount(double balance, double fee_)
    : Account(balance)
    , fee { fee_ }
{
}
bool CheckingAccount::withdraw(double amount)
{
    if (amount > this->get_balance()) {
        std::cout << "There is not enough money to withdraw" << std::endl;
        return 0;
    }
    this->deposit(-(fee + amount));
    // transactions_.push_back(????)
    return 1;
}