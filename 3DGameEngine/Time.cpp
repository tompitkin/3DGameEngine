#include "Time.h"

double Time::delta = 0;
LARGE_INTEGER Time::frequency;

void Time::startTime()
{
	QueryPerformanceFrequency(&frequency);
}

_int64 Time::getTime()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return time.QuadPart;
}

double Time::getTimePassedNano(_int64 time1, _int64 time2)
{
	return (double)((time1 - time2) * SECOND / frequency.QuadPart);
}

double Time::getDelta() 
{
	return delta;
}

void Time::setDelta(double delta)
{
	Time::delta = delta;
}
