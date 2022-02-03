#include <iostream>
#include <boost/program_options.hpp>

namespace opt = boost::program_options;

int main(int argc, char ** argv) {

    // get arguments: options for secret phrase, message
    //      use boost::program_options
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
        ("encrypt,e", "Encrypt <message> with <secretPhrase>");

    opt::variables_map options;
    opt::store(opt::parse_command_line(argc, argv, description), options);
    opt::notify(options);

    if (options.count("help")) {
        std::cout << description << std::endl;
        return 0;
    }

    return 0;
}
