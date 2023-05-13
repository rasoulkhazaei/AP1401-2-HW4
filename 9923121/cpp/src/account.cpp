#include "../include/account.h"
#include <compare>
#include <iostream>
#include <string>
#include <typeinfo>

// Constructor
Account::Account(double balance)
{
    std::cout << "Account constractor" << std::endl;
    balance_ = balance;
}

Account::Account(const Account& A) // Copy Counstructor
{
    std::cout << "copy constractor" << std::endl;
    balance_ = A.balance_;
}

Account::Account(Account&& A) // Move Counstructor
{
    std::cout << "Move constractor" << std::endl;
    balance_ = A.balance_;
    A.balance_ = 0;
}

Account& Account::operator=(const Account& A) // operator = (For L values)
{
    std::cout << "Operator = Copy version " << std::endl;
    if (this == &A) // checks if both objects are same or not
        return *this;
    // delete section
    balance_ = 0;
    // copy section
    balance_ = A.balance_;

    return *this;
}

Account& Account::operator=(Account&& A) // operator = (For R values)
{
    std::cout << "Operator = Move version " << std::endl;
    if (this == &A) // checks if both objects are same or not
        return *this;
    // delete section
    balance_ = 0;
    // move section
    balance_ = A.balance_;

    // nullptr ??
    A.balance_ = 0;

    return *this;
}

// Member functions
double Account::get_balance()
{
    return balance_;
}

void Account::deposit(double amount)
{
    balance_ += amount;
}

bool Account::withdraw(double amount)
{
    if (amount <= balance_) { /* If there is money then user can withdraw */

        balance_ -= amount;

        return true;
    } else
        return false;
}

// Distructor
Account::~Account()
{
    balance_ = 0;
}