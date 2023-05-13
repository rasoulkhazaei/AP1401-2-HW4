#include "../include/savingsAccount.h"

// Constructor
SavingsAccount::SavingsAccount(double balance = 0, double interest_rate = 0.01)
{
    double balance_after_interset = balance + (balance * interest_rate);
    Account { balance_after_interset };
    interestRate = interest_rate;
}

// copy counstructor
SavingsAccount::SavingsAccount(const SavingsAccount& A)
{
    interestRate = A.interestRate;
    step_interest = A.step_interest;
    withdrawCounts = A.withdrawCounts;
}

// move counstructor
SavingsAccount::SavingsAccount(SavingsAccount&& A)
{
    interestRate = A.interestRate;
    step_interest = A.step_interest;
    withdrawCounts = A.withdrawCounts;

    A.interestRate = 0;
    A.withdrawCounts = 0;
}

// operator = copy version
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& A)
{
    if (this == &A) // checks if both objects are same or not
        return *this;

    interestRate = A.interestRate;
    step_interest = A.step_interest;
    withdrawCounts = A.withdrawCounts;

    return *this;
}

// operator = move version
SavingsAccount& SavingsAccount::operator=(SavingsAccount&& A)
{
    if (this == &A) // checks if both objects are same or not
        return *this;

    interestRate = A.interestRate;
    step_interest = A.step_interest;
    withdrawCounts = A.withdrawCounts;

    A.interestRate = 0;
    A.step_interest = 0;
    A.withdrawCounts = 0;

    return *this;
}

// Member functions
void SavingsAccount::addInterest()
{
    interestRate += step_interest;
}

bool SavingsAccount::withdraw(double amount)
{
    if (withdrawCounts <= 3) {
        Account::withdraw(amount); // withdraw from account
        withdrawCounts += 1; // increasing number of with draws

        return true;
    } else {
        std::cout << "You can not withdraw beacuse you have withdrawed 3 time already this month" << std::endl;

        return false;
    }
}

SavingsAccount::~SavingsAccount()
{
    interestRate = 0;
    withdrawCounts = 0;
}
