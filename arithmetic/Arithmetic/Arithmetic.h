#include <string>
#include <vector>

class Arithmetic {
public:
    auto Do(const std::string& expression) -> int;

    int GetLeftOperand(unsigned long long int location);

    int GetRightOperand(unsigned long long int location);

    auto Calculate(std::vector<std::string>& tokens, int start, int end) -> int;
};