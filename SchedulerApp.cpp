#include "SchedulerApp.h"
#include"Task.h"
#include "String.h"
#include "Date.h"
#include"Time.h"
#include<iostream>
using namespace std;
void SchedulerApp::startApp()
{
	Scheduler schedule;
	Task task1;
	Time t;
	Date d;
	int day, m, y;
	int hour, min, sec;
	String message;
	int choice;
	do
	{
		cout << "\nPress 1 to Add a task to your List\nPress 2 to display a task\nPress 3 to display Todays Task\nPress 0 to exit\n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter Date:";
			cin >> day;
			cout << "\nEnter Month:";
			cin >> m;
			cout << "\nEnter Year:";
			cin >> y;
			d.setDate(day, m, y);
			cout << "Time:\nEnter Hours:";
			cin >> hour;
			cout << "\nEnter Minutes:";
			cin >> min;
			cout << "\nEnter Seconds";
			cin >> sec;
			t.setTime(hour, min, sec);
			cout << "Enter Your Messsage:";
			cin.ignore();
			message.input();
			task1.setTask(d, t, message);

			schedule.addTask(task1);

		}
		else if (choice == 2)
		{
			cout << "Enter Day of the task:";
			cin >> day;
			cout << "\nEnter Month of the task:";
			cin >> m;
			cout << "\nEnter Year of the task:";
			cin >> y;
			d.setDate(day, m, y);
			schedule.displayTask(d);
		}
		else if (choice == 3)
		{
			schedule.displayTodaysTasks();
		}
		else
		{

			cout << "App Closed.";

		}

	} while (choice != 0);
	return;
}