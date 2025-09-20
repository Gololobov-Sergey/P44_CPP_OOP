#pragma once

class Time
{
	int hours;
	int minutes;
	int seconds;

public:
	Time() : Time(0) {};
	Time(int seconds) : Time(0, seconds) {};
	Time(int minutes, int seconds) : Time(0, minutes, seconds) {};
	Time(int hours, int minutes, int seconds);
	void print() const;
}

Time::Time(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

