#include <iostream>

int main(int argc, char ** argv) {

    // get arguments: options for secret phrase, message
    //      (use std::find() like here: https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
    // sanitize and normalize secret phrase & message (remove spaces, lower case)
    // repeat letters of secret phrase over and over again until same size as message
    //      (handle case where message is smaller than secret phrase)
    // for i in message.size:
    //      schar = secret_phrase[i]
    //      mchar = message[i]
    //      encrypted_message += lookup[mchar][schar]
    // return encrypted_message
    // TODO add decrypting as well

    std::cout << "Hello, World!" << std::endl;

    return 0;
}
