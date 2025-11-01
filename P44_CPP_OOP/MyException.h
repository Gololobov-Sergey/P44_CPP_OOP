#pragma once
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


class MyException
{
	string date;
	string file;
	int line;
	string message;


public:
	MyException(string date, string file, int line, string message) : date(date), file(file), line(line), message(message) {}

	void saveError()
	{
		ofstream out("log.txt", ios::app);
		out << date << " | " << file << " | line: " << line << " | " << message << endl;
		out.close();
	}

	string getError()
	{
		return date + " | " + file + " | line: " + to_string(line) + " | " + message;
	}
};