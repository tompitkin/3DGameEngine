#pragma once

#include <windows.h>

class Time
{
public:
	static void startTime();
	static _int64 getTime();
	static double getDelta();
	static double getTimePassedNano(_int64 time1, _int64 time2);
	static void setDelta(double delta);
	static const long SECOND = 1000000000;

private:
	static double delta;
	static LARGE_INTEGER frequency;
};

