#include "../include/savingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double interest_rate)
    : Account(balance)
    , interestRate { interest_rate }
{
}
void SavingsAccount::addInterest(double amount)
{
    interestRate = amount;
}
bool SavingsAccount::withdraw(double amount)
{
    withdrawCounts++;
    if (withdrawCounts > 3) {
        std::cout << "you have reached the limit" << std::endl;
    }
    Account::withdraw(amount);
    // transactions_.push_back(???)
    return 1;
}