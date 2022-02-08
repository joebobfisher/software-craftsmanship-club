#include "AlphabetCipher/AlphabetCipher.h"

namespace opt = boost::program_options;

int main(int argc, char ** argv) {
    AlphabetCipher alphabetCipher = AlphabetCipher();

    alphabetCipher.Run(argc, argv);

    return 0;
}
