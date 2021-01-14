#pragma once 

#include <stdlib.h>
#include <algorithm>
#include <forward_list>
#include <string>

#include "TimeTracker.h"

namespace MeasureSequenceContainers 
{

	template <class T, class Ttracker=TimeTracker>
	double PushBackTime(T& v)
	{
		int k=10;
		long diff=0;

		for (int z=0; z<k; ++z)
		{
			Ttracker mtime;
			for (int i=0; i<100'000; ++i)
			{
				v.push_back(i);
			}
			double res = mtime.Stop();
			diff += res;
			T().swap(v);
		}
		return diff/static_cast<double>(k);
	}

    template <class Ttracker=TimeTracker>
	double PushFrontTime(std::forward_list<int>& v)
	{
		int k=10;
		long diff=0;

		for (int z=0; z<k; ++z)
		{
			Ttracker mtime;
			for (int i=0; i<100'000; ++i)
			{
				v.push_front(i);
			}
			double res = mtime.Stop();
			diff += res;
			v.clear();
		}
		return diff/static_cast<double>(k);
	}

	template <class T, class Ttracker=TimeTracker>
	double PushBackReserveTime(T& v)
	{
		int k=10;
		long diff=0;
		int maxSize = 100'000;

		for (int z=0; z<k; ++z)
		{
			v.reserve (maxSize);
			Ttracker mtime;
			for (int i=0; i<maxSize; ++i)
			{
				v.push_back(i);
			}
			double res = mtime.Stop();
			diff += res;
			T().swap(v);
		}
		return diff/static_cast<double>(k);
	}

	template <typename T, class Ttracker=TimeTracker>
	double PushFrontTime(T& v)
	{	
		int k=10;
		double diff=0;

		for (int z=0; z<k; ++z)
		{
			Ttracker mtime;
			for (int i=0; i<100'000; ++i)
			{
				v.insert(v.begin(),i);
			}
			double res = mtime.Stop();
			diff += res;
			T().swap(v);
		}
		return diff/static_cast<double>(k);
	}

	template <typename T, class Ttracker=TimeTracker>
	double SortTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}

		Ttracker mtime;
		std::sort (v.begin(), v.end());
		double timeStop = mtime.Stop();

		T().swap(v);
		return timeStop;
	}

	template <typename T, class Ttracker=TimeTracker>
	double SortListTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}

		Ttracker mtime;
		v.sort();
		double timeStop = mtime.Stop();

		T().swap(v);
		return timeStop;
	}

	double SortListTime(std::forward_list<int>& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_front(rand());
		}

		TimeTracker mtime;
		v.sort();
		double timeStop = mtime.Stop();

		v.clear();
		return timeStop;
	}

	template <typename T, class Ttracker=TimeTracker>
	double StableSortTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}

		std::sort (v.begin(), v.end());
		Ttracker mtime;
		std::stable_sort (v.begin(), v.end());
		double timeStop = mtime.Stop();

		v.clear();
		return timeStop;
	}

	template <typename T, class Ttracker=TimeTracker>
	double FindTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}
		
		int lastElement = *(--v.end());
		Ttracker mtime;
		std::find(v.begin(), v.end(), lastElement);
		double timeStop = mtime.Stop();

		v.clear();
		return timeStop;
	}

	double FindTime(std::forward_list<int>& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_front(i);
		}
		
		int lastElement = *(std::find(v.begin(),v.end(),99000));
		TimeTracker mtime;
		std::find(v.begin(), v.end(), lastElement);
		double timeStop = mtime.Stop();

		v.clear();
		return timeStop;
	}

	template <typename T, class Ttracker=TimeTracker> 
	double EnumerateTime(T& v)
	{
		for (int i=0; i<100'000;++i)
		{
			v.push_back(i);
		}

		Ttracker mtime;	
		for (auto i=v.begin(); i!=v.end();++i)
		{
			int z = *i;
		}
		double timeStop = mtime.Stop();
		v.clear();
		return timeStop;
	}

	double EnumerateTime(std::forward_list<int>& v)
	{
		for (int i=0; i<100'000;++i)
		{
			v.push_front(i);
		}

		TimeTracker mtime;	
		for (auto i=v.begin(); i!=v.end();++i)
		{
			int z = *i;
		}
		double timeStop = mtime.Stop();
		v.clear();
		return timeStop;
	}
}

#include "ModernAssignment.h"

namespace MeasureAssignment
{
    std::string getString()
    {
        using namespace std;
        string t;
        for (int i=0; i<1000'000;++i)
        {
            t += to_string(1);
        }
        return t;
    }

    double AssignmentOldTime()
    {
        using namespace std;

        OldAssignment oa;
        static auto s = getString();

		TimeTracker mtime;

        for (int i=0;i<100;++i)
        {
            oa.set (s);
            //oa.set ("");
        }

		double timeStop = mtime.Stop();

        return timeStop;
    }

    double AssignmentNewTime()
    {
        using namespace std; 

        NewAssignment na;
        static auto s = getString();

		TimeTracker mtime;

        for (int i=0;i<100;++i)
        {
            na.set (s);
            //na.set ("");
        }
		double timeStop = mtime.Stop();

        return timeStop;

    }
}

namespace MeasureAssociativeContainers 
{
	template <typename T>
	double InsertTime(T& v)
	{	
		int k=10;
		long diff=0;

		for (int z=0; z<k; ++z)
		{
			TimeTracker mtime;
			for (int i=0; i<100'000; ++i)
			{
				v.insert(i);
			}
			double res = mtime.Stop();
			diff += res;
			v.clear();
		}
		return diff/static_cast<double>(k);
	}

	template <typename T>
	double FindTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.insert(i);
		}
		
		int lastElement = *v.find(99'000);
		TimeTracker mtime;
		std::find(v.begin(), v.end(), lastElement);
		double timeStop = mtime.Stop();

		v.clear();
		return timeStop;
	}
	template <typename T> 
	double EnumerateTime(T& v)
	{
		for (int i=0; i<100'000;++i)
		{
			v.insert(i);
		}

		TimeTracker mtime;	
		for (auto i=v.begin(); i!=v.end();++i)
		{
			int z = *i;
		}
		double timeStop = mtime.Stop();
		v.clear();
		return timeStop;
	}

}

