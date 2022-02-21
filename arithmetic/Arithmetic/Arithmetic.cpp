#include "Arithmetic.h"
#include <sstream>

auto Arithmetic::Calculate(const std::string expression) -> double {    // NOLINT(performance-unnecessary-value-param)
    std::vector<std::string> tokenizedExpression = TokenizeExpression(expression);

    // TODO return error if first token not "("


    Reduce(tokenizedExpression, 0, tokenizedExpression.size());
    return GetResult(tokenizedExpression);
}

 auto Arithmetic::TokenizeExpression(const std::string& expression) -> std::vector<std::string> {
    std::vector<std::string> expressionTokens;
    std::stringstream expressionStream(expression);
    std::string token;

    while (expressionStream >> token) {
        expressionTokens.push_back(token);
    }

    return expressionTokens;
}

void Arithmetic::Reduce(std::vector<std::string>& tokens, size_t start, size_t end) { // NOLINT(misc-no-recursion)
    // PEMDAS
    HandleParentheses(tokens, start, end);
    HandleMultiplyAndDivide(tokens, start, end);
    HandleAddAndSubtract(tokens, start, end);
}

// TODO passing around end as a reference is bad -- side effects, and state/context! Better if we passed sub-vectors (then we wouldn't need to pass start & end!)
void Arithmetic::HandleParentheses(std::vector<std::string> &tokens, size_t start, size_t &end) { // NOLINT(misc-no-recursion)
    for (auto i = start; i < end; i++) {
        if (tokens[i] == ")") {
            // TODO could maybe be extracted as a "handle matching open paren" function (or maybe just functions to find i & j???)
            for (int j = i-1; j >= start; j--) {
                if (tokens[j] == "(") {
                    // remove the matching parens from the vector
                    tokens.erase(tokens.begin()+i);
                    tokens.erase(tokens.begin()+j);

                    // Handle what was between the parens
                    Reduce(tokens, j, i-1);

                    // probably more efficient way of doing this, but this is foolproof...
                    end = static_cast<int>(tokens.size());
                    i = start;
                    break;
                }
                // TODO return error -- didn't find matching open paren
            }
        }
    }
}

void Arithmetic::HandleMultiplyAndDivide(std::vector<std::string> &tokens, size_t start, size_t &end) {
    for (auto i = start; i < end; i++) {
        if (tokens[i] == "*" || tokens[i] == "/") {
            if (tokens[i] == "*") {
                DoMathAndReduceToAnswer(tokens, end, i, [](double x, double y) -> double { return x * y; } );
            } else {
                DoMathAndReduceToAnswer(tokens, end, i, [](double x, double y) -> double { return x / y; } );
            }
        }
    }
}

void Arithmetic::DoMathAndReduceToAnswer(std::vector<std::string> &tokens, size_t &end, size_t &i, std::function<double (double, double)> math) {
    // get operands to left and right
    auto left = std::stod(tokens[i-1]);
    auto right = std::stod(tokens[i+1]);

    // do whatever math function you were given
    auto result = math(left, right);

    // replace operands & operator with result in token vector
    tokens.erase(tokens.begin()+i-1, tokens.begin()+i+2);
    tokens.insert(tokens.begin()+i-1, std::to_string(result));
    end -= 2;
    i -= 1;
}

void Arithmetic::HandleAddAndSubtract(std::vector<std::string> &tokens, size_t start, size_t &end) {
    for (auto i = start; i < end; i++) {
        if (tokens[i] == "+" || tokens[i] == "-") {
            if (tokens[i] == "+") {
                DoMathAndReduceToAnswer(tokens, end, i, [](double x, double y) -> double { return x + y; } );
            } else {
                DoMathAndReduceToAnswer(tokens, end, i, [](double x, double y) -> double { return x - y; } );
            }
        }
    }
}

auto Arithmetic::GetResult(std::vector<std::string> tokenVector) -> double {
    return !tokenVector.empty() ? std::stod(tokenVector[0]) : 0;
}