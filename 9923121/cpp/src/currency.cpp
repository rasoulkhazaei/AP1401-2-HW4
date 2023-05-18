#include "../include/currency.h"
#include <compare>
#include <iostream>
#include <string>
#include <typeinfo>

Currency::Currency(const std::string& name_, double exchange_rate)
{
    name = name_;
    exchangeRate = exchange_rate;
}

std::string Currency::getName() const
{
    return name;
}

double Currency::getExchangeRate() const
{
    return exchangeRate;
}

Currency::~Currency()
{
    name = "";
    exchangeRate = 0;
}
