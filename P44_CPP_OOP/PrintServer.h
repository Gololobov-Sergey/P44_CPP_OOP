#pragma once
#include <iostream>
#include <string>
#include<iomanip>

#include "functions.h"

using namespace std;


#include "PriorityQueue.h"
#include"ForwardList.h"


enum class DEPARTMENT
{
	GENERAL, TRANSPORT, ECONOMICS, DIRECTOR
};

ostream& operator<<(ostream& out, const DEPARTMENT& d)
{
	switch (d)
	{
	case DEPARTMENT::GENERAL:   out << "GENERAL"; break;
	case DEPARTMENT::TRANSPORT: out << "TRANSPORT"; break;
	case DEPARTMENT::ECONOMICS: out << "ECONOMICS"; break;
	case DEPARTMENT::DIRECTOR:  out << "DIRECTOR"; break;
	}
	return out;
}



class TaskPrint
{
	string fName;
	size_t time;
	DEPARTMENT department;

public:
	TaskPrint(string fn, size_t t, DEPARTMENT d) : fName(fn), time(t), department(d) {}

	DEPARTMENT getDepartment()
	{
		return department;
	}

	size_t getTime()
	{
		return time;
	}

	friend ostream& operator<<(ostream& out, const TaskPrint& tp);
};

ostream& operator<<(ostream& out, const TaskPrint& tp)
{
	out << setw(10) << left << tp.department << setw(10) << tp.fName << " " << tp.time << endl;
	return out;
}

class PrintServer
{
	string ip;
	PriorityQueue<TaskPrint, DEPARTMENT> qPrint;
	ForwardList<TaskPrint> lStats;

	TaskPrint* currentTask = nullptr;
	int leftTime = 0;

	int totalTime = 0;
	
public:
	PrintServer(string ip) : ip(ip) {}

	void addTask(TaskPrint tp)
	{
		qPrint.enqueue(tp, tp.getDepartment());
	}

	void work()
	{
		system("cls");
		SetColor(Yellow, Blue);
		cout << "PrintServer : " << ip << endl;
		cout << "--------------------------------" << endl << endl;
		SetColor(White, Blue);
		if (qPrint.length() > 0 && currentTask == nullptr)
		{
			currentTask = new TaskPrint(*qPrint.front());
			qPrint.dequeue();
			leftTime = currentTask->getTime();
		}


		cout << "Current document : left time - " << leftTime << endl;
		if (currentTask)
		{
			cout << *currentTask << endl;
		}
		else
		{
			cout << " " << endl;
		}

		cout << "Waiting : " << endl;
		cout << "--------------------------------------" << endl;
		qPrint.print();

		gotoxy(42, 6);
		cout << "Printing : ";
		gotoxy(42, 7);
		cout << "--------------------------------------" << endl;
		lStats.print(42, 8, 10);

		leftTime--;
		if (leftTime < 0)
		{
			if(currentTask)
				lStats.push_back(*currentTask);
			currentTask = nullptr;
			leftTime = 0;
		}
	}

};
