// main.cpp
#include "Pressure.h"
#include "Weekday.h"
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
	set<Weekday> Weekdays;
	Weekdays.insert(Weekday::Mon);
	Weekdays.insert(Weekday::Tue);
	Weekdays.insert(Weekday::Wed);

	set<Weekday> Weekdays2;
	Weekdays2.insert(Weekday::Mon);
	Weekdays2.insert(Weekday::Tue);
	Weekdays2.insert(Weekday::Thu);

	set<Weekday> result;
	result.insert(Weekday::Sun);

	set_union(Weekdays.begin(), Weekdays.end(), Weekdays2.begin(), Weekdays2.end(), inserter(result, result.begin()));

	for (Weekday day : result)
	{
		cout << day << endl;
	}

	return 0;
}