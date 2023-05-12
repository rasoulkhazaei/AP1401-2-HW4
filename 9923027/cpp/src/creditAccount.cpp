#include "../include/creditAccount.h"

CreditAccount::CreditAccount(double balance, double credit_limit) // ✔
    : Account(balance)
    , creditLimit { credit_limit }
    , debt { 0 }
{
}

CreditAccount::CreditAccount(const CreditAccount& other) // ✔
    : CreditAccount(other.get_balance(), other.getCreditLimit())
{
    debt = other.getDebt();
}

CreditAccount::CreditAccount(CreditAccount&& other) // ✔
    : CreditAccount(other)
{
    other.Account::operator=(0);
    other.debt = 0;
    other.creditLimit = 0;
    other.interestrate = 0;
}

bool CreditAccount::withdraw(double amount) // ✔
{
    if (this->get_balance() - amount >= 0) {
        if (Account::withdraw(amount)) {
            return true;
        }
        return false;
    } else if (this->get_balance() - amount >= (-1 * creditLimit)) {
        debt += amount - this->get_balance();
        creditLimit -= amount - this->get_balance();
        Account::withdraw(this->get_balance());
        return true;
    } else
        return false;
}

double CreditAccount::getCreditLimit() const // ✔
{
    return creditLimit;
}

double CreditAccount::getInterestRate() const // ✔
{
    return interestrate;
}

double CreditAccount::getDebt() const // ✔
{
    return debt;
}

void CreditAccount::payDebt() // ✔
{
    if (this->getDebt() <= 0) {
        throw std::out_of_range { "you didn't have debt" };
    } else {
        debt = 0;
        creditLimit = 500;
    }
}

// for test
void CreditAccount::log()
{
    std::cout << "Credit Account log:" << std::endl;
    std::cout << "  CreitLimit is : " << creditLimit << std::endl;
    std::cout << "  debt is : " << debt << std::endl;
    std::cout << "  interestrate is : " << interestrate << std::endl;
    Account::log();
}
