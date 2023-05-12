#include <iostream>

#include "../include/account.h"
#include "../include/banckingSystem.h"
#include "../include/checkingAccount.h"
#include "../include/creditAccount.h"
#include "../include/currency.h"
#include "../include/customer.h"
#include "../include/savingsAccount.h"
#include "../include/transaction.h"

int main(int argc, char* argv[])
{
    Customer Mojtaba { "Mojtaba", "12345678" };
    Customer Rasoul { "Rasoul", "12345678" };
    Customer* cus1 = &Mojtaba;
    Customer* cus2 = &Rasoul;
    SavingsAccount s { 240, .01 };
    CreditAccount c { 500, 100 };
    CreditAccount d { 700, 100 };
    Account* a = &s;
    Account* b = &c;
    Account* b2 = &d;
    Currency USD { "USD", 1 };
    Currency TMN { "TMN", .02 };
    Currency EUR { "EUR", 1.2 };
    BankingSystem Mellat;
    Mojtaba.addAccount(a, USD);
    Mojtaba.addAccount(b, TMN);
    // Mojtaba.log();

    Rasoul.addAccount(b2, TMN);
    Mellat.addCustomer(cus1);
    Mellat.addCustomer(cus2);
    Mellat.log();
    Mellat.transfer(cus1, b, cus2, b2, 178, TMN);
    Mellat.log();
    // // Rasoul = Mojtaba;
    // // Customer Mahdi { Mojtaba };
    // // Mahdi.setName("mahdi");
    // // Mellat.addCustomer(&Mahdi);
    // // Mellat.log();
    // // std::vector<Account*> v {};
    // // v = Mahdi.getAccounts(USD);
    // // for (size_t i = 0; i < v.size(); i++) {
    // //     v[i]->log();
    // // }
    // // BankingSystem Tejarat {};
    // // Tejarat = std::move(Mellat);
    // // Mellat.log();
    // // Tejarat.log();
    // // double x { Tejarat.convert(100, TMN, EUR) };
    // // Mellat.log();
    // // Mellat.transfer(cus1, b, cus2, b2, 650, TMN);
    // Mellat.log();
    // // std::cout<< x << std::endl;
    // // std::swap(Mojtaba, Rasoul);

    // CreditAccount c { 500, 500 };
    // c.withdraw(1000);
    // c.log();
    // CreditAccount c2 { std::move(c) };
    // c.log();
    // c2.log();
    // c.log();
    // c2.log();
    // CreditAccount c2 { c };
    // c.log();
    // c2.log();
    // if () {
    //     c.log();
    // }
    // c2.log();
    // SavingsAccount c { 500, .01 };
    // SavingsAccount c2 { 400, 0.02 };
    // c.log();
    // c2.log();
    // c2 = std::move(c);
    // c.log();
    // c2.log();
    // CheckingAccount c2 { c };
    // c.log();
    // c2.log();
    // c.withdraw(100);
    // c.log();
    // c.withdraw(100);
    // c.log();
    // c.withdraw(100);
    // c.log();

    // Account a { 5 };
    // a.log();
    // Account b { 10 };
    // b = std::move(a);
    // a.log();
    // b.log();

    // a.withdraw(5);
    // a.log();

    return 0;
}
