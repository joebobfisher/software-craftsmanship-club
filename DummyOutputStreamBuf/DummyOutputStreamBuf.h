#ifndef FIZZBUZZ_DUMMYOUTPUTSTREAMBUF_H
#define FIZZBUZZ_DUMMYOUTPUTSTREAMBUF_H

#include <iostream>

class DummyOutputStreamBuf : public std::streambuf {
public:
    int overflow(int c) override;
};

#endif //FIZZBUZZ_DUMMYOUTPUTSTREAMBUF_H
