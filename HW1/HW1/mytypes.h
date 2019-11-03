#pragma once
typedef unsigned int uint;
typedef char *cstring;
#include <iostream>
#include<cstring>
#include<string.h>
#include<sstream>

int binarySearch(int *, int , int ); //בודק אם מספר הנתון מופיע במערך

int binarySearch(uint *, uint , uint ); //בודק אם מספר הנתון מופיע במערך


void delCell(int *, int , int );//delets a cell from array
void delCell(uint *, uint , uint );//delets a cell from array

void addCell(uint *, uint , uint );//adds a cell from array

void addCell(int *, int , int );//adds a cell from array
const char* intToString(int);//convorts a number to string