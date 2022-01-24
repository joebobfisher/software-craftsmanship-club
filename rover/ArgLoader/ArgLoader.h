#include <string>
#include <stdexcept>

class ArgLoader
{
private:
    void CheckForValidArgNumber(int argNumber) const;

    int _argc;
    char ** _argv;

public:
    ArgLoader(int argc, char ** argv);
    std::string GetArgAsString(int argNumber);
    int GetArgAsInt(int argNumber);
};