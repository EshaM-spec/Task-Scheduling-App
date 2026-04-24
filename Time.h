#ifndef TIME_H
#define TIME_H
class Time
{
	int hours;
	int minutes;
	int seconds;
public:
	Time();
	Time(int h, int m, int s);
	void setHour(int h);
	void setMinute(int m);
	void setSeconds(int s);
	void setTime(int h, int m, int s);
	int getHour();
	int getMinutes();
	int getSeconds();
	void incHour(int h = 1);
	void incMin(int m = 1);
	void incSec(int s = 1);
	void printTwentyFourHourFormat();
	void printTwelveHourFormat();
};


#endif