DISTek Software Craftsmanship Club 08 - Password Encryption
===========================================================
Kata: [This page!](README.md)

_Clean Code_ Chapter 8: Boundaries
----------------------------------
* Using third-party code
  * Encapsulate extra functionality you don't need/want in a class
    * E.g., "Sensors" HashMap
* Exploring & learning boundaries
  * Use "learning tests" to discover boundaries in 3rd-party code
  * E.g., learning `log4j`
* Learning tests are better than free
  * We have to learn API anyway, and now we have regression tests for that library!
* Using code that does not yet exist
  * Define your own interfaces and stub out implementations for later
* Don't let too much of your codebase rely on 3rd-party stuff
  * Then a lot has to change if those libraries change!
  * Encapsulate into a thing _you_ control.

### Don't forget what you've already learned!
* [_Clean Code_ Chapter 7: "Error Handling"](../password/README.md)
* [_Clean Code_ Chapter 6: "Objects & Data Structures"](../bowling/README.md)
* [_Clean Code_ Chapter 5: "Formatting"](../tiny-maze/README.md)
* [_Clean Code_ Chapter 4: "Comments"](../arithmetic/README.md)
* [_Clean Code_ Chapter 3: "Functions"](../alphabet-cipher/README.md)
* [_Clean Code_ Chapter 2: "Meaningful Names"](../rover/README.md)

Password Encryption
-------------------
This kata is a continuation of [the Password kata we did in the last chapter](https://github.com/joebobfisher/software-craftsmanship-club/tree/main/password).

Extend the code from the last kata (or develop from scratch if you're so inclined) to encrypt the username & password
when they're at rest. Additionally, create a method that will take a [plaintext](https://www.merriam-webster.com/dictionary/plaintext)
username & password combination, and check them against the usernames & passwords already entered.

This kata is written to use a 3rd-party encryption library to do the encryption & decryption. With that said, if it
becomes too big of an issue to incorporate (or even find) this library, the reader is free to implement their own, even
if it doesn't do actual encryption. The overall goal here is to get used to thinking about boundaries, and incorporate
the principles from the book -- not to get stuck on 3rd-party library details! 

### APIs
Your solution should have the following APIs. These are defined as C++ functions here but your implementation should
vary based on your language of choice (and the name you like).

Also feel free to tweak the parameters or return values to suit your code (e.g., passing in a monadic `PasswordObject`
instead of dyadic `username` and `password` strings!).

#### SetPassword()
```c++
void SetPassword(string username, string password)
```

This API should allow the user set the given user's password to the given password string. These strings will both be
given in plaintext, but after the call returns the username and
password should both be encrypted in memory.

Note we don't need a return value here -- feel free to throw an exception if something goes wrong (so if we return we
can assume everything worked OK).

#### Login()
```c++
bool Login(string usernameAttempt, string passwordAttempt)
```

This API should take another plaintext username + password combination, and search the list of already-entered usernames
& passwords for a matching set. If it finds one, it returns `true`; else it returns `false`.

(Note that this means you'll need to decrypt the already-stored usernames & passwords in order to compare them -- or,
alternatively, just encrypt these attempts in the same way and do a straight string compare, I guess 😄 -- whatever you
would like to do!)

### Ideas for cryptographic libraries to investigate
There are way more out there, but here are a couple of ideas to get started.

#### Python
* [Fernet library](https://cryptography.io/en/latest/fernet/)

### C++
* [Botan](https://github.com/randombit/botan)
* [Crypto++](https://www.cryptopp.com/)
* [libgcrypt](https://gnupg.org/related_software/libgcrypt/)

### Bonus Points If
* You write the username and password pairs to a file, encrypted.
* You read the encrypted username+password file at startup, to give the usernames & passwords persistence across runs. 

If you have any questions or concerns!
--------------------------------------
Please get ahold of us on [the Software Craftsmanship Club Team in Teams](https://teams.microsoft.com/l/channel/19%3aUZNW-WALpAPHWCpwhbONo9X4sA5hXyqSEbNfdD4zBe41%40thread.tacv2/General?groupId=73c1344e-5c84-4df4-8767-2d0c75c31b6f&tenantId=dc73057b-7566-4116-ac70-0ceba1935ca7)!
Really don't want anybody to spin their wheels on either the lesson text or the kata, so reach out if you are stuck (or
if something just doesn't make sense)!
