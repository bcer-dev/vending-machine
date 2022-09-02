#include "Command.hpp"

Command::Command(std::string raw)
{
    int space_pos = raw.find(' ');

    if (space_pos == std::string::npos)
    {
        name = raw;
        return;
    }

    name = raw.substr(0, space_pos);
    args = raw.substr(space_pos + 1);
}