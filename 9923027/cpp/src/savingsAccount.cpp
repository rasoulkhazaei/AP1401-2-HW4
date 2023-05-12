#include "../include/savingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double interest_rate) // ✔
    : Account(balance)
    , interestRate { interest_rate }
{
}

SavingsAccount::SavingsAccount(const SavingsAccount& a) // ✔
    : SavingsAccount(a.get_balance(), a.interestRate)
{
}

SavingsAccount::SavingsAccount(SavingsAccount&& a) // ✔
    : SavingsAccount(a)
{
    a.Account::operator=(0);
    a.addInterest(0);
}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& a) // ✔
{
    this->Account::operator=(a);
    this->interestRate = a.interestRate;
    return *this;
}

SavingsAccount& SavingsAccount::operator=(SavingsAccount&& a) // ✔
{
    this->interestRate = a.interestRate;
    this->Account::operator=(a);
    a.Account::operator=(0);
    a.addInterest(0);
    return *this;
}

void SavingsAccount::addInterest(double ir) // ✔
{
    interestRate = ir;
}

bool SavingsAccount::withdraw(double amount) // ✔
{
    if (withdrawCounts < 3) {
        withdrawCounts += 1;
        if (Account::withdraw(amount)) {
            return true;
        }
    }
    throw std::out_of_range { "You Already withdrew 3 times!" };
}

// for test
void SavingsAccount::log()
{
    std::cout << "Saving Account Log :" << std::endl;
    std::cout << "  Interest Rate is : " << interestRate << std::endl;
    std::cout << "  withdraw Count is : " << withdrawCounts << std::endl;
    Account::log();
}
