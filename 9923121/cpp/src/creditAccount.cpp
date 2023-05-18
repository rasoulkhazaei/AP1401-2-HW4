#include "../include/creditAccount.h"
#include <compare>
#include <iostream>
#include <string>
#include <typeinfo>

CreditAccount::CreditAccount(double balance = 0, double credit_limit = 500)
{
    Account { balance };
    creditLimit = credit_limit;
}

CreditAccount::~CreditAccount()
{
    debt = 0;
}

// copy constructor
CreditAccount::CreditAccount(const CreditAccount& other)
{
    creditLimit = other.creditLimit;
    debt = other.debt;
}

// move constructor
CreditAccount::CreditAccount(const CreditAccount& other)
{
    creditLimit = other.creditLimit;
    debt = other.debt;

    creditLimit = 0;
    debt = 0;
}

bool CreditAccount::withdraw(double amount)
{
    double current_balance = Account::get_balance();
    if (current_balance >= amount) {
        return Account::withdraw(amount);
    } else {
        if ((current_balance + creditLimit) >= amount) {
            debt = std::abs(current_balance - amount);
            creditLimit -= debt;
            return Account::withdraw(current_balance); // Making account empty
        } else {
            throw "It is not possible to withdraw";
        }
    }
}

void CreditAccount::payDebt()
{
    if (debt == 0) {
        throw "There is no debts for this account to pay";
    } else {
        debt = 0; // pay debt
        creditLimit = 500;
    }
}

double CreditAccount::getDebt() const
{
    return debt;
}

double CreditAccount::getCreditLimit()
{
    return creditLimit;
}