#include "Arithmetic.h"

auto Arithmetic::Do(const std::string& expression) -> int {
    // parse expression string
    //      (recursion if parentheses encountered?)
    // should error out if terms encountered before parentheses...
    // default (if there's nothing to do) to 0

    // General design of solution (I think):
    // Grammar roughly follows the rules (not counting whitespace):
    //      Expr: ( Expr|Symb Op Expr|Symb ) | ()
    //      Op: + | - | * | / | <null>
    //      Symb: -?[0-9]+ | <null>
    // Use recursion to evaluate Expr
    // (since recursion is needed, we can't parse with regex!)
    // 1. Tokenize input string into vector of strings
    // 2. Token state machine: ExpectOpenParen -> ExpectSymbOrOpenParens -> ExpectOp    ExpectCloseParen
    //                                            |__^   |  ^_________________|  ^_________|   ^  |__^
    //                                                   |_____________________________________|

    return 0;
}