#include <iostream>
#include <boost/program_options.hpp>
#include <map>

namespace opt = boost::program_options;

int main(int argc, char ** argv) {

    // get arguments: options for secret phrase, message
    //      use boost::program_options
    //      --help
    //      --encrypt [secretPhrase]
    //      usage: alphabet_cipher --encrypt myphrase mymessage
    //             alphabet_cipher --decrypt myphrase mymessage
    //             alphabet_cipher <anything-else> (prints same as --help)
    // sanitize and normalize secret phrase & message (remove spaces, lower case)
    // (don't need to chop/grow secret_phrase if we just mod while we look up each character...
    // for i in message.size:
    //      schar = secret_phrase[i % secret_phrase.size]
    //      mchar = message[i]
    //      encrypted_message += lookup[mchar][schar]
    // return encrypted_message
    // TODO add decrypting as well

    opt::options_description description("Options");
    description.add_options()
        ("help,h", "Write help message")
        ("encrypt,e", opt::value<std::string>(), "Encrypt message with given keyword")
        ("decrypt,d", opt::value<std::string>(), "Decrypt message with given keyword")
        ("message,m", opt::value<std::string>(), "Actual message to encrypt");

    opt::variables_map options;
    opt::store(opt::parse_command_line(argc, argv, description), options);
    opt::notify(options);

    if (options.count("help")) {
        // TODO would be nice to have an example usage string
        std::cout << description << std::endl;
    } else if (options.count("encrypt") && options.count("message")) {
        // TODO --encrypt with no phrase just dies -- should have example usage string
        // TODO need <message> to be a "positional" option, so we can see it from program_options
        // TODO allow giving <message> from STDIN (but not phrase)

        auto keyword = options["encrypt"].as<std::string>();
        auto message = options["message"].as<std::string>();

        // strip out spaces & non-alphabetic characters
        // Careful! This solution only works for ASCII (https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c)
        keyword.erase(std::remove_if(keyword.begin(), keyword.end(), [](const char &c) { return !::isalpha(c); }),
                      keyword.end());
        message.erase(std::remove_if(message.begin(), message.end(), [](const char &c) { return !::isalpha(c); }),
                      message.end());

        // transform to lower case only
        std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
        std::transform(message.begin(), message.end(), message.begin(), ::tolower);

        // repeat letters of secret phrase over and over again until same size as message
        if (keyword.size() < message.size()) {
            for (unsigned int i = keyword.size(), j = 0; i < message.size(); i++, j++) {
                keyword += keyword[j % keyword.size()];
            }
        }

        std::map<char, std::map<char, char>> encryptionMap =
        {
            {'a', {{'a', 'a'}, {'b', 'b'}, {'c', 'c'}, {'d', 'd'}, {'e', 'e'}, {'f', 'f'}, {'g', 'g'}, {'h', 'h'}, {'i', 'i'}, {'j', 'j'}, {'k', 'k'}, {'l', 'l'}, {'m', 'm'}, {'n', 'n'}, {'o', 'o'}, {'p', 'p'}, {'q', 'q'}, {'r', 'r'}, {'s', 's'}, {'t', 't'}, {'u', 'u'}, {'v', 'v'}, {'w', 'w'}, {'x', 'x'}, {'y', 'y'}, {'z', 'z'}}},
            {'b', {{'a', 'b'}, {'b', 'c'}, {'c', 'd'}, {'d', 'e'}, {'e', 'f'}, {'f', 'g'}, {'g', 'h'}, {'h', 'i'}, {'i', 'j'}, {'j', 'k'}, {'k', 'l'}, {'l', 'm'}, {'m', 'n'}, {'n', 'o'}, {'o', 'p'}, {'p', 'q'}, {'q', 'r'}, {'r', 's'}, {'s', 't'}, {'t', 'u'}, {'u', 'v'}, {'v', 'w'}, {'w', 'x'}, {'x', 'y'}, {'y', 'z'}, {'z', 'a'}}},
            {'c', {{'a', 'c'}, {'b', 'd'}, {'c', 'e'}, {'d', 'f'}, {'e', 'g'}, {'f', 'h'}, {'g', 'i'}, {'h', 'j'}, {'i', 'k'}, {'j', 'l'}, {'k', 'm'}, {'l', 'n'}, {'m', 'o'}, {'n', 'p'}, {'o', 'q'}, {'p', 'r'}, {'q', 's'}, {'r', 't'}, {'s', 'u'}, {'t', 'v'}, {'u', 'w'}, {'v', 'x'}, {'w', 'y'}, {'x', 'z'}, {'y', 'a'}, {'z', 'b'}}},
            {'d', {{'a', 'd'}, {'b', 'e'}, {'c', 'f'}, {'d', 'g'}, {'e', 'h'}, {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, {'j', 'm'}, {'k', 'n'}, {'l', 'o'}, {'m', 'p'}, {'n', 'q'}, {'o', 'r'}, {'p', 's'}, {'q', 't'}, {'r', 'u'}, {'s', 'v'}, {'t', 'w'}, {'u', 'x'}, {'v', 'y'}, {'w', 'z'}, {'x', 'a'}, {'y', 'b'}, {'z', 'c'}}},
            {'e', {{'a', 'e'}, {'b', 'f'}, {'c', 'g'}, {'d', 'h'}, {'e', 'i'}, {'f', 'j'}, {'g', 'k'}, {'h', 'l'}, {'i', 'm'}, {'j', 'n'}, {'k', 'o'}, {'l', 'p'}, {'m', 'q'}, {'n', 'r'}, {'o', 's'}, {'p', 't'}, {'q', 'u'}, {'r', 'v'}, {'s', 'w'}, {'t', 'x'}, {'u', 'y'}, {'v', 'z'}, {'w', 'a'}, {'x', 'b'}, {'y', 'c'}, {'z', 'd'}}},
            {'f', {{'a', 'f'}, {'b', 'g'}, {'c', 'h'}, {'d', 'i'}, {'e', 'j'}, {'f', 'k'}, {'g', 'l'}, {'h', 'm'}, {'i', 'n'}, {'j', 'o'}, {'k', 'p'}, {'l', 'q'}, {'m', 'r'}, {'n', 's'}, {'o', 't'}, {'p', 'u'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'}, {'u', 'z'}, {'v', 'a'}, {'w', 'b'}, {'x', 'c'}, {'y', 'd'}, {'z', 'e'}}},
            {'g', {{'a', 'g'}, {'b', 'h'}, {'c', 'i'}, {'d', 'j'}, {'e', 'k'}, {'f', 'l'}, {'g', 'm'}, {'h', 'n'}, {'i', 'o'}, {'j', 'p'}, {'k', 'q'}, {'l', 'r'}, {'m', 's'}, {'n', 't'}, {'o', 'u'}, {'p', 'v'}, {'q', 'w'}, {'r', 'x'}, {'s', 'y'}, {'t', 'z'}, {'u', 'a'}, {'v', 'b'}, {'w', 'c'}, {'x', 'd'}, {'y', 'e'}, {'z', 'f'}}},
            {'h', {{'a', 'h'}, {'b', 'i'}, {'c', 'j'}, {'d', 'k'}, {'e', 'l'}, {'f', 'm'}, {'g', 'n'}, {'h', 'o'}, {'i', 'p'}, {'j', 'q'}, {'k', 'r'}, {'l', 's'}, {'m', 't'}, {'n', 'u'}, {'o', 'v'}, {'p', 'w'}, {'q', 'x'}, {'r', 'y'}, {'s', 'z'}, {'t', 'a'}, {'u', 'b'}, {'v', 'c'}, {'w', 'd'}, {'x', 'e'}, {'y', 'f'}, {'z', 'g'}}},
            {'i', {{'a', 'i'}, {'b', 'j'}, {'c', 'k'}, {'d', 'l'}, {'e', 'm'}, {'f', 'n'}, {'g', 'o'}, {'h', 'p'}, {'i', 'q'}, {'j', 'r'}, {'k', 's'}, {'l', 't'}, {'m', 'u'}, {'n', 'v'}, {'o', 'w'}, {'p', 'x'}, {'q', 'y'}, {'r', 'z'}, {'s', 'a'}, {'t', 'b'}, {'u', 'c'}, {'v', 'd'}, {'w', 'e'}, {'x', 'f'}, {'y', 'g'}, {'z', 'h'}}},
            {'j', {{'a', 'j'}, {'b', 'k'}, {'c', 'l'}, {'d', 'm'}, {'e', 'n'}, {'f', 'o'}, {'g', 'p'}, {'h', 'q'}, {'i', 'r'}, {'j', 's'}, {'k', 't'}, {'l', 'u'}, {'m', 'v'}, {'n', 'w'}, {'o', 'x'}, {'p', 'y'}, {'q', 'z'}, {'r', 'a'}, {'s', 'b'}, {'t', 'c'}, {'u', 'd'}, {'v', 'e'}, {'w', 'f'}, {'x', 'g'}, {'y', 'h'}, {'z', 'i'}}},
            {'k', {{'a', 'k'}, {'b', 'l'}, {'c', 'm'}, {'d', 'n'}, {'e', 'o'}, {'f', 'p'}, {'g', 'q'}, {'h', 'r'}, {'i', 's'}, {'j', 't'}, {'k', 'u'}, {'l', 'v'}, {'m', 'w'}, {'n', 'x'}, {'o', 'y'}, {'p', 'z'}, {'q', 'a'}, {'r', 'b'}, {'s', 'c'}, {'t', 'd'}, {'u', 'e'}, {'v', 'f'}, {'w', 'g'}, {'x', 'h'}, {'y', 'i'}, {'z', 'j'}}},
            {'l', {{'a', 'l'}, {'b', 'm'}, {'c', 'n'}, {'d', 'o'}, {'e', 'p'}, {'f', 'q'}, {'g', 'r'}, {'h', 's'}, {'i', 't'}, {'j', 'u'}, {'k', 'v'}, {'l', 'w'}, {'m', 'x'}, {'n', 'y'}, {'o', 'z'}, {'p', 'a'}, {'q', 'b'}, {'r', 'c'}, {'s', 'd'}, {'t', 'e'}, {'u', 'f'}, {'v', 'g'}, {'w', 'h'}, {'x', 'i'}, {'y', 'j'}, {'z', 'k'}}},
            {'m', {{'a', 'm'}, {'b', 'n'}, {'c', 'o'}, {'d', 'p'}, {'e', 'q'}, {'f', 'r'}, {'g', 's'}, {'h', 't'}, {'i', 'u'}, {'j', 'v'}, {'k', 'w'}, {'l', 'x'}, {'m', 'y'}, {'n', 'z'}, {'o', 'a'}, {'p', 'b'}, {'q', 'c'}, {'r', 'd'}, {'s', 'e'}, {'t', 'f'}, {'u', 'g'}, {'v', 'h'}, {'w', 'i'}, {'x', 'j'}, {'y', 'k'}, {'z', 'l'}}},
            {'n', {{'a', 'n'}, {'b', 'o'}, {'c', 'p'}, {'d', 'q'}, {'e', 'r'}, {'f', 's'}, {'g', 't'}, {'h', 'u'}, {'i', 'v'}, {'j', 'w'}, {'k', 'x'}, {'l', 'y'}, {'m', 'z'}, {'n', 'a'}, {'o', 'b'}, {'p', 'c'}, {'q', 'd'}, {'r', 'e'}, {'s', 'f'}, {'t', 'g'}, {'u', 'h'}, {'v', 'i'}, {'w', 'j'}, {'x', 'k'}, {'y', 'l'}, {'z', 'm'}}},
            {'o', {{'a', 'o'}, {'b', 'p'}, {'c', 'q'}, {'d', 'r'}, {'e', 's'}, {'f', 't'}, {'g', 'u'}, {'h', 'v'}, {'i', 'w'}, {'j', 'x'}, {'k', 'y'}, {'l', 'z'}, {'m', 'a'}, {'n', 'b'}, {'o', 'c'}, {'p', 'd'}, {'q', 'e'}, {'r', 'f'}, {'s', 'g'}, {'t', 'h'}, {'u', 'i'}, {'v', 'j'}, {'w', 'k'}, {'x', 'l'}, {'y', 'm'}, {'z', 'n'}}},
            {'p', {{'a', 'p'}, {'b', 'q'}, {'c', 'r'}, {'d', 's'}, {'e', 't'}, {'f', 'u'}, {'g', 'v'}, {'h', 'w'}, {'i', 'x'}, {'j', 'y'}, {'k', 'z'}, {'l', 'a'}, {'m', 'b'}, {'n', 'c'}, {'o', 'd'}, {'p', 'e'}, {'q', 'f'}, {'r', 'g'}, {'s', 'h'}, {'t', 'i'}, {'u', 'j'}, {'v', 'k'}, {'w', 'l'}, {'x', 'm'}, {'y', 'n'}, {'z', 'o'}}},
            {'q', {{'a', 'q'}, {'b', 'r'}, {'c', 's'}, {'d', 't'}, {'e', 'u'}, {'f', 'v'}, {'g', 'w'}, {'h', 'x'}, {'i', 'y'}, {'j', 'z'}, {'k', 'a'}, {'l', 'b'}, {'m', 'c'}, {'n', 'd'}, {'o', 'e'}, {'p', 'f'}, {'q', 'g'}, {'r', 'h'}, {'s', 'i'}, {'t', 'j'}, {'u', 'k'}, {'v', 'l'}, {'w', 'm'}, {'x', 'n'}, {'y', 'o'}, {'z', 'p'}}},
            {'r', {{'a', 'r'}, {'b', 's'}, {'c', 't'}, {'d', 'u'}, {'e', 'v'}, {'f', 'w'}, {'g', 'x'}, {'h', 'y'}, {'i', 'z'}, {'j', 'a'}, {'k', 'b'}, {'l', 'c'}, {'m', 'd'}, {'n', 'e'}, {'o', 'f'}, {'p', 'g'}, {'q', 'h'}, {'r', 'i'}, {'s', 'j'}, {'t', 'k'}, {'u', 'l'}, {'v', 'm'}, {'w', 'n'}, {'x', 'o'}, {'y', 'p'}, {'z', 'q'}}},
            {'s', {{'a', 's'}, {'b', 't'}, {'c', 'u'}, {'d', 'v'}, {'e', 'w'}, {'f', 'x'}, {'g', 'y'}, {'h', 'z'}, {'i', 'a'}, {'j', 'b'}, {'k', 'c'}, {'l', 'd'}, {'m', 'e'}, {'n', 'f'}, {'o', 'g'}, {'p', 'h'}, {'q', 'i'}, {'r', 'j'}, {'s', 'k'}, {'t', 'l'}, {'u', 'm'}, {'v', 'n'}, {'w', 'o'}, {'x', 'p'}, {'y', 'q'}, {'z', 'r'}}},
            {'t', {{'a', 't'}, {'b', 'u'}, {'c', 'v'}, {'d', 'w'}, {'e', 'x'}, {'f', 'y'}, {'g', 'z'}, {'h', 'a'}, {'i', 'b'}, {'j', 'c'}, {'k', 'd'}, {'l', 'e'}, {'m', 'f'}, {'n', 'g'}, {'o', 'h'}, {'p', 'i'}, {'q', 'j'}, {'r', 'k'}, {'s', 'l'}, {'t', 'm'}, {'u', 'n'}, {'v', 'o'}, {'w', 'p'}, {'x', 'q'}, {'y', 'r'}, {'z', 's'}}},
            {'u', {{'a', 'u'}, {'b', 'v'}, {'c', 'w'}, {'d', 'x'}, {'e', 'y'}, {'f', 'z'}, {'g', 'a'}, {'h', 'b'}, {'i', 'c'}, {'j', 'd'}, {'k', 'e'}, {'l', 'f'}, {'m', 'g'}, {'n', 'h'}, {'o', 'i'}, {'p', 'j'}, {'q', 'k'}, {'r', 'l'}, {'s', 'm'}, {'t', 'n'}, {'u', 'o'}, {'v', 'p'}, {'w', 'q'}, {'x', 'r'}, {'y', 's'}, {'z', 't'}}},
            {'v', {{'a', 'v'}, {'b', 'w'}, {'c', 'x'}, {'d', 'y'}, {'e', 'z'}, {'f', 'a'}, {'g', 'b'}, {'h', 'c'}, {'i', 'd'}, {'j', 'e'}, {'k', 'f'}, {'l', 'g'}, {'m', 'h'}, {'n', 'i'}, {'o', 'j'}, {'p', 'k'}, {'q', 'l'}, {'r', 'm'}, {'s', 'n'}, {'t', 'o'}, {'u', 'p'}, {'v', 'q'}, {'w', 'r'}, {'x', 's'}, {'y', 't'}, {'z', 'u'}}},
            {'w', {{'a', 'w'}, {'b', 'x'}, {'c', 'y'}, {'d', 'z'}, {'e', 'a'}, {'f', 'b'}, {'g', 'c'}, {'h', 'd'}, {'i', 'e'}, {'j', 'f'}, {'k', 'g'}, {'l', 'h'}, {'m', 'i'}, {'n', 'j'}, {'o', 'k'}, {'p', 'l'}, {'q', 'm'}, {'r', 'n'}, {'s', 'o'}, {'t', 'p'}, {'u', 'q'}, {'v', 'r'}, {'w', 's'}, {'x', 't'}, {'y', 'u'}, {'z', 'v'}}},
            {'x', {{'a', 'x'}, {'b', 'y'}, {'c', 'z'}, {'d', 'a'}, {'e', 'b'}, {'f', 'c'}, {'g', 'd'}, {'h', 'e'}, {'i', 'f'}, {'j', 'g'}, {'k', 'h'}, {'l', 'i'}, {'m', 'j'}, {'n', 'k'}, {'o', 'l'}, {'p', 'm'}, {'q', 'n'}, {'r', 'o'}, {'s', 'p'}, {'t', 'q'}, {'u', 'r'}, {'v', 's'}, {'w', 't'}, {'x', 'u'}, {'y', 'v'}, {'z', 'w'}}},
            {'y', {{'a', 'y'}, {'b', 'z'}, {'c', 'a'}, {'d', 'b'}, {'e', 'c'}, {'f', 'd'}, {'g', 'e'}, {'h', 'f'}, {'i', 'g'}, {'j', 'h'}, {'k', 'i'}, {'l', 'j'}, {'m', 'k'}, {'n', 'l'}, {'o', 'm'}, {'p', 'n'}, {'q', 'o'}, {'r', 'p'}, {'s', 'q'}, {'t', 'r'}, {'u', 's'}, {'v', 't'}, {'w', 'u'}, {'x', 'v'}, {'y', 'w'}, {'z', 'x'}}},
            {'z', {{'a', 'z'}, {'b', 'a'}, {'c', 'b'}, {'d', 'c'}, {'e', 'd'}, {'f', 'e'}, {'g', 'f'}, {'h', 'g'}, {'i', 'h'}, {'j', 'i'}, {'k', 'j'}, {'l', 'k'}, {'m', 'l'}, {'n', 'm'}, {'o', 'n'}, {'p', 'o'}, {'q', 'p'}, {'r', 'q'}, {'s', 'r'}, {'t', 's'}, {'u', 't'}, {'v', 'u'}, {'w', 'v'}, {'x', 'w'}, {'y', 'x'}, {'z', 'y'}}}
        };

        std::string resultMessage;

        for (unsigned int i = 0; i < message.size(); i++) {
            auto keyChar = keyword[i % keyword.size()];
            auto msgChar = message[i];
            resultMessage += encryptionMap[keyChar][msgChar];
        }

        std::cout << resultMessage << std::endl;
    } else if (options.count("decrypt") && options.count("message")) {
        // TODO --decrypt with no phrase just dies -- should have example usage string

        // TODO This is all the same as the --encrypt logic, except for the end. Clean it up!

        auto keyword = options["decrypt"].as<std::string>();
        auto message = options["message"].as<std::string>();

        // strip out spaces & non-alphabetic characters
        // Careful! This solution only works for ASCII (https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c)
        keyword.erase(std::remove_if(keyword.begin(), keyword.end(), []( const char & c ) { return !::isalpha(c); }), keyword.end());
        message.erase(std::remove_if(message.begin(), message.end(), []( const char & c ) { return !::isalpha(c); }), message.end());

        // transform to lower case only
        std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
        std::transform(message.begin(), message.end(), message.begin(), ::tolower);

        // repeat letters of secret phrase over and over again until same size as message
        if (keyword.size() < message.size()) {
            for (unsigned int i = keyword.size(), j = 0; i < message.size(); i++, j++) {
                keyword += keyword[j % keyword.size()];
            }
        }

        std::map<char, std::map<char, char>> encryptionMap =
        {
            {'a', {{'a', 'a'}, {'b', 'b'}, {'c', 'c'}, {'d', 'd'}, {'e', 'e'}, {'f', 'f'}, {'g', 'g'}, {'h', 'h'}, {'i', 'i'}, {'j', 'j'}, {'k', 'k'}, {'l', 'l'}, {'m', 'm'}, {'n', 'n'}, {'o', 'o'}, {'p', 'p'}, {'q', 'q'}, {'r', 'r'}, {'s', 's'}, {'t', 't'}, {'u', 'u'}, {'v', 'v'}, {'w', 'w'}, {'x', 'x'}, {'y', 'y'}, {'z', 'z'}}},
            {'b', {{'a', 'b'}, {'b', 'c'}, {'c', 'd'}, {'d', 'e'}, {'e', 'f'}, {'f', 'g'}, {'g', 'h'}, {'h', 'i'}, {'i', 'j'}, {'j', 'k'}, {'k', 'l'}, {'l', 'm'}, {'m', 'n'}, {'n', 'o'}, {'o', 'p'}, {'p', 'q'}, {'q', 'r'}, {'r', 's'}, {'s', 't'}, {'t', 'u'}, {'u', 'v'}, {'v', 'w'}, {'w', 'x'}, {'x', 'y'}, {'y', 'z'}, {'z', 'a'}}},
            {'c', {{'a', 'c'}, {'b', 'd'}, {'c', 'e'}, {'d', 'f'}, {'e', 'g'}, {'f', 'h'}, {'g', 'i'}, {'h', 'j'}, {'i', 'k'}, {'j', 'l'}, {'k', 'm'}, {'l', 'n'}, {'m', 'o'}, {'n', 'p'}, {'o', 'q'}, {'p', 'r'}, {'q', 's'}, {'r', 't'}, {'s', 'u'}, {'t', 'v'}, {'u', 'w'}, {'v', 'x'}, {'w', 'y'}, {'x', 'z'}, {'y', 'a'}, {'z', 'b'}}},
            {'d', {{'a', 'd'}, {'b', 'e'}, {'c', 'f'}, {'d', 'g'}, {'e', 'h'}, {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, {'j', 'm'}, {'k', 'n'}, {'l', 'o'}, {'m', 'p'}, {'n', 'q'}, {'o', 'r'}, {'p', 's'}, {'q', 't'}, {'r', 'u'}, {'s', 'v'}, {'t', 'w'}, {'u', 'x'}, {'v', 'y'}, {'w', 'z'}, {'x', 'a'}, {'y', 'b'}, {'z', 'c'}}},
            {'e', {{'a', 'e'}, {'b', 'f'}, {'c', 'g'}, {'d', 'h'}, {'e', 'i'}, {'f', 'j'}, {'g', 'k'}, {'h', 'l'}, {'i', 'm'}, {'j', 'n'}, {'k', 'o'}, {'l', 'p'}, {'m', 'q'}, {'n', 'r'}, {'o', 's'}, {'p', 't'}, {'q', 'u'}, {'r', 'v'}, {'s', 'w'}, {'t', 'x'}, {'u', 'y'}, {'v', 'z'}, {'w', 'a'}, {'x', 'b'}, {'y', 'c'}, {'z', 'd'}}},
            {'f', {{'a', 'f'}, {'b', 'g'}, {'c', 'h'}, {'d', 'i'}, {'e', 'j'}, {'f', 'k'}, {'g', 'l'}, {'h', 'm'}, {'i', 'n'}, {'j', 'o'}, {'k', 'p'}, {'l', 'q'}, {'m', 'r'}, {'n', 's'}, {'o', 't'}, {'p', 'u'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'}, {'u', 'z'}, {'v', 'a'}, {'w', 'b'}, {'x', 'c'}, {'y', 'd'}, {'z', 'e'}}},
            {'g', {{'a', 'g'}, {'b', 'h'}, {'c', 'i'}, {'d', 'j'}, {'e', 'k'}, {'f', 'l'}, {'g', 'm'}, {'h', 'n'}, {'i', 'o'}, {'j', 'p'}, {'k', 'q'}, {'l', 'r'}, {'m', 's'}, {'n', 't'}, {'o', 'u'}, {'p', 'v'}, {'q', 'w'}, {'r', 'x'}, {'s', 'y'}, {'t', 'z'}, {'u', 'a'}, {'v', 'b'}, {'w', 'c'}, {'x', 'd'}, {'y', 'e'}, {'z', 'f'}}},
            {'h', {{'a', 'h'}, {'b', 'i'}, {'c', 'j'}, {'d', 'k'}, {'e', 'l'}, {'f', 'm'}, {'g', 'n'}, {'h', 'o'}, {'i', 'p'}, {'j', 'q'}, {'k', 'r'}, {'l', 's'}, {'m', 't'}, {'n', 'u'}, {'o', 'v'}, {'p', 'w'}, {'q', 'x'}, {'r', 'y'}, {'s', 'z'}, {'t', 'a'}, {'u', 'b'}, {'v', 'c'}, {'w', 'd'}, {'x', 'e'}, {'y', 'f'}, {'z', 'g'}}},
            {'i', {{'a', 'i'}, {'b', 'j'}, {'c', 'k'}, {'d', 'l'}, {'e', 'm'}, {'f', 'n'}, {'g', 'o'}, {'h', 'p'}, {'i', 'q'}, {'j', 'r'}, {'k', 's'}, {'l', 't'}, {'m', 'u'}, {'n', 'v'}, {'o', 'w'}, {'p', 'x'}, {'q', 'y'}, {'r', 'z'}, {'s', 'a'}, {'t', 'b'}, {'u', 'c'}, {'v', 'd'}, {'w', 'e'}, {'x', 'f'}, {'y', 'g'}, {'z', 'h'}}},
            {'j', {{'a', 'j'}, {'b', 'k'}, {'c', 'l'}, {'d', 'm'}, {'e', 'n'}, {'f', 'o'}, {'g', 'p'}, {'h', 'q'}, {'i', 'r'}, {'j', 's'}, {'k', 't'}, {'l', 'u'}, {'m', 'v'}, {'n', 'w'}, {'o', 'x'}, {'p', 'y'}, {'q', 'z'}, {'r', 'a'}, {'s', 'b'}, {'t', 'c'}, {'u', 'd'}, {'v', 'e'}, {'w', 'f'}, {'x', 'g'}, {'y', 'h'}, {'z', 'i'}}},
            {'k', {{'a', 'k'}, {'b', 'l'}, {'c', 'm'}, {'d', 'n'}, {'e', 'o'}, {'f', 'p'}, {'g', 'q'}, {'h', 'r'}, {'i', 's'}, {'j', 't'}, {'k', 'u'}, {'l', 'v'}, {'m', 'w'}, {'n', 'x'}, {'o', 'y'}, {'p', 'z'}, {'q', 'a'}, {'r', 'b'}, {'s', 'c'}, {'t', 'd'}, {'u', 'e'}, {'v', 'f'}, {'w', 'g'}, {'x', 'h'}, {'y', 'i'}, {'z', 'j'}}},
            {'l', {{'a', 'l'}, {'b', 'm'}, {'c', 'n'}, {'d', 'o'}, {'e', 'p'}, {'f', 'q'}, {'g', 'r'}, {'h', 's'}, {'i', 't'}, {'j', 'u'}, {'k', 'v'}, {'l', 'w'}, {'m', 'x'}, {'n', 'y'}, {'o', 'z'}, {'p', 'a'}, {'q', 'b'}, {'r', 'c'}, {'s', 'd'}, {'t', 'e'}, {'u', 'f'}, {'v', 'g'}, {'w', 'h'}, {'x', 'i'}, {'y', 'j'}, {'z', 'k'}}},
            {'m', {{'a', 'm'}, {'b', 'n'}, {'c', 'o'}, {'d', 'p'}, {'e', 'q'}, {'f', 'r'}, {'g', 's'}, {'h', 't'}, {'i', 'u'}, {'j', 'v'}, {'k', 'w'}, {'l', 'x'}, {'m', 'y'}, {'n', 'z'}, {'o', 'a'}, {'p', 'b'}, {'q', 'c'}, {'r', 'd'}, {'s', 'e'}, {'t', 'f'}, {'u', 'g'}, {'v', 'h'}, {'w', 'i'}, {'x', 'j'}, {'y', 'k'}, {'z', 'l'}}},
            {'n', {{'a', 'n'}, {'b', 'o'}, {'c', 'p'}, {'d', 'q'}, {'e', 'r'}, {'f', 's'}, {'g', 't'}, {'h', 'u'}, {'i', 'v'}, {'j', 'w'}, {'k', 'x'}, {'l', 'y'}, {'m', 'z'}, {'n', 'a'}, {'o', 'b'}, {'p', 'c'}, {'q', 'd'}, {'r', 'e'}, {'s', 'f'}, {'t', 'g'}, {'u', 'h'}, {'v', 'i'}, {'w', 'j'}, {'x', 'k'}, {'y', 'l'}, {'z', 'm'}}},
            {'o', {{'a', 'o'}, {'b', 'p'}, {'c', 'q'}, {'d', 'r'}, {'e', 's'}, {'f', 't'}, {'g', 'u'}, {'h', 'v'}, {'i', 'w'}, {'j', 'x'}, {'k', 'y'}, {'l', 'z'}, {'m', 'a'}, {'n', 'b'}, {'o', 'c'}, {'p', 'd'}, {'q', 'e'}, {'r', 'f'}, {'s', 'g'}, {'t', 'h'}, {'u', 'i'}, {'v', 'j'}, {'w', 'k'}, {'x', 'l'}, {'y', 'm'}, {'z', 'n'}}},
            {'p', {{'a', 'p'}, {'b', 'q'}, {'c', 'r'}, {'d', 's'}, {'e', 't'}, {'f', 'u'}, {'g', 'v'}, {'h', 'w'}, {'i', 'x'}, {'j', 'y'}, {'k', 'z'}, {'l', 'a'}, {'m', 'b'}, {'n', 'c'}, {'o', 'd'}, {'p', 'e'}, {'q', 'f'}, {'r', 'g'}, {'s', 'h'}, {'t', 'i'}, {'u', 'j'}, {'v', 'k'}, {'w', 'l'}, {'x', 'm'}, {'y', 'n'}, {'z', 'o'}}},
            {'q', {{'a', 'q'}, {'b', 'r'}, {'c', 's'}, {'d', 't'}, {'e', 'u'}, {'f', 'v'}, {'g', 'w'}, {'h', 'x'}, {'i', 'y'}, {'j', 'z'}, {'k', 'a'}, {'l', 'b'}, {'m', 'c'}, {'n', 'd'}, {'o', 'e'}, {'p', 'f'}, {'q', 'g'}, {'r', 'h'}, {'s', 'i'}, {'t', 'j'}, {'u', 'k'}, {'v', 'l'}, {'w', 'm'}, {'x', 'n'}, {'y', 'o'}, {'z', 'p'}}},
            {'r', {{'a', 'r'}, {'b', 's'}, {'c', 't'}, {'d', 'u'}, {'e', 'v'}, {'f', 'w'}, {'g', 'x'}, {'h', 'y'}, {'i', 'z'}, {'j', 'a'}, {'k', 'b'}, {'l', 'c'}, {'m', 'd'}, {'n', 'e'}, {'o', 'f'}, {'p', 'g'}, {'q', 'h'}, {'r', 'i'}, {'s', 'j'}, {'t', 'k'}, {'u', 'l'}, {'v', 'm'}, {'w', 'n'}, {'x', 'o'}, {'y', 'p'}, {'z', 'q'}}},
            {'s', {{'a', 's'}, {'b', 't'}, {'c', 'u'}, {'d', 'v'}, {'e', 'w'}, {'f', 'x'}, {'g', 'y'}, {'h', 'z'}, {'i', 'a'}, {'j', 'b'}, {'k', 'c'}, {'l', 'd'}, {'m', 'e'}, {'n', 'f'}, {'o', 'g'}, {'p', 'h'}, {'q', 'i'}, {'r', 'j'}, {'s', 'k'}, {'t', 'l'}, {'u', 'm'}, {'v', 'n'}, {'w', 'o'}, {'x', 'p'}, {'y', 'q'}, {'z', 'r'}}},
            {'t', {{'a', 't'}, {'b', 'u'}, {'c', 'v'}, {'d', 'w'}, {'e', 'x'}, {'f', 'y'}, {'g', 'z'}, {'h', 'a'}, {'i', 'b'}, {'j', 'c'}, {'k', 'd'}, {'l', 'e'}, {'m', 'f'}, {'n', 'g'}, {'o', 'h'}, {'p', 'i'}, {'q', 'j'}, {'r', 'k'}, {'s', 'l'}, {'t', 'm'}, {'u', 'n'}, {'v', 'o'}, {'w', 'p'}, {'x', 'q'}, {'y', 'r'}, {'z', 's'}}},
            {'u', {{'a', 'u'}, {'b', 'v'}, {'c', 'w'}, {'d', 'x'}, {'e', 'y'}, {'f', 'z'}, {'g', 'a'}, {'h', 'b'}, {'i', 'c'}, {'j', 'd'}, {'k', 'e'}, {'l', 'f'}, {'m', 'g'}, {'n', 'h'}, {'o', 'i'}, {'p', 'j'}, {'q', 'k'}, {'r', 'l'}, {'s', 'm'}, {'t', 'n'}, {'u', 'o'}, {'v', 'p'}, {'w', 'q'}, {'x', 'r'}, {'y', 's'}, {'z', 't'}}},
            {'v', {{'a', 'v'}, {'b', 'w'}, {'c', 'x'}, {'d', 'y'}, {'e', 'z'}, {'f', 'a'}, {'g', 'b'}, {'h', 'c'}, {'i', 'd'}, {'j', 'e'}, {'k', 'f'}, {'l', 'g'}, {'m', 'h'}, {'n', 'i'}, {'o', 'j'}, {'p', 'k'}, {'q', 'l'}, {'r', 'm'}, {'s', 'n'}, {'t', 'o'}, {'u', 'p'}, {'v', 'q'}, {'w', 'r'}, {'x', 's'}, {'y', 't'}, {'z', 'u'}}},
            {'w', {{'a', 'w'}, {'b', 'x'}, {'c', 'y'}, {'d', 'z'}, {'e', 'a'}, {'f', 'b'}, {'g', 'c'}, {'h', 'd'}, {'i', 'e'}, {'j', 'f'}, {'k', 'g'}, {'l', 'h'}, {'m', 'i'}, {'n', 'j'}, {'o', 'k'}, {'p', 'l'}, {'q', 'm'}, {'r', 'n'}, {'s', 'o'}, {'t', 'p'}, {'u', 'q'}, {'v', 'r'}, {'w', 's'}, {'x', 't'}, {'y', 'u'}, {'z', 'v'}}},
            {'x', {{'a', 'x'}, {'b', 'y'}, {'c', 'z'}, {'d', 'a'}, {'e', 'b'}, {'f', 'c'}, {'g', 'd'}, {'h', 'e'}, {'i', 'f'}, {'j', 'g'}, {'k', 'h'}, {'l', 'i'}, {'m', 'j'}, {'n', 'k'}, {'o', 'l'}, {'p', 'm'}, {'q', 'n'}, {'r', 'o'}, {'s', 'p'}, {'t', 'q'}, {'u', 'r'}, {'v', 's'}, {'w', 't'}, {'x', 'u'}, {'y', 'v'}, {'z', 'w'}}},
            {'y', {{'a', 'y'}, {'b', 'z'}, {'c', 'a'}, {'d', 'b'}, {'e', 'c'}, {'f', 'd'}, {'g', 'e'}, {'h', 'f'}, {'i', 'g'}, {'j', 'h'}, {'k', 'i'}, {'l', 'j'}, {'m', 'k'}, {'n', 'l'}, {'o', 'm'}, {'p', 'n'}, {'q', 'o'}, {'r', 'p'}, {'s', 'q'}, {'t', 'r'}, {'u', 's'}, {'v', 't'}, {'w', 'u'}, {'x', 'v'}, {'y', 'w'}, {'z', 'x'}}},
            {'z', {{'a', 'z'}, {'b', 'a'}, {'c', 'b'}, {'d', 'c'}, {'e', 'd'}, {'f', 'e'}, {'g', 'f'}, {'h', 'g'}, {'i', 'h'}, {'j', 'i'}, {'k', 'j'}, {'l', 'k'}, {'m', 'l'}, {'n', 'm'}, {'o', 'n'}, {'p', 'o'}, {'q', 'p'}, {'r', 'q'}, {'s', 'r'}, {'t', 's'}, {'u', 't'}, {'v', 'u'}, {'w', 'v'}, {'x', 'w'}, {'y', 'x'}, {'z', 'y'}}}
        };

        // This is the part that's different! Transposing each pair of characters in the encryption map.
        std::map<char, std::map<char, char>> decryptionMap;
        for (auto row : encryptionMap) {
            for (auto pair : row.second) {
                decryptionMap[row.first].insert(std::make_pair(pair.second, pair.first));
            }
        }

        // The rest of this is the same as before...
        std::string resultMessage;

        for (unsigned int i = 0; i < message.size(); i++) {
            auto keyChar = keyword[i % keyword.size()];
            auto msgChar = message[i];
            resultMessage += decryptionMap[keyChar][msgChar];
        }

        std::cout << resultMessage << std::endl;
    } else {
        std::cout << "See \"alphabet_cipher --help\" for help." << std::endl;
    }

    return 0;
}
