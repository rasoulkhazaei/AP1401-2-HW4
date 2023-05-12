#include "../include/transaction.h"

Transaction::Transaction(const std::string& from_, const std::string& to_, double amount_, const std::string& currency_)
    : from { from_ }
    , to { to_ }
    , amount { amount_ }
    , currency { currency_ }
{
}
std::string Transaction::getFrom() const
{
    return from;
}
std::string Transaction::getTo() const
{
    return to;
}
double Transaction::getAmount() const
{
    return amount;
}
std::string Transaction::getCurrency() const
{
    return currency;
}