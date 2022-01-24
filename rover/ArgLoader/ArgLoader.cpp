#include "ArgLoader.h"

#define BASE_10 10

ArgLoader::ArgLoader(int argc, char ** argv)
{
    _argc = argc;
    _argv = argv;
}

std::string ArgLoader::GetArgAsString(int argNumber)
{
    CheckForValidArgNumber(argNumber);

    return std::string{_argv[argNumber]};
}

int ArgLoader::GetArgAsInt(int argNumber)
{
    CheckForValidArgNumber(argNumber);

    return (int)strtol(_argv[argNumber], nullptr, BASE_10);
}

void ArgLoader::CheckForValidArgNumber(int argNumber) const
{
    int number_of_args_given = _argc - 1;

    if (argNumber > number_of_args_given)
    {
        throw std::invalid_argument("ArgLoader::CheckForValidArgNumber(" + std::to_string(__LINE__) +
                                    "): Looking for argument #" + std::to_string(argNumber) + ", but only " +
                                    std::to_string(number_of_args_given) + " arguments were given.");
    }
}