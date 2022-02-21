#include <string>
#include <vector>
#include <functional>

class Arithmetic {
public:
    auto Calculate(std::string expression) -> double;

private:
    static auto TokenizeExpression(const std::string& expression) -> std::vector<std::string>;
    void Reduce(std::vector<std::string> &tokens, size_t start, size_t end);
    void HandleParentheses(std::vector<std::string> &tokens, size_t start, size_t &end);
    static void HandleMultiplyAndDivide(std::vector<std::string> &tokens, size_t start, size_t &end) ;
    static void HandleAddAndSubtract(std::vector<std::string> &tokens, size_t start, size_t &end) ;
    static void DoMathAndReduceToAnswer(std::vector<std::string> &tokens, size_t &end, size_t &i, std::function<double (double, double)> math);
    static auto GetResult(std::vector<std::string> tokenVector) -> double;
};