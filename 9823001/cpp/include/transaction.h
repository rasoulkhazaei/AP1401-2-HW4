#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
class Transaction {
public:
    Transaction(const std::string&, const std::string&, double, const std::string&);
    ~Transaction() = default;

    std::string getFrom() const;
    std::string getTo() const;
    double getAmount() const;
    std::string getCurrency() const;

private:
    std::string from;
    std::string to;
    double amount;
    std::string currency;
};

#endif