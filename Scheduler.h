#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Task.h"
class Scheduler
{
	Task* taskList;
	int noOfTasks;
	int capacity;
public:
	Scheduler();
	~Scheduler();
	Scheduler(const Scheduler& newSchedule);
	void addTask(Task& t);
	void reSize(int);
	void displayTask(const Date& d = Date(1, 1, 1500))const;
	void displayTodaysTasks()const;
};
#endif
