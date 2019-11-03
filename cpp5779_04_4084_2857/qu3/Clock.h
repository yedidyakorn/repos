/*
File: Clock.h
Description: Clock class
Course: 150018 C++ Workshop
Exercise 4, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/
#pragma once


#ifndef __CLOCK_H
#define __CLOCK_H

#include <iostream>
#include"Errors.h"

using namespace std;


class Clock
{
private:
	 int _hour, _minute, _second;//feildes of clock

public:
	Clock();//defult ctor
	Clock( int hour = 0,  int minute = 0,  int second = 0);//ctor with values
	~Clock();

	void setHour(int hour);//seter
	void setMinute(int minute);//seter
	void setSecond(int second);//seter
	int getHour();//geter
	int getMinute();//geter
	int getSecond();//geter

	Clock& operator += (const int);//adds secondes to update time

};

#endif // __CLOCK_H