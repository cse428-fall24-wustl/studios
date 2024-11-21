#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include "string_order.h"
using namespace std;

const int SUCCESS = 0;

using namespace std;

int main(int argc, char* argv[])
{
    
    // set<char*> stringSet;

    // copy(argv, argv + argc, inserter(stringSet, stringSet.begin()));

    // copy(stringSet.begin(), stringSet.end(), ostream_iterator<string>(cout, "\n"));

    //std::set<std::string, decltype(&reverseStringOrder)> stringSet(reverseStringOrder);
    // std::multiset<std::string, decltype(&reverseStringOrder)> stringSet(reverseStringOrder);
    // std::copy(argv, argv + argc, std::inserter(stringSet, stringSet.begin()));
    // std::cout << "Contents of the set (reverse order):" << std::endl;
    // std::copy(stringSet.begin(), stringSet.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    

    std::multiset<std::string> stringSet;

    std::copy(argv, argv + argc, std::inserter(stringSet, stringSet.begin()));

    std::cout << "Contents of the multiset:" << std::endl;
    std::copy(stringSet.begin(), stringSet.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << std::endl;


    string target ="1234";

    auto range = stringSet.equal_range(target);

    std::cout << "Occurrences of \"" << target << "\":" << std::endl;
    std::copy(range.first, range.second, std::ostream_iterator<std::string>(std::cout, "\n"));

    if (range.first != range.second) {
        stringSet.erase(range.first);
    }

    std::cout << "Contents of the multiset after erasing the first occurrence of \"" << target << "\":" << std::endl;
    std::copy(stringSet.begin(), stringSet.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << std::endl;

    range = stringSet.equal_range(target);
    if (range.first != range.second) {
        stringSet.erase(range.first, range.second);
    }

    std::cout << "Contents of the multiset after erasing all occurrences of \"" << target << "\":" << std::endl;
    std::copy(stringSet.begin(), stringSet.end(), std::ostream_iterator<std::string>(std::cout, "\n"));


    return SUCCESS;
}
