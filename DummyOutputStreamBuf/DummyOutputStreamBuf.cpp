#include "DummyOutputStreamBuf.h"

int DummyOutputStreamBuf::overflow(int c) {
    return c;
}
