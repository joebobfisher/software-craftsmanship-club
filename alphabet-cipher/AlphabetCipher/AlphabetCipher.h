#ifndef ALPHABET_CIPHER_ALPHABETCIPHER_H
#define ALPHABET_CIPHER_ALPHABETCIPHER_H

#include <iostream>
#include <map>
#include <boost/program_options.hpp>

namespace opt = boost::program_options;

class AlphabetCipher {
public:
    AlphabetCipher();
    // TODO Probably want a better interface for using this class from another class (not at the top level)
    void Run(int argc, char** argv);

private:
    static std::map<char, std::map<char, char>>& TransposeEncryptionMap();
    void DefineOptions();
    void ReadOptionsFromCommandLine(int argc, char **argv);
    bool ReceivedValidEncryptionRequest();
    void RunEncryption();
    void SanitizeInputs();
    static void Sanitize(std::string& stringToModify);
    static void RemoveNonAlphabeticCharacters(std::string& stringToModify);
    static void TransformToLowerCase(std::string& stringToModify);
    std::string EncryptMessage();
    std::string BuildResultMessage(char (AlphabetCipher::*charMapFunc)(char keyChar, char msgChar));
    char GetEncryptionValue(char keyChar, char messageChar);
    bool ReceivedValidDecryptionRequest();
    void RunDecryption();
    std::string DecryptMessage();
    char GetDecryptionValue(char keyChar, char messageChar);
    bool ReceivedHelpRequest();
    void ShowHelp();
    static void ShowOptionsError();

    std::map<char, std::map<char, char>>& _encryptionMap;
    std::map<char, std::map<char, char>>& _decryptionMap;
    opt::options_description _description;
    opt::variables_map _options;
    std::string _keyword;
    std::string _message;
};


#endif //ALPHABET_CIPHER_ALPHABETCIPHER_H
