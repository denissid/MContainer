#pragma once 
#include <time.h>
#include <stdexcept>
#include <chrono>

class TimeTracker 
{
	public:
		TimeTracker()
		{
			Start();
		}
        
        TimeTracker(const TimeTracker&) = delete;
        TimeTracker& operator= (const TimeTracker&) = delete;

		void Start ()
		{	
			int res = clock_gettime(CLOCK_REALTIME, &time_spec_);
			if (res==-1)
			{
				throw std::runtime_error("Error clock_gettime");
			}
		}

		double Stop()
		{
			timespec ts = {0};
			int res = clock_gettime(CLOCK_REALTIME, &ts);
			if (res==-1)
			{
				throw std::runtime_error("Error clock_gettime");
			}

			return (ts.tv_sec-time_spec_.tv_sec)*1000000 + (ts.tv_nsec - time_spec_.tv_nsec)/1000;
		}

		~TimeTracker()
		{
		}

	private:
		timespec time_spec_ = {0,0};
};

class TimeTrackerChrono
{
    public:
        TimeTrackerChrono()
        {
        }
        
        double Stop()
        {
            using namespace std;
            auto end = chrono::steady_clock::now();
            auto delta = chrono::duration_cast<chrono::microseconds>(end-begin);
            return delta.count();
        }

    private:
         std::chrono::time_point<std::chrono::steady_clock> begin = std::chrono::steady_clock::now();

};

