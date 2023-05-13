#include "../include/CheckingAccount.h"

CheckingAccount::CheckingAccount(double balance = 0, double fee = 1)
{
    double balance_after_fee = balance - fee;
    Account { balance_after_fee };
    fee = fee;
}

CheckingAccount::~CheckingAccount()
{
    fee = 0;
}

// copy counstructor
CheckingAccount::CheckingAccount(const CheckingAccount& A)
{
    fee = A.fee;
}

// move counstructor
CheckingAccount::CheckingAccount(CheckingAccount&& A)
{
    fee = A.fee;
    A.fee = 0;
}

// = copy version
CheckingAccount& CheckingAccount::operator=(const CheckingAccount& A)
{
    if (this == &A) // checks if both objects are same or not
        return *this;

    fee = 0;

    fee = A.fee;

    return *this;
}

// = move version
CheckingAccount& CheckingAccount::operator=(CheckingAccount&& A)
{
    if (this == &A) // checks if both objects are same or not
        return *this;

    fee = 0;

    fee = A.fee;

    A.fee = 0;

    return *this;
}

// NO we can not meke withdraw const beacuse it would change balance value
bool CheckingAccount::withdraw(double amount)
{
    return Account::withdraw(amount);
}