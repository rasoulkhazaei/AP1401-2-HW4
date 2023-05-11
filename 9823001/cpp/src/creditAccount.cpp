#include "../include/creditAccount.h"

CreditAccount::CreditAccount(double balance, double credit_limit)
    : Account(balance)
    , creditLimit { credit_limit }
{
}
bool CreditAccount::withdraw(double amount)
{
    double balance = this->get_balance();

    if (amount > (balance + creditLimit)) {
        std::cout << "You can not withdraw this much of money" << std::endl;
        return 0;
    }
    if (amount > balance) {
        this->deposit(-balance);
        debt = amount - balance;
        return 1;
    }
    this->deposit(-amount);
    return 1;
}
double CreditAccount::getCreditLimit()
{
    return creditLimit;
}
// CreditAccount::getInterestRate()
// {
// ????
// }
double CreditAccount::getDebt()
{
    return debt;
}
void CreditAccount::payDebt()
{
    debt = 0;
}