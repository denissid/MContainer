
#include <iostream>

#include <vector>
#include <deque>
#include <set>
#include <list>
#include <forward_list> 

#include <unordered_set>

#include "MeasureCommands.h" 

int main (int argc, char* argv[])
{
	using namespace std;

	{
		using namespace MeasureSequenceContainers;
		cout << " vector<int> " << endl;
		vector<int> v;

		cout << "time of push  back in microseconds " << PushBackTime(v) << endl;
		cout << "time of push with reserve in microseconds " << PushBackReserveTime(v) << endl;
		cout << "time of push front in microseconds " << PushFrontTime(v) << endl;

		cout << "time of sort in microseconds " << SortTime(v) << endl;
		cout << "time of stable sort in microseconds " << StableSortTime(v) << endl;
		cout << "time of find in microseconds " << FindTime(v) << endl;
		
		cout << "time of enumerate " << EnumerateTime(v) << endl;
	}

	{
		using namespace MeasureSequenceContainers;
		cout << " deque<int> " << endl;
		deque<int> v;

		cout << "time of push  back in microseconds " << PushBackTime(v) << endl;
		cout << "time of push front in microseconds " << PushFrontTime(v) << endl;

		cout << "time of sort in microseconds " << SortTime(v) << endl;
		cout << "time of stable sort in microseconds " << StableSortTime(v) << endl;
		cout << "time of find in microseconds " << FindTime(v) << endl;

		cout << "time of enumerate " << EnumerateTime(v) << endl;
	}

	{
		using namespace MeasureSequenceContainers;
		cout << " list<int> " << endl;
		list<int> v;

		cout << "time of push  back in microseconds " << PushBackTime(v) << endl;
		cout << "time of push front in microseconds " << PushFrontTime(v) << endl;

		cout << "time of sort in microseconds " << SortListTime(v) << endl;
		cout << "time of find in microseconds " << FindTime(v) << endl;

		cout << "time of enumerate " << EnumerateTime(v) << endl;
	}

	{
		using namespace MeasureSequenceContainers;
		cout << " forward_list<int> " << endl;
		forward_list<int> v;

		cout << "time of push front in microseconds " << PushBackTime(v) << endl;

		cout << "time of sort in microseconds " << SortListTime(v) << endl;
		cout << "time of find in microseconds " << FindTime(v) << endl;

		cout << "time of enumerate " << EnumerateTime(v) << endl;
	}

	{
		using namespace MeasureAssociativeContainers;
		cout << " set<int> " << endl;
		set<int> m;

		cout << "time of insert in microseconds " << InsertTime (m) << endl;
		cout << "time of find in microseconds " << FindTime (m) << endl;
		cout << "time of enumerate " << EnumerateTime(m) << endl;
	}

	{
		using namespace MeasureAssociativeContainers;
		cout << " unordered_set<int> " << endl;
		unordered_set<int> m;

		cout << "time of insert in microseconds " << InsertTime (m) << endl;
		cout << "time of find in microseconds " << FindTime (m) << endl;
		cout << "time of enumerate " << EnumerateTime(m) << endl;
	}
	return 0;
}
