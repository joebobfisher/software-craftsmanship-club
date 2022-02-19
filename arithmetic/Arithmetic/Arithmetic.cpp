#include "Arithmetic.h"

auto Arithmetic::Do(const std::string& expression) -> int {
    //std::vector<std::string> v {"(","(","1","+","2",")","*","(","3","*","4",")",")"};
    //std::vector<std::string> v {"(", "1", "+", "(", "(", "2", "+", "3", ")", "*", "(","4", "*", "5",")", ")", ")"};
    std::vector<std::string> v {"(", "5", "*", "(", "4", "*", "(", "3", "*", "(", "2", "*", "(", "1", "*", "9", ")", "/", "8", "-", "7", ")", "+", "6", ")", ")", ")"};
    Calculate(v, 0, v.size());

    return stoi(v[0]);
}

void Arithmetic::Calculate(std::vector<std::string>& tokens, int start, int end) { // NOLINT(misc-no-recursion)
    // PEMDAS: P
    // take care of parentheses
    for (int i = start; i < end; i++) {
        if (tokens[i] == ")") {
            for (int j = i-1; j >= start; j--) {
                if (tokens[j] == "(") {
                    Arithmetic::Calculate(tokens, j+1, i);
                    tokens.erase(tokens.begin()+j+2);
                    tokens.erase( tokens.begin()+j);
                    end -= i - j;
                    i = j;
                    break;
                }
            }
        }
    }

    // PEMDAS: MD
    // search whole token vector for * & /
    for (int i = start; i < end; i++) {
        if (tokens[i] == "*" || tokens[i] == "/") {
            if (tokens[i] == "*") {
                // get operands to left and right
                auto left = stoi(tokens[i-1]);
                auto right = stoi(tokens[i+1]);

                // do *
                auto result = left * right;

                // replace operands & operator with result in token vector
                tokens.erase(tokens.begin()+i-1, tokens.begin()+i+2);
                tokens.insert(tokens.begin()+i-1, std::to_string(result));
                end -= 2;
                i -= 1;
            } else {
                // get operands to left and right
                auto left = stoi(tokens[i-1]);
                auto right = stoi(tokens[i+1]);

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
                auto left = stoi(tokens[i-1]);
                auto right = stoi(tokens[i+1]);

                // do +
                auto result = left + right;

                // replace operands & operator with result in token vector
                tokens.erase(tokens.begin()+i-1, tokens.begin()+i+2);
                tokens.insert(tokens.begin()+i-1, std::to_string(result));
                end -= 2;
                i -= 1;
            } else {
                // get operands to left and right
                auto left = stoi(tokens[i-1]);
                auto right = stoi(tokens[i+1]);

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