#ifndef VENDINGMACHINE_HPP
#define VENDINGMACHINE_HPP

#include <map>
#include <string>

class VendingMachine
{
private:
    double total_money;
    std::map<std::string, double> products;

public:
    VendingMachine();
    double GetBalance() const;
    void AddMoney(double amt);
    void Buy(std::string slot);
    bool HasSlot(std::string slot);
    double GetPrice(std::string slot);
    void AddProduct(std::string slot, double price);
};

#endif // VENDINGMACHINE_HPP