#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command
{
private:
    std::string name;
    std::string args;

public:
    Command(std::string raw);

    inline std::string GetName() const
    {
        return name;
    }

    inline std::string GetArgs() const
    {
        return args;
    }
};

#endif // COMMAND_HPP