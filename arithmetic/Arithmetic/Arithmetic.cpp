#include "Arithmetic.h"

auto Arithmetic::Do(const std::string& expression) -> int {
    // parse expression string
    //      (recursion if parentheses encountered?)
    // should error out if terms encountered before parentheses...
    // default (if there's nothing to do) to 0

    // General design of solution (I think):
    //      * Every open paren has to be matched with a close paren _sometime_.
    //          - Any time we encounter an open paren, we call the function recursively
    //          - Any time we encounter a closed paren, we return
    //      * In the function:
    //          - Current result is passed in
    //          - If input == '(', recurse
    //          - If input == ')', return result
    //          - If input == Num, push Num and expect Op next
    //          - If input == Op and Op is expected, save Op and expect Num next
    //          - If input == Num and Num expected, do math
    //      * Operations have to be surrounded by numbers or parens
    //      *
    // Grammar roughly follows the rules (not counting whitespace):
    //      Num -> -?[0-9]+
    //      Op -> [+-*/]
    //      Expr -> ()
    //      Expr -> (Num)
    //      Expr -> (Num Op Num)
    //      Expr -> (Expr Op Num)
    //      Expr -> (Num Op Expr)
    //      Expr ->
    //      Expr: ( Expr|Symb Op Expr|Symb ) | ()
    //      Op   -> [+-*/]
    //      Num  -> -?[0-9]+
    //      Expr -> (Expr|Num Op Expr|Num )
    // Use recursion to evaluate Expr
    // (since recursion is needed, we can't parse with regex!)
    // 1. Tokenize input string into vector of strings
    // 2. Token state machine: ExpectOpenParen -> ExpectSymbOrOpenParens -> ExpectOp    ExpectCloseParen
    //                                            |__^   |  ^_________________|  ^_________|   ^  |__^
    //                                                   |_____________________________________|

//    int result = 0;
//
//    // PEMDAS: P
//    auto symbolLocation = expression.find('(');
//    if (symbolLocation != std::string::npos) {
//        result = Do(expression.substr(symbolLocation));
//    }
//
//    // PEMDAS: MD
//    do {
//        symbolLocation = expression.find('*');
//        auto secondSymbolLocation = expression.find('/');
//
//        if (symbolLocation == std::string::npos && secondSymbolLocation == std::string::npos) {
//            break;
//        }
//
//        if (symbolLocation < secondSymbolLocation) {
//            // do M
//            // find operands on either side
//            auto leftOperand = Arithmetic::GetLeftOperand(symbolLocation);
//            auto rightOperand = Arithmetic::GetRightOperand(symbolLocation);
//            // do math
//            int result = leftOperand * rightOperand;
//            // replace operands and operator with result
//        } else {
//            // do D
//            // find operands on either side
//            auto leftOperand = Arithmetic::GetLeftOperand(secondSymbolLocation);
//            auto rightOperand = Arithmetic::GetRightOperand(secondSymbolLocation);
//            // do math
//            int result = leftOperand / rightOperand;
//            // replace operands and operator with result
//        }
//    }

    std::vector<std::string> v {"(","(","1","+","2",")","*","(","3","*","4",")",")"};
    Calculate(v, 0, v.size());

    return 0;
}

int Arithmetic::GetLeftOperand(unsigned long long int location) {
    return 0;
}

int Arithmetic::GetRightOperand(unsigned long long int location) {
    return 0;
}

auto Arithmetic::Calculate(std::vector<std::string>& tokens, int start, int end) -> int { // NOLINT(misc-no-recursion)
    // PEMDAS: P
    // take care of parentheses
    for (int i = start; i < end; i++) {
        if (tokens[i] == ")") {
            for (int j = i-1; j >= start; j--) {
                if (tokens[j] == "(") {
                    auto result = Arithmetic::Calculate(tokens, j+1, i);
                    tokens.erase(tokens.begin()+j, tokens.begin()+i+1);
                    tokens.insert(tokens.begin()+i, std::to_string(result));
                    end -= i - j;
                    i = j;
                    break;
                }
            }
        }
    }

    // PEMDAS: MD
    // search whole token vector for * & /
//    for (auto token : tokens) {
//        if (token == "*" || token == "/") {
//            if (token == "*") {
//                // get operands to left and right
//                // do *
//                // replace operands & operator with result in token vector
//            } else {
//                // get operands to left and right
//                // do /
//                // replace operands & operator with result in token vector
//            }
//        }
//    }

    // PEMDAS: AS
    // search whole token vector for + & -
//    for (auto token : tokens) {
//        if (token == "+" || token == "-") {
//            if (token == "+") {
//                // get operands to left and right
//                // do +
//                // replace operands & operator with result in token vector
//            } else {
//                // get operands to left and right
//                // do -
//                // replace operands & operator with result in token vector
//            }
//        }
//    }

    // PEMDAS: P
    // There should only be a single closing paren left in token vector, along with answer
    // Do error checking and return result
    // TODO need to remove rest of stuff from token vector? Need to return overall token vector?


    return 0;
}