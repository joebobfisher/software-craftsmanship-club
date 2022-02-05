#include <iostream>
#include <boost/program_options.hpp>

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
    // repeat letters of secret phrase over and over again until same size as message
    //      (handle case where message is smaller than secret phrase)
    // for i in message.size:
    //      schar = secret_phrase[i]
    //      mchar = message[i]
    //      encrypted_message += lookup[mchar][schar]
    // return encrypted_message
    // TODO add decrypting as well

    opt::options_description description("Options");
    description.add_options()
        ("help,h", "Write help message")
        ("encrypt,e", opt::value<std::string>(), "Encrypt message with <arg> secret word")
        ("message", opt::value<std::string>(), "Actual message to encrypt/decrypt.");

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
        keyword.erase(std::remove_if(keyword.begin(), keyword.end(), []( const char & c ) { return !::isalpha(c); }), keyword.end());
        message.erase(std::remove_if(message.begin(), message.end(), []( const char & c ) { return !::isalpha(c); }), message.end());

        // transform to lower case only
        std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
        std::transform(message.begin(), message.end(), message.begin(), ::tolower);

        std::cout << "keyword: \"" << keyword << "\"" << std::endl;
        std::cout << "message: \"" << message << "\"" << std::endl;
    } else {
        std::cout << "See \"alphabet_cipher --help\" for help.";
    }

    return 0;
}
