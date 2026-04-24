#include"Time.h"
#include<iostream>
using namespace std;
Time::Time()
{
	hours = 12;
	minutes = 15;
	seconds = 30;
}
Time::Time(int h, int m, int s) :Time()
{
	setHour(h);
	setMinute(m);
	setSeconds(s);
}
void Time::setHour(int h)
{
	if (h >= 0 && h <= 23)
		hours = h;
}
void Time::setMinute(int m)
{
	if (m >= 0 && m <= 59)
		minutes = m;
}
void Time::setSeconds(int s)
{
	if (s >= 0 && s <= 59)
		seconds = s;
}
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSeconds(s);
}
int Time::getHour()
{
	return hours;
}
int Time::getMinutes()
{
	return minutes;
}
int Time::getSeconds()
{
	return seconds;
}
void Time::incHour(int h)
{
	hours = (hours + h) % 24;
}
void Time::incMin(int m)
{
	int totalMin = (minutes + m);
	minutes = totalMin % 60;
	incHour(totalMin / 60);
}
void Time::incSec(int s)
{
	int totalSec = (seconds + s);
	seconds = totalSec % 60;
	incMin(totalSec / 60);
}
void Time::printTwentyFourHourFormat()
{
	cout << hours << ":" << minutes << ":" << seconds << "\n";
}
void Time::printTwelveHourFormat()
{
	if (hours == 0)
	{
		cout << 12 << ":" << minutes << ":" << seconds << " AM" << "\n";
	}
	else if (hours == 12)
	{
		cout << 12 << ":" << minutes << ":" << seconds << " PM" << "\n";
	}
	else if (hours < 12)
	{
		cout << hours << ":" << minutes << ":" << seconds << " AM" << "\n";
	}
	else
	{
		cout << hours % 12 << ":" << minutes << ":" << seconds << " PM" << "\n";
	}
}
