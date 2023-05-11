#include "../include/customer.h"

Customer::Customer(const std::string& name_, const std::string& password_)
    : name { name_ }
    , password { password_ }
{
}

bool Customer::authenticate(const std::string& password_)
{
    if (password == password_)
        return 1;
    return 0;
}
// void Customer::addAccount(Account* account, const Currency& currency)
// {
// }
