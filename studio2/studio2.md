# CSE428 Studio 2

## Q1

**Participants:**

- Dijkstra Liu
- Ryan Zhang

## Q2

**Code:**

```c++
// Weekday.h
#ifndef WEEK_DAY
#define WEEK_DAY

#include <iostream>

using namespace std;

enum class Weekday {
  Sun,
  Mon,
  Tue,
  Wed,
  Thu,
  Fir,
  Sat
};

ostream& operator << (ostream&, const Weekday& day);


#endif
```

```c++
//Weekday.cpp
#include "Weekday.h"

using namespace std;

ostream& operator << (ostream& os, const Weekday& day) {
  switch(day) {
    case Weekday::Sun: os << "Sun"; break;
    case Weekday::Mon: os << "Mon"; break;
    case Weekday::Tue: os << "Tue"; break;
    case Weekday::Wed: os << "Wed"; break;
    case Weekday::Thu: os << "Thu"; break;
    case Weekday::Fri: os << "Fri"; break;
    case Weekday::Sat: os << "Sat"; break;
  }
  os << " ";
  return os;
}

```

```C++
//main.cpp
#include "Weekday.h"

using namespace std;

int main(){
  Weekday day = Weekday::Mon;
  cout<<day;
}
```

**Output:**

```bash
[l.tingjun@iht32-1502.sif studio2]$ ./studio2
Mon
```

## Q3

### Code

```c++
//Weekday.h
#ifndef WEEK_DAY
#define WEEK_DAY

#include <iostream>

using namespace std;

enum class Weekday {
  Sun,
  Mon,
  Tue,
  Wed,
  Thu,
  Fri,
  Sat
};

ostream& operator << (ostream&, const Weekday& day);

Weekday& operator ++ (Weekday& day);

Weekday operator ++ (Weekday& day, int i);

#endif
```

```C++
//Weekday.cpp
#include "Weekday.h"

using namespace std;

ostream& operator << (ostream& os, const Weekday& day) {
  switch(day) {
    case Weekday::Sun: os << "Sun"; break;
    case Weekday::Mon: os << "Mon"; break;
    case Weekday::Tue: os << "Tue"; break;
    case Weekday::Wed: os << "Wed"; break;
    case Weekday::Thu: os << "Thu"; break;
    case Weekday::Fri: os << "Fri"; break;
    case Weekday::Sat: os << "Sat"; break;
  }
  os << " ";
  return os;
}

Weekday& operator ++ (Weekday& day) {
  switch(day) {
    case Weekday::Sun: day = Weekday::Mon; break;
    case Weekday::Mon: day = Weekday::Tue; break;
    case Weekday::Tue: day = Weekday::Wed; break;
    case Weekday::Wed: day = Weekday::Thu; break;
    case Weekday::Thu: day = Weekday::Fri; break;
    case Weekday::Fri: day = Weekday::Sat; break;
    case Weekday::Sat: day = Weekday::Sun; break;
  }
  return day;
}

Weekday operator ++ (Weekday& day, int) {
    Weekday oldDay = day;
    ++day;
    return oldDay;
}

```

```C++
#include "Weekday.h"

int main() {
	Weekday weekday = Weekday::Mon;
	do {
		weekday++;
		cout << weekday;
	} while (weekday != Weekday::Mon);
}
```

### Output:

```bash
[l.tingjun@iht32-1502.sif studio2]$ ./studio2
Tue Wed Thu Fri Sat Sun Mon
```

## Q4

### Code:

```c++
//Weekday.h
#ifndef WEEK_DAY
#define WEEK_DAY

#include <iostream>

using namespace std;

enum class Weekday {
  Sun,
  Mon,
  Tue,
  Wed,
  Thu,
  Fri,
  Sat
};

ostream& operator << (ostream&, const Weekday& day);

Weekday& operator ++ (Weekday& day);

Weekday operator ++ (Weekday& day, int i);

Weekday& operator -- (Weekday& day);

Weekday operator -- (Weekday& day, int i);

#endif
```

```C++
//Weekday.cpp
#include "Weekday.h"

using namespace std;

ostream& operator << (ostream& os, const Weekday& day) {
  switch(day) {
    case Weekday::Sun: os << "Sun"; break;
    case Weekday::Mon: os << "Mon"; break;
    case Weekday::Tue: os << "Tue"; break;
    case Weekday::Wed: os << "Wed"; break;
    case Weekday::Thu: os << "Thu"; break;
    case Weekday::Fri: os << "Fri"; break;
    case Weekday::Sat: os << "Sat"; break;
  }
  os << " ";
  return os;
}

Weekday& operator ++ (Weekday& day) {
  switch(day) {
    case Weekday::Sun: day = Weekday::Mon; break;
    case Weekday::Mon: day = Weekday::Tue; break;
    case Weekday::Tue: day = Weekday::Wed; break;
    case Weekday::Wed: day = Weekday::Thu; break;
    case Weekday::Thu: day = Weekday::Fri; break;
    case Weekday::Fri: day = Weekday::Sat; break;
    case Weekday::Sat: day = Weekday::Sun; break;
  }
  return day;
}

Weekday operator ++ (Weekday& day, int) {
    Weekday oldDay = day;
    ++day;
    return oldDay;
}

Weekday& operator -- (Weekday& day) {
    switch (day) {
    case Weekday::Sun: day = Weekday::Sat; break;
    case Weekday::Mon: day = Weekday::Sun; break;
    case Weekday::Tue: day = Weekday::Mon; break;
    case Weekday::Wed: day = Weekday::Tue; break;
    case Weekday::Thu: day = Weekday::Wed; break;
    case Weekday::Fri: day = Weekday::Thu; break;
    case Weekday::Sat: day = Weekday::Fri; break;
    }
    return day;
}

Weekday operator -- (Weekday& day, int) {
    Weekday oldDay = day;
    --day;
    return oldDay;
}
```

```C++
//main.cpp
#include "Weekday.h"

int main() {
	Weekday weekday = Weekday::Mon;
	do {
		weekday--;
		cout << weekday;
	} while (weekday != Weekday::Mon);
}
```

### Output:

```bash
[l.tingjun@iht32-1502.sif studio2]$ ./studio2
Sun Sat Fri Thu Wed Tue Mon
```

## Q5

### Code:

```c++
//Pressure.h
#ifndef PRESSURE
#define PRESSURE

#include <iostream>

using namespace std;

enum class Pressure {
	Lo,
	Med,
	Hi,
	Pop
};


ostream& operator << (ostream&, const Pressure& day);

#endif
```

```C++
//Pressure.cpp
#include "Pressure.h"

using namespace std;

ostream& operator << (ostream& os, const Pressure& day) {
    switch (day) {
    case Pressure::Lo: os << "Lo"; break;
    case Pressure::Med: os << "Med"; break;
    case Pressure::Hi: os << "Hi"; break;
    case Pressure::Pop: os << "Pop"; break;
    }
    os << " ";
    return os;
}

```

```C++
//main.cpp
#include "Pressure.h"

int main() {
	Pressure p = Pressure::Lo;
	cout << p;
}
```

### output:

```bash
[l.tingjun@iht32-1502.sif studio2]$ ./studio2
Lo
```

# Q6

### Code:

```C++
//Pressure.h
#ifndef PRESSURE
#define PRESSURE

#include <iostream>

using namespace std;

enum class Pressure {
	Lo,
	Med,
	Hi,
	Pop
};


ostream& operator << (ostream&, const Pressure& day);

Pressure& operator ++ (Pressure& day);

Pressure operator ++ (Pressure& day, int i);

#endif
```

```C++
//Pressure.cpp
#include "Pressure.h"

using namespace std;

ostream& operator << (ostream& os, const Pressure& day) {
    switch (day) {
    case Pressure::Lo: os << "Lo"; break;
    case Pressure::Med: os << "Med"; break;
    case Pressure::Hi: os << "Hi"; break;
    case Pressure::Pop: os << "Pop"; break;
    }
    os << " ";
    return os;
}

Pressure& operator ++ (Pressure& day) {
    switch (day) {
    case Pressure::Lo: day = Pressure::Med; break;
    case Pressure::Med: day = Pressure::Hi; break;
    case Pressure::Hi: day = Pressure::Pop; break;
    case Pressure::Pop: day = Pressure::Pop; break;
    }
    return day;
}

Pressure operator ++ (Pressure& day, int) {
    Pressure oldDay = day;
    ++day;
    return oldDay;
}
```

```C++
//main.cpp
#include "Pressure.h"

int main() {

	for(Pressure p = Pressure::Lo;p != Pressure::Pop; p++){
		cout << p;
	}

}

```

### output

```bash
[l.tingjun@iht32-1502.sif studio2]$ ./studio2
Lo Med Hi
```
