#include "Date.h"
#include"String.h"
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
using namespace std;

const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date()
{
	day = 27;
	month = 9;
	year = 2006;
}
Date::Date(int d, int m, int y) :Date()
{
	setYear(y);
	setMonth(m);
	setDay(d);
}
void Date::setDate(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}
void Date::setDay(int d)
{
	if (isLeapYear())
	{
		if (month != 2 && (d > 0 && d <= daysInMonth[month]))
			day = d;
		else if (month == 2 && (d > 0 && d <= 29))
			day = d;
		return;
	}
	else
	{
		if (d > 0 && d <= daysInMonth[month])
			day = d;
		return;
	}

}
void Date::setMonth(int m)
{
	if (m > 0 && m < 13)
		month = m;
	return;
}
void Date::setYear(int y)
{
	if (y >= 1500 && y <= 3000)
		year = y;
	return;
}
bool Date::isLeapYear()const
{
	if ((year % 4 == 0) || ((year % 400 == 0) && (year % 100 == 0)) || ((year % 400 != 0) && (year % 100 != 0)))
		return true;
	else
		return false;
}
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
void Date::printFormat1()const
{
	cout << month << "/" << day << "/" << year << '\n';
}
void Date::printFormat2()const
{
	const char* monthName[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	cout << monthName[month - 1] << " " << day << ", " << year << '\n';
}
void Date::printFormat3()const
{
	const char* monthName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	cout << day << "-" << monthName[month - 1] << "-" << year << '\n';
}
String Date::getDateInFormat2()const
{
	const char* monthName[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	String dateFormat{ monthName[month - 1] };
	String tempStr{ " " };
	dateFormat.insert(dateFormat.getLength(), tempStr);
	tempStr.setNumber(day);
	dateFormat.insert(dateFormat.getLength(), tempStr);
	String tempStr2{ ", " };
	dateFormat.insert(dateFormat.getLength(), tempStr2);
	tempStr2.setNumber(year);
	dateFormat.insert(dateFormat.getLength(), tempStr2);
	return dateFormat;
}
String Date::getDateInFormat1()const
{
	String tempStr;
	tempStr.setNumber(month);
	String dateFormat{ tempStr };
	String tempStr2{ '/' };
	dateFormat.insert(dateFormat.getLength(), tempStr2);
	tempStr.setNumber(day);
	dateFormat.insert(dateFormat.getLength(), tempStr);
	dateFormat.insert(dateFormat.getLength(), tempStr2);
	tempStr.setNumber(year);
	dateFormat.insert(dateFormat.getLength(), tempStr);
	return dateFormat;

}
String Date::getDateInFormat3()const
{
	const char* monthName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	String dateFormat{ monthName[month - 1] };
	String tempStr;
	tempStr.setNumber(day);
	dateFormat.insert(0, tempStr);
	String tempStr2{ '-' };
	dateFormat.insert(tempStr.getLength(), tempStr2);
	dateFormat.insert(dateFormat.getLength(), tempStr2);
	tempStr.setNumber(year);
	dateFormat.insert(dateFormat.getLength(), tempStr);
	return dateFormat;
}
void Date::incDay(int d)
{
	int totalDays = d + day;
	while (totalDays > daysInMonth[month])
	{
		if (month == 2 && (isLeapYear()))
		{
			if (totalDays == 29)
				day = 29;
			return;
		}
		if (month + 1 == 2)
		{

			isLeapYear() ? totalDays = (totalDays - (daysInMonth[month] + 1)) : totalDays = (totalDays - daysInMonth[month]);
			incMonth();
		}
		else
		{
			totalDays = (totalDays - daysInMonth[month]);
			incMonth();
		}
	}

	day = totalDays;
}
void Date::incMonth(int m)
{
	if (month + m > 12)
	{
		if (month + m % 12 != 0)
		{
			month = (month + m) % 12;
			year = year + ((month + m) / 12) + 1;
		}
		else
			year = year + ((month + m) / 12);
		return;
	}
	month = month + m;
	return;
}
void Date::incYear(int y)
{
	year = year + y;
}
bool Date::isValidDate(int d, int m, int y)const
{

	if (y >= 1500 && y <= 3000)
	{
		if (m > 0 && m < 13)
		{
			if ((month != 2 && (d > 0 && d <= daysInMonth[month])) || (month == 2 && (d > 0 && d <= 29)))
			{
				return true;
			}

		}

	}
	return false;
}
Date Date::todaysDate()
{
	time_t now = time(nullptr);
	tm* local_Time = localtime(&now);
	Date d;
	d.setDate(local_Time->tm_mday, (local_Time->tm_mon) + 1, (local_Time->tm_year) + 1900);
	return d;
}

bool Date::isEqual(const Date& d)const
{
	if ((d.getDay() == getDay()) && (d.getMonth() == getMonth()) && (d.getYear() == getYear()))
		return true;
	return false;

}
