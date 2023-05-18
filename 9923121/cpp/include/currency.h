#ifndef CURRENCY_H
#define CURRENCY_H
#include "../include/account.h"

class Currency {
public:
    Currency(const std::string& name, double exchange_rate);
    ~Currency();
    std::string getName() const;
    double getExchangeRate() const;

private:
    std::string name;
    double exchangeRate;
};

#endif
