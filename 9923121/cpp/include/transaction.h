#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "../include/account.h"

class Transaction : public Account {
public:
    Transaction(const std::string& from_, const std::string& to_, double amount_, const std::string& currency_);

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
