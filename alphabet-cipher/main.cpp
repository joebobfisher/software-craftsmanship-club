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
        std::cout << "Caught --encrypt; given secret word was: \"" << options["encrypt"].as<std::string>() << "\"" << std::endl;
        std::cout << "Caught --message; given message was: \"" << options["message"].as<std::string>() << "\"" << std::endl;
    } else {
        std::cout << "See \"alphabet_cipher --help\" for help.";
    }

    return 0;
}
