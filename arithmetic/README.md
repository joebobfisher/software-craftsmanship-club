DISTek Software Craftsmanship Club 04 - Arithmetics
===================================================
Kata: [Arithmetics Kata on Katalyst](https://katalyst.codurance.com/arithmetics)

_Clean Code_ Chapter 4: Comments
--------------------------------
* Comments do not make up for bad code
* Explain yourself in code
* Good comments
  * Legal comments
  * Informative comments
  * Explanation of intent
  * Clarification
  * Warning of consequences
  * TODO comments
  * Amplification
  * Javadocs in public APIs
* Bad comments
  * Mumbling
  * Redundant comments
  * Misleading comments
  * Mandated comments
  * Journal comments
  * Noise comments
  * Scary noise
  * Don't use a comment when you can use a function or a variable
  * Position markers
  * Closing brace comments
  * Attributions and bylines
  * Commented-out code
  * HTML comments
  * Nonlocal information
  * Too much information
  * Inobvious connection
  * Function headers
  * Javadocs in nonpublic code

### Don't forget what you've already learned!
* [_Clean Code_ Chapter 3: "Functions"](../alphabet-cipher/README.md)
* [_Clean Code_ Chapter 2: "Meaningful Names"](../rover/README.md)

Arithmetics
-----------
### Story
Durance got tired of learning spells and sorting bags and decided to invest in papicoins, the newest cryptocurrency (we don't judge). In order to do so, he has to learn how to read the records of transactions. Durance promised us a percentage of the profits so let's help!

### Description
Create an application that helps Durance read the transactions of the cryptocurrency.
The transactions are arithmetic operations wrapped by parentheses. In case a record is invalid, we should let Durance know with an "Invalid record" error message.

### Rules
* All of the operations are wrapped in parentheses
* There is an even number of parentheses
* Spaces can be considered as separators (to help identify negative numbers)
* If only parenthesis are provided, return 0 (consider the other rules)
* Operations should follow PEMDAS precedence rules (Parentheses, Exponents, Multiplication/Division, Addition/Subtraction)

### Examples
```
( 1 + ( ( 2 + 3 ) * (4 * 5) ) ) -> 101
( 5 * ( 4 * ( 3 * ( 2 * ( 1 * 9 ) / 8 - 7 ) + 6 ) ) ) -> -165
((()())) -> 0
3 + ( 2 * 1 ) -> Invalid record error
```

Random New Thing I Learned
--------------------------
```
clang-tidy -checks=-*,readability-*,cppcoreguidelines-*,cert-*,bugprone-*,clang-analyzer-*,modernize-*,performance-*,portability-* -dump-config > ../.clang-tidy
```
The above sets up clang-tidy settings for your particular project. Check out the available checks at [clang-tidy's site](clang.llvm.org/extra/clang-tidy).