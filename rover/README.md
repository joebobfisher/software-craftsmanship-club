DISTek Software Craftsmanship Club 02 - Simple Mars Rover
=========================================================
Coding Kata: [Simple Mars Rover Kata on Katalyst](https://katalyst.codurance.com/simple-mars-rover)  
(Harder Version: [Full Mars Rover Kata on Katalyst](https://katalyst.codurance.com/mars-rover))

Goals for this Kata
-------------------
_Clean Code_ Chapter 2: "Meaningful Names"
* Use intention-revealing names
* Avoid disinformation
* Make meaningful distinctions
* Use pronounceable names
* Use searchable names
* Avoid encodings
  * Hungarian notation
  * Member prefixes
  * Interfaces and implementations
* Avoid mental mapping
* Class names - nouns or noun phrases (avoid Manager, Processor, Data, Info, etc.)
* Method names - verb or verb phrases; accesssors, mutators, predicates should start with "get", "set", or "is"
  * Use static factory methods instead of merely using overloaded constructors, e.g.,
    ```c++
    Complex fulcrumPoint = Complex.FromRealNumber(23.0);
    ```
    as opposed to
    ```c++
    Complex fulcrumPoint = new Complex(23.0);
    ```
* Don't be cute
* Pick one word per concept
* Don't pun
* Use solution domain names - use of CS terms is usually appropriate
* Use problem domain names - when no CS terms helpful, pick terms domain experts understand
* Add meaningful context
* Don't add gratuitous context

Instructions
------------
A squad of robotic rovers are to be landed by NASA on a plateau on Mars.

This plateau, which is curiously rectangular, must be navigated by the rovers so that their onboard cameras can get a complete view of the surrounding terrain to send back to Earth.

Your task is to develop an API that moves the rovers around on the plateau.

In this API, the plateau is represented as a 10x10 grid, and a rover has state consisting of two parts:

* its position on the grid (represented by an X,Y coordinate pair)
* the compass direction it's facing (represented by a letter, one of `N`, `S`, `E`, `W`)

Input
-----
The input to the program is a string of one-character move commands:

* `L` and `R` rotate the direction the rover is facing
* `M` moves the rover one grid square forward in the direction it is currently facing

If a rover reaches the end of the plateau, it wraps around the end of the grid.

Output
------
The program's output is the final position of the rover after all the move commands have been executed. The position is represented as a coordinate pair and a direction, joined by colons to form a string. For example: a rover whose position is `2:3:W` is at square (2,3), facing west.

Examples
--------
* given an input `MMRMMLM` then the output should be `2:3:N`
* given an input `MMMMMMMMMM` gives output `0:0:N` (due to wrap-around)

Interface
---------
There are no restrictions on the design of the public interface.

A public interface to the API could look something like this:

```c++
public class MarsRover 
{
    public string Execute(string command);
}
```

Rules
-----
* The rover receives a char array of commands e.g. `RMMLM` and returns the finishing point after the moves e.g. `2:1:N`
* The rover wraps around if it reaches the end of the grid.
