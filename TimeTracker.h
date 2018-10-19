#pragma once 
#include <time.h>
#include <stdexcept>

class TimeTracker 
{
	public:
		TimeTracker()
		{
			Start();
		}

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


