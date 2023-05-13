#include "../include/transaction.h"

Transaction::Transaction(const std::string& _from, const std::string& _to, double _amount, const std::string& _currency) // ✔
    : from { _from }
    , to { _to }
    , amount { _amount }
    , currency { _currency }
{
}

std::string Transaction::getFrom() const // ✔
{
    return from;
}

std::string Transaction::getTo() const // ✔
{
    return to;
}

double Transaction::getAmount() const // ✔
{
    return amount;
}

std::string Transaction::getCurrency() const // ✔
{
    return currency;
}

void Transaction::log()
{
    std::cout << "transactions Log:" << std::endl;
    std::cout << "from : " << from << "   to : " << to << "   amount : " << amount << "   Currency : " << currency << std::endl;
}
