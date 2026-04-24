#ifndef TASK_H
#define TASK_H
#include "String.h"
#include "Time.h"
#include "Date.h"
class Task
{
	Date taskDate;
	Time taskTime;
	String taskMsg;
public:
	Task();
	Task(const Date& d, const Time& t, const String& m);
	void setTask(const Date& d, const Time& t, const String& m);
	void updateDate(const Date& nd);
	void updateTime(const Time& nt);
	void updateMessage(const String& m);
	Date getDate()const;
	Time getTime()const;
	String getMessage()const;
};

#endif

