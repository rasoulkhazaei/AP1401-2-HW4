#include "../include/checkingAccount.h"

CheckingAccount::CheckingAccount(double balance, double _fee) // ✔
    : Account(balance)
    , fee { _fee }
{
}

CheckingAccount::CheckingAccount(const CheckingAccount& a) // ✔
    : CheckingAccount(a.get_balance(), a.fee)
{
}

CheckingAccount::CheckingAccount(CheckingAccount&& a)
    : Account(std::move(a))
    , fee { a.fee }
{
    a.fee = 0;
}

CheckingAccount& CheckingAccount::operator=(const CheckingAccount& a) // ✔
{
    if (this == &a)
        return *this;
    this->fee = a.fee;
    Account::operator=(a);
    return *this;
}

CheckingAccount& CheckingAccount::operator=(CheckingAccount&& a) // ✔
{
    this->fee = a.fee;
    Account::operator=(a);
    a.fee = 0;
    a.Account::operator=({ 0 });
    return *this;
}

bool CheckingAccount::withdraw(double amount) // ✔
{
    if (Account::withdraw(amount + fee)) {
        return true;
    }
    return false;
}

// test
void CheckingAccount::log()
{
    std::cout << "Checking Account log:" << std::endl;
    std::cout << "  fee is : " << fee << std::endl;
    Account::log();
}
