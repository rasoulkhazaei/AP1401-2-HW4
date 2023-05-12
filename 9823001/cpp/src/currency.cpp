#include "../include/currency.h"

Currency::Currency(const std::string& name_, double exchange_rate)
    : name { name_ }
    , exchangeRate { exchange_rate }
{
}
std::string Currency::getName() const
{
    return name;
}
double Currency::getExchangeRate() const
{
    return exchangeRate;
}