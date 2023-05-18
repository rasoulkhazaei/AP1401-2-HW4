#include <iostream>

#include "../include/account.h"
#include "../include/backingSystem.h"
#include "../include/creditAccount.h"
#include "../include/currency.h"
#include "../include/customer.h"
#include "../include/savingsAccount.h"
#include "../include/transaction.h"

int main(int argc, char* argv[])
{
    Account A { 5 };
    std::cout << "Account balance is: " << A.get_balance() << std::endl;
}
