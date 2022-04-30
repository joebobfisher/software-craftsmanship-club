DISTek Software Craftsmanship Club 14 - Command-Line Argument Parser
====================================================================
Coding Kata: this kata!

_Clean Code_ Chapter 14: Successive Refinement
----------------------------------------------
* Args implementation
  * How did I do this?
* Args: the rough draft
  * So I stopped
  * On incrementalism
* String arguments

### Don't forget what you've already learned!
* [_Clean Code_ Chapter 13: "Concurrency"](../kprimes-concurrent/readme.md)
* [_Clean Code_ Chapter 12: "Emergence"](../kprimes/readme.md)
* [_Clean Code_ Chapter 11: "Systems"](../rover-factory/readme.md)
* [_Clean Code_ Chapter 10: "Classes"](../rover-refactor/readme.md)
* [_Clean Code_ Chapter 9: "Unit Tests"](../rover-redux/README.md)
* [_Clean Code_ Chapter 8: "Boundaries"](../password-encrypt/README.md)
* [_Clean Code_ Chapter 7: "Error Handling"](../password/README.md)
* [_Clean Code_ Chapter 6: "Objects & Data Structures"](../bowling/README.md)
* [_Clean Code_ Chapter 5: "Formatting"](../tiny-maze/README.md)
* [_Clean Code_ Chapter 4: "Comments"](../arithmetic/README.md)
* [_Clean Code_ Chapter 3: "Functions"](../alphabet-cipher/README.md)
* [_Clean Code_ Chapter 2: "Meaningful Names"](../rover/README.md)

Command-Line Argument Parser
----------------------------
Implement a parser of command-line arguments, similar to the parser that is discussed in the chapter.

The interface to the argument parser should ___roughly___ look like this below. Note that you should modify the
interface not just for your language, but based on your implementation's needs (i.e., this is just a guideline).

```java
public interface ArgParser {
    public ArgParser(String[] args);
    public int Cardinality();
    public String Usage();
    public boolean GetBoolean(char arg);
    public String GetString(char arg);
    public int GetInt(char arg);
    public double GetDouble(char arg);
    public boolean has(char arg);
};
```

