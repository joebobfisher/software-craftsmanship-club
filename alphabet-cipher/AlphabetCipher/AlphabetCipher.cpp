#include "AlphabetCipher.h"

namespace opt = boost::program_options;

static std::map<char, std::map<char, char>> encryptionMap = // NOLINT(cert-err58-cpp)
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

AlphabetCipher::AlphabetCipher() : _encryptionMap(encryptionMap), _decryptionMap(TransposeEncryptionMap()), _description("Options") {
    DefineOptions();
}

std::map<char, std::map<char, char>>& AlphabetCipher::TransposeEncryptionMap() {
    static std::map<char, std::map<char, char>> decryptionMap;

    for (const auto& row : encryptionMap) {
        for (auto pair : row.second) {
            decryptionMap[row.first].insert(std::make_pair(pair.second, pair.first));
        }
    }

    return decryptionMap;
}

void AlphabetCipher::DefineOptions() {
    _description.add_options()
            ("help,h", "Write help message")
            ("encrypt,e", opt::value<std::string>(), "Encrypt message with given keyword")
            ("decrypt,d", opt::value<std::string>(), "Decrypt message with given keyword")
            ("message,m", opt::value<std::string>(), "Actual message to encrypt");
}

void AlphabetCipher::Run(int argc, char ** argv) {
    // TODO break options-handling into separate class (maybe even sanitization stuff)
    ReadOptionsFromCommandLine(argc, argv);

    if (ReceivedValidEncryptionRequest()) {
        RunEncryption();
    } else if (ReceivedValidDecryptionRequest()) {
        RunDecryption();
    } else if (ReceivedHelpRequest()) {
        ShowHelp();
    } else {
        ShowOptionsError();
    }
}

void AlphabetCipher::ReadOptionsFromCommandLine(int argc, char** argv) {
    opt::store(opt::parse_command_line(argc, argv, _description), _options);
    opt::notify(_options);
}

bool AlphabetCipher::ReceivedValidEncryptionRequest() {
    return _options.count("encrypt") && _options.count("message");
}

void AlphabetCipher::RunEncryption() {
    _keyword = _options["encrypt"].as<std::string>();
    _message = _options["message"].as<std::string>();

    SanitizeInputs();
    std::string encryptedMessage = EncryptMessage();
    std::cout << encryptedMessage << std::endl;
}

void AlphabetCipher::SanitizeInputs() {
    Sanitize(_keyword);
    Sanitize(_message);
}

void AlphabetCipher::Sanitize(std::string &stringToModify) {
    RemoveNonAlphabeticCharacters(stringToModify);
    TransformToLowerCase(stringToModify);
}

void AlphabetCipher::RemoveNonAlphabeticCharacters(std::string &stringToModify) {
    // Careful! This solution only works for ASCII (https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c)
    stringToModify.erase(std::remove_if(stringToModify.begin(),
                                        stringToModify.end(),
                                        [](const char &c) { return !::isalpha(c); }),
                         stringToModify.end());
}

void AlphabetCipher::TransformToLowerCase(std::string &stringToModify) {
    std::transform(stringToModify.begin(), stringToModify.end(), stringToModify.begin(), ::tolower);
}

std::string AlphabetCipher::EncryptMessage() {
     return BuildResultMessage(&AlphabetCipher::GetEncryptionValue);
}

std::string AlphabetCipher::BuildResultMessage(char (AlphabetCipher::*charMapFunc)(char keyChar, char msgChar)) {
    std::string resultMessage;

    for (unsigned int i = 0; i < _message.size(); i++) {
        auto keyChar = _keyword[i % _keyword.size()];
        auto msgChar = _message[i];
        resultMessage += (this->*charMapFunc)(keyChar, msgChar);
    }

    return resultMessage;
}

char AlphabetCipher::GetEncryptionValue(const char keyChar, const char messageChar) {
    // TODO keyChar and messageChar should be paired values in a single object (monad)
    return _encryptionMap[keyChar][messageChar];
}

bool AlphabetCipher::ReceivedValidDecryptionRequest() {
    return _options.count("decrypt") && _options.count("message");
}

void AlphabetCipher::RunDecryption() {
    _keyword = _options["decrypt"].as<std::string>();
    _message = _options["message"].as<std::string>();

    SanitizeInputs();
    std::string decryptedMessage = DecryptMessage();
    std::cout << decryptedMessage << std::endl;
}

std::string AlphabetCipher::DecryptMessage() {
    return BuildResultMessage(&AlphabetCipher::GetDecryptionValue);
}

char AlphabetCipher::GetDecryptionValue(const char keyChar, const char messageChar) {
    return _decryptionMap[keyChar][messageChar];
}

bool AlphabetCipher::ReceivedHelpRequest() {
    return _options.count("help");
}

void AlphabetCipher::ShowHelp() {
    // TODO would be nice to have an example usage string
    std::cout << _description << std::endl;
}

void AlphabetCipher::ShowOptionsError() {
    std::cout << "See \"alphabet_cipher --help\" for help." << std::endl;
}
