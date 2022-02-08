#include "AlphabetCipher/AlphabetCipher.h"

int main(int argc, char ** argv) {
    AlphabetCipher alphabetCipher = AlphabetCipher();

    alphabetCipher.Run(argc, argv);

    return 0;
}
