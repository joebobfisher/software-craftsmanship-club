#include <string>
#include <vector>

class Arithmetic {
public:
    auto Calculate(const std::string& expression) -> double;
    void Reduce(std::vector<std::string>& tokens, int start, int end);
};