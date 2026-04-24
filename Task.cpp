#include"Task.h"
#include"Time.h"
#include<iostream>
using namespace std;
Task::Task()
{
}
Task::Task(const Date& d, const Time& t, const String& m) :taskDate(d), taskTime(t), taskMsg(m)
{
}
void Task::setTask(const Date& d, const Time& t, const String& m)
{

	taskDate = d;
	taskTime = t;
	if ((m.getLength() >= taskMsg.getSize()) || (taskMsg.getLength() == 0))
		taskMsg.reSize(m.getLength() + 1);
	for (int i = 0; i < m.getLength(); i++)
		taskMsg.at(i) = m.at(i);
	taskMsg.at(m.getLength()) = '\0';
}
void Task::updateDate(const Date& nd)
{
	taskDate = nd;
}
void Task::updateTime(const Time& nt)
{
	taskTime = nt;
}
void Task::updateMessage(const String& m)
{
	taskMsg.remove(0, taskMsg.getLength());
	taskMsg.insert(0, m);
}
Date Task::getDate()const
{
	return taskDate;
}
Time Task::getTime()const
{
	return taskTime;
}
String Task::getMessage()const
{
	String s;

	s.concatEqual(taskMsg);
	return s;
}
