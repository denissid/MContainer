#pragma once 

#include <stdlib.h>
#include <algorithm>
#include <forward_list>

#include "TimeTracker.h"

namespace MeasureSequenceContainers 
{

	template <class T>
	double PushBackTime(T& v)
	{
		int k=10;
		long diff=0;

		for (int z=0; z<k; ++z)
		{
			TimeTracker mtime;
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

	double PushFrontTime(std::forward_list<int>& v)
	{
		int k=10;
		long diff=0;

		for (int z=0; z<k; ++z)
		{
			TimeTracker mtime;
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

	template <class T>
	double PushBackReserveTime(T& v)
	{
		int k=10;
		long diff=0;
		int maxSize = 100'000;

		for (int z=0; z<k; ++z)
		{
			v.reserve (maxSize);
			TimeTracker mtime;
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

	template <typename T>
	double PushFrontTime(T& v)
	{	
		int k=10;
		double diff=0;

		for (int z=0; z<k; ++z)
		{
			TimeTracker mtime;
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

	template <typename T>
	double SortTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}

		TimeTracker mtime;
		std::sort (v.begin(), v.end());
		double timeStop = mtime.Stop();

		T().swap(v);
		return timeStop;
	}

	template <typename T>
	double SortListTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}

		TimeTracker mtime;
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

	template <typename T>
	double StableSortTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}

		std::sort (v.begin(), v.end());
		TimeTracker mtime;
		std::stable_sort (v.begin(), v.end());
		double timeStop = mtime.Stop();

		v.clear();
		return timeStop;
	}

	template <typename T>
	double FindTime(T& v)
	{
		srand(time(nullptr));
		for (int i=0; i<100'000;++i)
		{
			v.push_back(rand());
		}
		
		int lastElement = *(--v.end());
		TimeTracker mtime;
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

	template <typename T> 
	double EnumerateTime(T& v)
	{
		for (int i=0; i<100'000;++i)
		{
			v.push_back(i);
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

