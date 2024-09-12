/* A C++ Program in the spirit of the classic example from page 6
   of Kernighan and Ritchie's The C Programming Language, 2nd. Ed. */

#include <iostream> // for cout ostream and endl manipulator
#include <fstream>
using namespace std; // optional, could say std::cout and std::endl below instead

const int SUCCESS = 0; // by convention, where non-zero results are error codes

int main(int argc, char **argv)
{ // argc and argv not used, but their types are specified

    const int ERROR_USAGE_VALUE = 1;

    const int ERROR_FILE_VALUE = -1;

    ofstream ofs(argv[3]);

    if (argc != 4)
    {
        cout << "usage: studio0 <number1> <number2> <filename>" << endl;
        return ERROR_USAGE_VALUE;
    }

    if (!ofs)
    {
        cout << "Error opening file: " << argv[3] << " for writing" << endl;
        return ERROR_FILE_VALUE;
    }

    ofs << atoi(argv[1]) + atoi(argv[2]); // procedural: has an effect

    return SUCCESS; // functional: returns a success/failure code
}
