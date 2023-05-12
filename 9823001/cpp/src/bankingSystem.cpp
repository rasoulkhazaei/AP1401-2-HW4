#include "../include/bankingSystem.h"

double BankingSystem::convert(double amount, const Currency& from_currency,
    const Currency& to_currency) const
{
    return ((amount * to_currency.getExchangeRate()) / from_currency.getExchangeRate());
}