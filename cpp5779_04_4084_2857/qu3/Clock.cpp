/*
File: Clock.cpp
Description: Clock class
Course: 150018 C++ Workshop
Exercise 4, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include "Clock.h"



Clock::Clock()
{
	_hour = 0;
	_minute = 0;
	_second = 0;
}

Clock::Clock( int hour = 0,  int minute = 0, int second = 0) {
	if((hour>0&&hour<59)&&((minute<23&&minute>0)||(second < 23 && second>0)))
		throw "Wrong time format.";
	if (hour>23)
		throw "Invalid time - more than 24 hours.";
	if (minute>59)
		throw "Invalid time - more than 60 minutes.";
	if (second>59)
		throw "Invalid time - more than 60 seconds.";
	if (hour < 0)
		throw "Invalid time - negative number of hours.";
	if (minute < 0 )
		throw "Invalid time - negative number of minutes.";
	if (second < 0 )
		throw "Invalid time - negative number of seconds.";
		_hour = hour;
		_minute = minute;
		_second = second;		
}

Clock::~Clock()
{
}

void Clock::setHour(int hour){	_hour = hour;}

void Clock::setMinute(int minute){	_minute = minute;}

void Clock::setSecond(int second){	_second = second;}

int Clock::getHour(){	return _hour;}

int Clock::getMinute(){	return _minute;}

int Clock::getSecond(){	return _second;}

Clock & Clock::operator+=(const int sec)
{
	if (sec < 0)
		throw "ERROR - can't add negative number of seconds.";
	int tempS = 0,tempM=0,tempH=0;
	tempH += sec / 3600;
	tempM += sec / 60;
	tempS += sec % 60;
	_hour += tempH;
	_minute += tempM;
	_second += tempS;
	if (_second > 59) {
		_minute++;
		_second -= 60;
	}
	if (_minute > 59) {
		_hour++;
		_minute -= 60;
	}
	if (_hour > 23)
		_hour -= 24;
}
