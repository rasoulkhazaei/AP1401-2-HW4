#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>
class Currency {
public:
    Currency(const std::string&, double);
    ~Currency() = default;
    std::string getName() const;
    double getExchangeRate() const;

private:
    std::string name;
    double exchangeRate;
};

#endif
