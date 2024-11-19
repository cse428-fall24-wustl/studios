#include "print.h"

namespace CustomPrint {

    void printToStream(std::ostream &os, const MyClass &value)
    {
        os << value << " ";
    }

}
