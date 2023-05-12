#include "../include/currency.h"

Currency::Currency(const std::string& _name, double _exchange_rate) // ✔
    : name { _name }
    , exchangeRate { _exchange_rate }
{
}

Currency::~Currency()
{
}

std::string Currency::getName() const // ✔
{
    return name;
}

double Currency::getExchangeRate() const // ✔
{
    return exchangeRate;
}

void Currency::log()
{
    std::cout << "Currency log :" << std::endl;
    std::cout << "  name is : " << name << std::endl;
    std::cout << "  ExchangeRate is : " << exchangeRate << std::endl;
}
