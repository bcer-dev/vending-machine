#include "VendingMachine.hpp"

VendingMachine::VendingMachine() : total_money{0} {}

double VendingMachine::GetBalance() const
{
    return total_money;
}

void VendingMachine::AddMoney(double amt)
{
    total_money += amt;
}

void VendingMachine::Buy(std::string slot)
{
    if (!HasSlot(slot))
    {
        return;
    }

    total_money -= GetPrice(slot);
}

bool VendingMachine::HasSlot(std::string slot)
{
    return products.count(slot) != 0;
}

double VendingMachine::GetPrice(std::string slot)
{
    if (!HasSlot(slot))
    {
        return 0;
    }

    return products[slot];
}

void VendingMachine::AddProduct(std::string slot, double price)
{
    products[slot] = price;
}