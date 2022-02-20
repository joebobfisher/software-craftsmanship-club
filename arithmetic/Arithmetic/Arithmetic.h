#include <string>
#include <vector>
#include <functional>

class Arithmetic {
public:
    auto Calculate(const std::string &expression) -> double;

private:
    auto Tokenize(const std::string &basicString) -> std::vector<std::string>;
    void Reduce(std::vector<std::string> &tokens, size_t start, size_t end);
    void HandleParentheses(std::vector<std::string> &tokens, size_t start, size_t &end);
    static void HandleMultiplyAndDivide(std::vector<std::string> &tokens, size_t start, size_t &end) ;
    static void HandleAddAndSubtract(std::vector<std::string> &tokens, size_t start, size_t &end) ;

    static void DoMathAndReduceToAnswer(std::vector<std::string> &tokens, size_t &end, size_t &i, std::function<double (double, double)> math);
};