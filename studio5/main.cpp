#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <functional>

#include "Compose_T.h"

using namespace std;

const int SUCCESS = 0;

int main()
{
    float f = 3.14159;

    std::function<float(float)> sin_lambda = [](float x)
    { return std::sin(x); };
    std::function<float(float)> cos_lambda = [](float x)
    { return std::cos(x); };

    auto composed = compose(sin_lambda, cos_lambda);

    auto binded = bind(composed, f);

    cout << f << endl;
    cout << binded() << endl;

    return SUCCESS;
}
