#include <iostream>
#include <iomanip>
#include "VendingMachine.hpp"
#include "Command.hpp"

#ifdef DEBUG
static void PrintCommand(Command &c)
{
    std::cout << "CMD: " 
                << c.GetName()
                << ", ARGS: "
                << c.GetArgs() 
                << '\n';
}
#endif

static bool IsNumber(std::string str)
{
    bool is_negative = false;
    bool has_point = false;

    for (auto c : str)
    {
        if (!(isdigit(c) || c == '-' || c == '.'))
        {
            return false;
        }

        if (c == '-')
        {
            if (is_negative)
            {
                return false;
            }

            is_negative = true;
        }

        if (c == '.')
        {
            if (has_point)
            {
                return false;
            }

            has_point = true;
        }
    }

    return true;
}

int main()
{
    bool is_admin = false;
    VendingMachine machine;
    std::string buffer;

    while (1)
    {
        std::cout << "Balance: $" << std::setprecision(2) << machine.GetBalance() << "\n\n";
        std::cout << "> ";
        std::getline(std::cin, buffer);
        std::cout << "\n";

        Command command(buffer);

        
        if (command.GetName() == "exit")
        {
            break;
        }

        else if (command.GetName() == "add")
        {
            if (command.GetArgs().length() == 0 || !IsNumber(command.GetArgs()))
            {
                std::cerr << "Invalid argument: " << command.GetArgs() << "\n\n";
                continue;
            }

            double amount = std::stod(command.GetArgs());
            machine.AddMoney(amount);
        }

        else if (command.GetName() == "buy")
        {
            auto slot = command.GetArgs();

            if (slot.length() == 0 || !machine.HasSlot(slot))
            {
                std::cerr << "Invalid Slot: " << command.GetArgs() << "\n\n";
                continue;
            }

            if (machine.GetBalance() < machine.GetPrice(slot))
            {
                std::cerr << "Insufficient Funds.\n\n";
                continue;
            }

            machine.Buy(slot);
            std::cout << "Vending...\n\n";
        }

        else if (command.GetName() == "slot")
        {
            if (!is_admin)
            {
                std::cerr << "You do not have permission to do that.\n\n";
                continue;
            }

            int space_index = command.GetArgs().find(' ');

            if (space_index == std::string::npos)
            {
                std::cerr << "Invalid Arguments: " << command.GetArgs() << "\n\n";
                continue;
            }

            auto slot = command.GetArgs().substr(0, space_index);
            auto price_str = command.GetArgs().substr(space_index + 1);

            if (price_str.length() == 0 || !IsNumber(price_str))
            {
                std::cerr << "Invalid Price: " << price_str << "\n\n";
                continue;
            }

            machine.AddProduct(slot, std::stod(price_str));
            std::cout << "Successfully set the price of " << slot << " to $" << price_str << "\n\n";
        }

        else if (command.GetName() == "123abc")
        {
            is_admin = true;
            std::cout << "Admin privelages enabled.\n\n";
        }

        else
        {
            std::cerr << "Invalid command: " << command.GetName() << '\n';
        }

        std::cout << '\n';
    }

    std::cout << "\n\nHave a good day!\n";
    return EXIT_SUCCESS;
}