#include <string>
#include <vector>

class Arithmetic {
public:
    auto Do(const std::string& expression) -> int;
    void Calculate(std::vector<std::string>& tokens, int start, int end);
};