DISTek Software Craftsmanship Club 13 - Count k-Primes Concurrently
===================================================================
Coding Kata: [k-Primes](https://codewars.com/kata/5726f813c8dcebf5ed000a6b)

_Clean Code_ Chapter 13: Concurrency
------------------------------------
* Why concurrency?
  * Myths and misconceptions
* Challenges
* Concurrency defense principles
  * Single Responsibility Principle
  * Corollary: limit the scope of data
  * Corollary: use copies of data
  * Corollary: threads should be as independent as possible
* Know your library
  * Thread-safe collections
* Know your execution models
  * Producer-consumer
  * Readers-writers
  * Dining philosophers
* Beware dependencies between synchronized methods
* Keep synchronized sections small
* Writing correct shut-down code is hard
* Testing threaded code
  * Test spurious failures as candidate threading issues
  * Get your non-threaded code working first
  * Make your threaded code pluggable
  * Make your threaded code tunable
  * Run with more threads than processors
  * Run on different platforms
  * Instrument your code to try and force failures
  * Hand-coded
  * Automated

### Don't forget what you've already learned!
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

Counting k-Primes Concurrently
------------------------------
Make the kata code from the last chapter ([Chapter 12: Counting k-Primes](../kprimes)) run concurrently, to find all the
k-Primes (and count them) more quickly!
