#include "../include/customer.h"

Customer::Customer(const std::string& _name, const std::string& _password) // ✔
    : name { _name }
    , password { _password }
{
}

Customer::Customer(const Customer& other) // ✔
    : Customer(other.name, other.password)
{
    for (auto x : other.accounts) {
        accounts.insert({ x.first, x.second });
    }
}

Customer::Customer(Customer&& other)
    : Customer(other.name, other.password) // ✔
{
    for (auto x : other.accounts) {
        accounts.insert({ x.first, x.second });
    }
    other.~Customer();
}

Customer& Customer::operator=(const Customer& other) // ✔
{
    name = other.name;
    password = other.password;
    accounts.clear();
    for (auto x : other.accounts) {
        accounts.insert({ x.first, x.second });
    }
    return *this;
}

Customer& Customer::operator=(Customer&& other) // ✔
{
    name = other.name;
    password = other.password;
    accounts.clear();
    for (auto x : other.accounts) {
        accounts.insert({ x.first, x.second });
    }
    other.~Customer();
    return *this;
}

bool Customer::authenticate(const std::string& _password) // ✔
{
    return (password == _password);
}

void Customer::addAccount(Account* account, const Currency& currency) // ✔
{
    bool flag { false };
    for (auto& x : accounts) {
        if (x.first->getName() == currency.getName() && x.first->getExchangeRate() == currency.getExchangeRate()) {
            x.second.push_back(account);
            flag = true;
            break;
        }
    }
    if (!flag) {
        // std::cout << "--------" << std::endl;
        std::vector<Account*> v {};
        v.push_back(account);
        accounts.insert({ &currency, v });
    }
}

std::vector<Account*>& Customer::getAccounts(const Currency& currency) // ✔
{
    for (auto& x : accounts) {
        if (x.first->getName() == currency.getName() && x.first->getExchangeRate() == currency.getExchangeRate()) {
            return x.second;
        }
    }
    throw std::out_of_range { "Your index doesn't exist" };
}

void Customer::log()
{
    std::cout << "Customer Log :" << std::endl;
    std::cout << "  Name is : " << name << std::endl;
    std::cout << "  Password is : " << password << std::endl;
    for (auto& x : accounts) {
        for (size_t i { 0 }; i < x.second.size(); i++) {
            x.second[i]->log();
        }
    }
}
