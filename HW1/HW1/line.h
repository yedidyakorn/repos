#pragma once

#ifndef __LINE_H_
#define __LINE_H_

#include "mytypes.h"

const uint  MAX_BUSES_IN_LINE = 5; // Max 
const uint MAX_LINES = 9;  // Max 

struct Line
{
	uint busesNum;
	uint *idList;
};

__declspec(selectany) Line *linesList[MAX_LINES];

void lineAddBus(uint , uint );//assignes a bus to a line

void lineDelBus(uint , uint );//unassignes a bus to a line


uint * lineGetBuses(uint);//returns bus list for a line

#endif __LINE_H_