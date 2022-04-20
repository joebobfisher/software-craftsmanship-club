DISTek Software Craftsmanship Club 09 - Rover Redux
===================================================
Coding Kata: [Simple Mars Rover Kata on Katalyst](https://katalyst.codurance.com/simple-mars-rover)

_Clean Code_ Chapter 9: Unit Tests
----------------------------------
* Three Laws of TDD
  * You may not write production code until you have written a failing unit test.
  * You may not write more of a unit test than is sufficient to fail (and not compiling is failing).
  * You may not write more production code than is sufficient to pass the currently failing test.
* Keeping tests clean
  * Dirty tests worse than no tests
  * Test code is just as important as production code!
    * Tests enable the -ilities
      * Flexibility, maintainability, reusability
      * Without tests every change is a possible bug
* Clean tests
  * Readability is what makes tests clean!
  * "Build-Operate-Check" pattern
  * Domain-specific testing language
  * A dual standard
    * Test code has different standards than production code, but _it does have standards!_
* One assert per test
  * Single concept per test
    * Not necessarily one assert, strictly speaking, but one "thing" that is being tested
      (even if multiple asserts are necessary)
* F.I.R.S.T.
  * Fast
  * Independent
  * Repeatable
  * Self-validating (either pass or fail)
  * Timely (written _just before_ code to make them pass)

### Don't forget what you've already learned!
* [_Clean Code_ Chapter 8: "Boundaries"](../password-encrypt/README.md)
* [_Clean Code_ Chapter 7: "Error Handling"](../password/README.md)
* [_Clean Code_ Chapter 6: "Objects & Data Structures"](../bowling/README.md)
* [_Clean Code_ Chapter 5: "Formatting"](../tiny-maze/README.md)
* [_Clean Code_ Chapter 4: "Comments"](../arithmetic/README.md)
* [_Clean Code_ Chapter 3: "Functions"](../alphabet-cipher/README.md)
* [_Clean Code_ Chapter 2: "Meaningful Names"](../rover/README.md)

Rover Redux
-----------
This is a rewrite of the [`rover` project from Chapter 2](../rover), but with unit testing.
Below are the instructions for reference.

### Instructions
A squad of robotic rovers are to be landed by NASA on a plateau on Mars.

This plateau, which is curiously rectangular, must be navigated by the rovers so that their onboard cameras can get a complete view of the surrounding terrain to send back to Earth.

Your task is to develop an API that moves the rovers around on the plateau.

In this API, the plateau is represented as a 10x10 grid, and a rover has state consisting of two parts:

* its position on the grid (represented by an X,Y coordinate pair)
* the compass direction it's facing (represented by a letter, one of `N`, `S`, `E`, `W`)

### Input
The input to the program is a string of one-character move commands:

* `L` and `R` rotate the direction the rover is facing
* `M` moves the rover one grid square forward in the direction it is currently facing

If a rover reaches the end of the plateau, it wraps around the end of the grid.

### Output
The program's output is the final position of the rover after all the move commands have been executed. The position is represented as a coordinate pair and a direction, joined by colons to form a string. For example: a rover whose position is `2:3:W` is at square (2,3), facing west.

### Examples
* given an input `MMRMMLM` then the output should be `2:3:N`
* given an input `MMMMMMMMMM` gives output `0:0:N` (due to wrap-around)

### Interface
There are no restrictions on the design of the public interface.

A public interface to the API could look something like this:

```c++
public class MarsRover 
{
    public string Execute(string command);
}
```

### Rules
* The rover receives a char array of commands e.g. `RMMLM` and returns the finishing point after the moves e.g. `2:1:N`
* The rover wraps around if it reaches the end of the grid.


