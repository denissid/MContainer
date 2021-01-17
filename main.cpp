
#include <iostream>

#include <vector>
#include <deque>
#include <set>
#include <list>
#include <forward_list> 

#include <unordered_set>
#include <assert.h>

#include "MeasureCommands.h" 

template <typename T>
struct allocator_v
{
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T value_type;	

	allocator_v() = default;
	
	template <class U> 
	allocator_v(const allocator_v&)
	{}

	T* allocate (std::size_t n, const void* =0)
	{
		//std::cout << "Alloc " << n;
		return reinterpret_cast<T*> (::operator new (n*sizeof(T)));
	}

	void deallocate (T* ptr, size_t)
	{
		//std::cout << "free ";
		::operator delete(ptr);
	}
};

template <typename T>
struct allocator_s
{
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T value_type;	

	allocator_s ()
	{}

	
	template <class U> 
	allocator_s(const allocator_s& a)
	{
		assert (!"Copy constructor");
		m_p = a.m_p;
	}

	T* allocate (std::size_t n, const void* t = 0)
	{
	//	std::cout << " " << n << " mem " << t << std::endl;
		return reinterpret_cast<T*> (&m_p[0]);
	}

	void deallocate (T* ptr, size_t size)
	{
	}
	
	private:
		
	int m_p[100000] = {0};
	unsigned int m_offset = 0;
};

template <typename T, typename U>
	inline bool operator==(const allocator_v<T>&,
			       const allocator_v<U>&)
	{
		return true;
	}

template <typename T, typename U>
	inline bool operator!= (const allocator_v<T>& a,
				const allocator_v<U>& b)
	{
		return !(a==b);
	}

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

		cout << "time of push front in microseconds " << PushFrontTime(v) << endl;

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

	{	
		using namespace MeasureSequenceContainers;
		cout << " vector<int> allocator " << endl;
		vector<int, allocator_s<int> > v;

		cout << "time of push  back in microseconds " << PushBackTime(v) << endl;

	}

    {
		using namespace MeasureSequenceContainers;
		cout << " vector<int> chrono" << endl;
        using vec = vector<int>;
		vec v;

		cout << "time of push  back in microseconds " << PushBackTime< vec, TimeTrackerChrono >(v) << endl;
		cout << "time of push with reserve in microseconds " << PushBackReserveTime<vec, TimeTrackerChrono> (v) << endl;
		cout << "time of push front in microseconds " << PushFrontTime<vec, TimeTrackerChrono> (v) << endl;

		cout << "time of sort in microseconds " << SortTime<vec, TimeTrackerChrono> (v) << endl;
		cout << "time of stable sort in microseconds " << StableSortTime<vec, TimeTrackerChrono> (v) << endl;
		cout << "time of find in microseconds " << FindTime<vec, TimeTrackerChrono> (v) << endl;
		
		cout << "time of enumerate " << EnumerateTime<vec, TimeTrackerChrono>(v) << endl;
	}

    {
        using namespace MeasureAssignment;

        cout << "assignment " << endl;
        cout << "time set string old " << AssignmentTime<OldAssignment>() << endl;
        cout << "time set string move " << AssignmentTime<MoveAssignment>() << endl;
        cout << "time set string forward " << AssignmentTime<ForwardAssignment>() << endl;
    }


	return 0;
}
