DISTek Software Craftsmanship Club 05 - Tiny Maze
=================================================
Kata: [tiny-maze on wonderland-clojure-katas](https://github.com/gigasquid/wonderland-clojure-katas/tree/master/tiny-maze)

_Clean Code_ Chapter 5: Formatting
----------------------------------
* The purpose of formatting
* Vertical formatting
  * The newspaper metaphor
    * Detail should increase as you move downward in the code
  * Vertical openness between concepts
  * Vertical density
  * Vertical distance
    * Variable declarations
      * Local variables should usually appear at the top of each function
    * Instance variables
      * Should be declared at the top of the class (Java)
      * Should be declared at the bottom of the class (C++)
      * Just follow a convention that won't surprise others!
    * Dependent functions
    * Conceptual affinity
  * Vertical ordering
* Horizontal formatting
  * Horizontal openness and density
  * Horizontal alignment
  * Indentation
  * Dummy scopes
* Team rules
  * Create and obey rules as a team!

### Don't forget what you've already learned!
* [_Clean Code_ Chapter 4: "Comments"](../arithmetics/README.md)
* [_Clean Code_ Chapter 3: "Functions"](../alphabet-cipher/README.md)
* [_Clean Code_ Chapter 2: "Meaningful Names"](../rover/README.md)

tiny-maze
---------
This is a tiny maze solver.

A maze is represented by a matrix:
```
[ [ S  0  1 ]
  [ 1  0  1 ]
  [ 1  0  E ] ]
```
* `S` : start of the maze
* `E` : end of the maze
* `1` : This is a wall that you cannot pass through
* `0` : A free space that you can move through.

The goal is the get to the end of the maze. A solved maze will have a `x` in the start, the path, and the end of the maze, like this.
```
[ [ x  x  1 ]
  [ 1  x  1 ]
  [ 1  x  x ] ]
```
### Constraints
Here are some further constraints you can count on:
* The maze will always be solvable
* `S` will always be at the top left (`[0][0]`)
* `E` will always be at the bottom right (`[<size-of-array>][<size-of-array>]`)

### Examples
Here is a more complex example:
```
[ [ S  0  0  0  0 ]
  [ 1  1  1  1  0 ]
  [ 0  0  0  1  0 ]
  [ 0  1  0  1  0 ]
  [ 0  1  0  0  0 ]
  [ 0  1  1  1  1 ]
  [ 0  1  0  0  0 ]
  [ 0  1  1  1  1 ]
  [ 0  0  0  0  1 ]
  [ 0  1  0  1  1 ]
  [ 1  1  0  0  E ] ]
```
Note that not all `0`s are reachable (or even part of the solution):
```
[ [ x  x  x  x  x ]
  [ 1  1  1  1  x ]
  [ x  x  x  1  x ]
  [ x  1  x  1  x ]
  [ x  1  x  x  x ]
  [ x  1  1  1  1 ]
  [ x  1  0  0  0 ]
  [ x  1  1  1  1 ]
  [ x  x  x  0  1 ]
  [ 0  1  x  1  1 ]
  [ 1  1  x  x  x ] ]
```

