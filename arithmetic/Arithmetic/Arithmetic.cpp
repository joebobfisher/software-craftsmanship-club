#include "Arithmetic.h"

auto Arithmetic::Calculate(const std::string& expression) -> double {
    //std::vector<std::string> v {"(","(","1","+","2",")","*","(","3","*","4",")",")"};
    //std::vector<std::string> v {"(", "1", "+", "(", "(", "2", "+", "3", ")", "*", "(","4", "*", "5",")", ")", ")"};
    //std::vector<std::string> v {"(", "5", "*", "(", "4", "*", "(", "3", "*", "(", "2", "*", "(", "1", "*", "9", ")", "/", "8", "-", "7", ")", "+", "6", ")", ")", ")"};
    //std::vector<std::string> v {"(","(","(",")","(",")",")",")"};

    // TODO Tokenize the expression string
    // TODO return error if first token not "("

    Reduce(v, 0, v.size());
    auto result = v.size() > 0 ? std::stod(v[0]) : 0;
    return result;
}

void Arithmetic::Reduce(std::vector<std::string>& tokens, int start, int end) { // NOLINT(misc-no-recursion)
    // PEMDAS: P
    // take care of parentheses
    for (int i = start; i < end; i++) {
        if (tokens[i] == ")") {
            for (int j = i-1; j >= start; j--) {
                if (tokens[j] == "(") {
                    // remove the matching parens from the vector
                    tokens.erase(tokens.begin()+i);
                    tokens.erase(tokens.begin()+j);

                    // Handle what was between the parens
                    Arithmetic::Reduce(tokens, j, i-1);

                    // probably more efficient way of doing this, but this is foolproof...
                    end = static_cast<int>(tokens.size());
                    i = start;
                    break;
                }
                // TODO return error -- didn't find matching open paren
            }
        }
    }

    // PEMDAS: MD
    // search whole token vector for * & /
    for (int i = start; i < end; i++) {
        if (tokens[i] == "*" || tokens[i] == "/") {
            if (tokens[i] == "*") {
                // get operands to left and right
                auto left = std::stod(tokens[i-1]);
                auto right = std::stod(tokens[i+1]);

                // do *
                auto result = left * right;

                // replace operands & operator with result in token vector
                tokens.erase(tokens.begin()+i-1, tokens.begin()+i+2);
                tokens.insert(tokens.begin()+i-1, std::to_string(result));
                end -= 2;
                i -= 1;
            } else {
                // get operands to left and right
                auto left = std::stod(tokens[i-1]);
                auto right = std::stod(tokens[i+1]);

                // do /
                auto result = left / right;

                // replace operands & operator with result in token vector
                tokens.erase(tokens.begin()+i-1, tokens.begin()+i+2);
                tokens.insert(tokens.begin()+i-1, std::to_string(result));
                end -= 2;
                i -= 1;
            }
        }
    }

    // PEMDAS: AS
    // search whole token vector for + & -
    for (int i = start; i < end; i++) {
        if (tokens[i] == "+" || tokens[i] == "-") {
            if (tokens[i] == "+") {
                // get operands to left and right
                auto left = std::stod(tokens[i-1]);
                auto right = std::stod(tokens[i+1]);

                // do +
                auto result = left + right;

                // replace operands & operator with result in token vector
                tokens.erase(tokens.begin()+i-1, tokens.begin()+i+2);
                tokens.insert(tokens.begin()+i-1, std::to_string(result));
                end -= 2;
                i -= 1;
            } else {
                // get operands to left and right
                auto left = std::stod(tokens[i-1]);
                auto right = std::stod(tokens[i+1]);

                // do -
                auto result = left - right;

                // replace operands & operator with result in token vector
                tokens.erase(tokens.begin()+i-1, tokens.begin()+i+2);
                tokens.insert(tokens.begin()+i-1, std::to_string(result));
                end -= 2;
                i -= 1;
            }
        }
    }
}