#include "Arithmetic.h"
#include <sstream>

auto Arithmetic::Calculate(const std::string expression) -> double {    // NOLINT(performance-unnecessary-value-param)
    CheckExpressionValidity(expression);
    std::vector<std::string> tokenizedExpression = TokenizeExpression(expression);
    Reduce(tokenizedExpression, 0, tokenizedExpression.size());
    return GetResult(tokenizedExpression);
}

void Arithmetic::CheckExpressionValidity(const std::string& expression) {
    if (expression.empty() || expression.at(0) != '(') {
        throw std::invalid_argument("Expression must be surrounded by parentheses");
    }
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

// TODO should change this to pass a sub-vector instead (maybe slightly less performant, but much cleaner)
void Arithmetic::Reduce(std::vector<std::string>& tokens, size_t start, size_t end) {   // NOLINT(misc-no-recursion)
    HandleParentheses(tokens, start, end);
    HandleMultiplyAndDivide(tokens, start, end);
    HandleAddAndSubtract(tokens, start, end);
}

// TODO should change this to pass a sub-vector instead (maybe slightly less performant, but much cleaner)
void Arithmetic::HandleParentheses(std::vector<std::string> &tokens, size_t start, size_t &end) {   // NOLINT(misc-no-recursion)
    for (auto i = start; i < end; i++) {
        if (tokens[i] == ")") {
            for (int j = i-1; j >= start; j--) {
                if (tokens[j] == "(") {
                    // TODO take care of these "sections" after sub-vector change
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
            }
        }
    }
}

// TODO should change this to pass a sub-vector instead (maybe slightly less performant, but much cleaner)
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

// TODO should change this to pass a sub-vector instead (maybe slightly less performant, but much cleaner)
void Arithmetic::DoMathAndReduceToAnswer(std::vector<std::string> &tokens, size_t &end, size_t &i, const std::function<double (double, double)>& math) {
    // TODO take care of these "sections" after sub-vector change
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

// TODO should change this to pass a sub-vector instead (maybe slightly less performant, but much cleaner)
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