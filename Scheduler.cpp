#include "Scheduler.h"
#include<iostream>
using namespace std;
Scheduler::Scheduler()
{
	capacity = 0;
	noOfTasks = 0;
	taskList = nullptr;
}
Scheduler::Scheduler(const Scheduler& newSchedule) :Scheduler()
{
	if (newSchedule.taskList == nullptr)
		return;
	capacity = newSchedule.capacity;
	noOfTasks = newSchedule.noOfTasks;
	taskList = new Task[capacity];
	for (int i = 0; i < newSchedule.capacity && i < newSchedule.noOfTasks; i++)
		taskList[i] = newSchedule.taskList[i];

}
void Scheduler::addTask(Task& t)
{
	if (noOfTasks + 1 > capacity)
		reSize(capacity + 10);
	taskList[noOfTasks].setTask(t.getDate(), t.getTime(), t.getMessage());
	noOfTasks++;
}
Scheduler::~Scheduler()
{
	delete[]taskList;
	taskList = nullptr;
	capacity = 0;
	noOfTasks = 0;
}

void Scheduler::reSize(int newSize)
{
	int i = 0;
	Task* temp = new Task[newSize];
	if (taskList != nullptr)
	{
		for (i = 0; i < noOfTasks && i < newSize; i++)
		{
			temp[i] = taskList[i];
		}
	}
	this->~Scheduler();
	taskList = temp;
	noOfTasks = i;
	capacity = newSize;
}
void Scheduler::displayTask(const Date& d)const
{

	int count = 0;
	for (int i = 0; i < noOfTasks; i++)
	{
		if (taskList[i].getDate().isEqual(d))
		{
			taskList[i].getDate().printFormat2();
			taskList[i].getTime().printTwelveHourFormat();
			taskList[i].getMessage().display();
			cout << '\n';
			count++;
		}
	}
	if (count == 0)
	{
		if (d.isEqual(Date{ 1,1,1500 }))
			displayTodaysTasks();
		else
			cout << "\nNo task on this date\n";
		return;
	}
	return;
}
void Scheduler::displayTodaysTasks()const
{
	int count = 0;
	for (int i = 0; i < noOfTasks; i++)
	{
		if ((taskList[i].getDate().isEqual(Date::todaysDate())))
		{
			taskList[i].getDate().printFormat2();
			taskList[i].getTime().printTwelveHourFormat();
			taskList[i].getMessage().display();
			cout << '\n';
			count++;
		}
	}
	if (count == 0)
		cout << "NO TASK TODAY";
	return;
}
