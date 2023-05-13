#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <vector>

class Transaction {
public:
    Transaction(const std::string& from, const std::string& to, double amount, const std::string& currency);
    std::string getFrom() const;
    std::string getTo() const;
    double getAmount() const;
    std::string getCurrency() const;

    void log();

private:
    std::string from;
    std::string to;
    double amount;
    std::string currency;
};

#endif