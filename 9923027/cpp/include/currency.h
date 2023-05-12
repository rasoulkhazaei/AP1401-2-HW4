#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <vector>

class Currency {
public:
    Currency(const std::string& _name, double _exchange_rate);
    ~Currency();
    std::string getName() const;
    double getExchangeRate() const;

    void log();

private:
    std::string name;
    double exchangeRate;
};

#endif