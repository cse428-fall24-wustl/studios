#include "print.h"

namespace CustomPrint {

    void printToStream(std::ostream &os, const MyClass &value)
    {
        os << "Non-template function called: " << value;
    }

}
