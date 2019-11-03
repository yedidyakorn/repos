#include "line.h"

void lineAddBus(uint id, uint line)
{
	if (linesList[line - 1]->busesNum == MAX_BUSES_IN_LINE)
		throw MAX_BUSES_IN_LINE;
	if (binarySearch(linesList[line - 1]->idList, linesList[line - 1]->busesNum, id) > 0)
			throw intToString(id);
	addCell(linesList[line - 1]->idList, linesList[line - 1]->busesNum, line);
	linesList[line - 1]->busesNum++;
}

void lineDelBus(uint id, uint line)
{
	if (binarySearch(linesList[line - 1]->idList, linesList[line - 1]->busesNum, id) < 0)
		throw intToString(id);
	delCell(linesList[line - 1]->idList, linesList[line - 1]->busesNum, id);
	linesList[line - 1]->busesNum--;
	if (linesList[line - 1]->busesNum == 0)
		delete linesList[line - 1]->idList;
}

uint * lineGetBuses(uint line) { return linesList[line - 1]->idList; }