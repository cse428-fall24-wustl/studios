# CSE428 Studio 0

## Q1

Dijkstra Liu
Ryan Zhang

## Q2
```C++
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int SUCCESS = 0;

int main()
{
    const char *hello = "Hello, ";
    const char *world = "world!";

    cout << "\"" << hello << " " << "\"" << endl;
    cout << "\"" << world << " " << "\"" << endl;

    cout << "Length of \"" << hello << "\" is " << strlen(hello) << endl;
    cout << "Length of \"" << world << "\" is " << strlen(world) << endl;

    return SUCCESS;
}

```


```bash
l.tingjun@shell studio5]$ ./main
"Hello,  "
"world! "
Length of "Hello, " is 7
Length of "world!" is 6
```

## Q3
```C++
std::size_t (*strlen_ptr)(const char *) = &std::strlen;
```

## Q4
```C++
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

const int SUCCESS = 0;

int main()
{
    float f = 3.14159;

    cout << f << endl;
    cout << sin(cos(f)) << endl;

    return SUCCESS;
}
```

```bash
3.14159
-0.841471
```


## Q5
```C++
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <functional>
using namespace std;

const int SUCCESS = 0;

int main()
{
    float f = 3.14159;

    std::function<float(float)> sin_lambda = [](float x)
    { return std::sin(x); };
    std::function<float(float)> cos_lambda = [](float x)
    { return std::cos(x); };

    cout << f << endl;
    cout << sin_lambda(cos_lambda(f)) << endl;

    return SUCCESS;
}

```

## Q6
```C++
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

    cout << f << endl;
    cout << composed(f) << endl;

    return SUCCESS;
}

```

## Q7
```C++
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
```