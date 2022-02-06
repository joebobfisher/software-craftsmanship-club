DISTek Software Craftsmanship Club 03 - Alphabet Cipher
=======================================================
Kata: [Alphabet Cipher on GitHub](https://github.com/mathias-brandewinder/wonderland-fsharp-katas/blob/master/wonderland-fsharp-katas/alphabet-cipher.md)

_Clean Code_ Chapter 3: Functions
---------------------------------
* Small!
  * Blocks and Indenting
    * Should be one line long
    * Indent level should not be greater than one or two.
* Do one thing
  * Functions that do one thing can't be divided into sections!
* One level of abstraction per function!
  * Reading code from top to bottom: the Stepdown Rule
    * Follow up a function with the functions in the next level of abstraction
* Switch statements
  * Encapsulate switch statements in Abstract Factories
    * Return the right polymorphic type that calls the right method
* Use descriptive names
  * Be consistent in your names!
* Function arguments
  * Priority of preference
    * Ideal: zero arguments ("niladic" function)
    * Next: one argument ("monadic" function)
    * Next: two arguments ("dyadic" function)
    * Three arguments ("triadic") or more should be avoided!
  * Common monadic forms
    * Return value
      * Asking a question about an argument and returning the answer
      * Operating on the argument and returning a result
    * No return value
      * Events: use input to alter state of system
    * Avoid monadic functions that don't follow these forms
  * Don't use flag arguments!
  * Dyadic functions
    * Sometimes appropriate, but not as often as you think!
      * E.g., cartesian point coordinates == appropriate
        * However, better would be a single object with two parts!
  * Again, triads are bad!
  * Argument objects
    * If you think you need more than 2 or 3, some may need to be wrapped in a class
    ```c++
    Circle makeCircle(double x, double y, double radius); // ok...
    Circle makeCircle(Point center, double radius); // Better!
    ```
  * Argument Lists
    * Functions that take multiple args that are the same sort of thing are often really monads or dyads.
    ```c++
    // this is actually dyadic!
    String.format("%s worked %.2f hours.", name, hours);
    public String format(String format, Object... args)     // equivalent definition
    ```
    ```c++
    void monad(Integer... args);
    void dyad(String name, Integer... args);
    void triad(String name, int count, Integer... args);
    ```
  * Verbs and keywords
    * Consider `writeField(name)` instead of `write(name)`.
    * Consider `assertExpectedEqualsActual(expected, actual)` instead of `assertEquals(expected, actual)`.
* Have no side effects
  * Output arguments
    * Avoid making readers do a double-take!
    * `report.appendFooter()` is better than `appendFooter(report)`.
* Command-Query separation
  * Functions should either do something or answer something, **not both**.
* Prefer exceptions to returning error codes!
  * Extract try/catch blocks
  * Error handling is One Thing
    * If `try` is in your function, it should be first thing and `catch/finally` block should be last!
* Don't Repeat Yourself (DRY)
* Structured Programming
  * Dijkstra: every block should have one entry & one exit!
  * This rule serves little benefit when functions are small though
    * Still no `goto`s tho.
* Start with "bad" functions, work your way towards "good"!

### Don't forget what you've already learned!
* [_Clean Code_ Chapter 2: "Meaningful Names"](../rover/README.md)

Alphabet Cipher
---------------
Lewis Carroll published a cipher known as The Alphabet Cipher.

This Alphabet Cipher involves alphabet substitution using a keyword.

First you must make a substitution chart like this, where each row of the alphabet is rotated by one as each letter goes down the chart.

```
  ABCDEFGHIJKLMNOPQRSTUVWXYZ
A abcdefghijklmnopqrstuvwxyz
B bcdefghijklmnopqrstuvwxyza
C cdefghijklmnopqrstuvwxyzab
D defghijklmnopqrstuvwxyzabc
E efghijklmnopqrstuvwxyzabcd
F fghijklmnopqrstuvwxyzabcde
G ghijklmnopqrstuvwxyzabcdef
H hijklmnopqrstuvwxyzabcdefg
I ijklmnopqrstuvwxyzabcdefgh
J jklmnopqrstuvwxyzabcdefghi
K klmnopqrstuvwxyzabcdefghij
L lmnopqrstuvwxyzabcdefghijk
M mnopqrstuvwxyzabcdefghijkl
N nopqrstuvwxyzabcdefghijklm
O opqrstuvwxyzabcdefghijklmn
P pqrstuvwxyzabcdefghijklmno
Q qrstuvwxyzabcdefghijklmnop
R rstuvwxyzabcdefghijklmnopq
S stuvwxyzabcdefghijklmnopqr
T tuvwxyzabcdefghijklmnopqrs
U uvwxyzabcdefghijklmnopqrst
V vwxyzabcdefghijklmnopqrstu
W wxyzabcdefghijklmnopqrstuv
X xyzabcdefghijklmnopqrstuvw
Y yzabcdefghijklmnopqrstuvwx
Z zabcdefghijklmnopqrstuvwxy
```

Both parties need to decide on a secret keyword. This keyword is not written down anywhere, but memorized.

To encode the message, first write down the message.

```
meetmebythetree
```

Then, write the keyword, (which in this case is scones), repeated as many times as necessary.

```
sconessconessco
meetmebythetree
```

Now you can look up the column S in the table and follow it down until it meets the M row. The value at the intersection is the letter e. All the letters would be thus encoded.

```
sconessconessco
meetmebythetree
egsgqwtahuiljgs
```

The encoded message is now `egsgqwtahuiljgs`

To decode, the person would use the secret keyword and do the opposite.
