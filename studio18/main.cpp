#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

const int SUCCESS = 0;

int main()
{
    int arr[] = {-2, 19, 80, -47, 80, 80, -2, 19, 19};

    int *start = arr;
    int *end = arr + sizeof(arr) / sizeof(arr[0]);

    std::copy(start, end, std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
    
    std::vector<int> vec;

    std::back_insert_iterator<std::vector<int> > back_it = std::back_inserter(vec);

    std::copy(start, end, back_it);

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    std::sort(start, end);

    std::copy(start, end, std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    int *it = start;

    while (it != end)
    {
        it = std::adjacent_find(it, end);
        if (it == end)
        {
            break;
        }
        int cur = *it;
        do
        {
            std::cout << *it << " ";
            ++it;
        }
        while (it != end && *it == cur);
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::sort(start, end, std::greater<int>());

    std::copy(start, end, std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    int median = *(arr + sizeof(arr) / sizeof(arr[0]) / 2);
    std::cout << "Median: " << median << std::endl;

    float mean = static_cast<float>(std::accumulate(start, end, 0)) / (sizeof(arr) / sizeof(arr[0]));
    std::cout << "Mean: " << mean << std::endl;

    int mode = arr[0];
    int maxCount = 0;

    it = start;
    while (it != end) {
        int current = *it;
        int count = std::count(it, end, current);

        if (count > maxCount) {
            maxCount = count;
            mode = current;
        }

        it += count;
    }

    std::cout << "Mode: " << mode << std::endl;

    return SUCCESS;
}
