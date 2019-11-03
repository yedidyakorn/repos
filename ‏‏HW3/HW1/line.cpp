#include "line.h"

bool lineAddBus(uint id, uint line)
{
	if (linesList[line - 1]->busesNum == MAX_BUSES_IN_LINE)
		return false;
	addCell(linesList[line - 1]->idList, linesList[line - 1]->busesNum, line);
	linesList[line - 1]->busesNum++;
	return true;
}

bool lineDelBus(uint id, uint line)
{
	if (binarySearch(linesList[line - 1]->idList, linesList[line - 1]->busesNum, id) < 0)
		return false;
	delCell(linesList[line - 1]->idList, linesList[line - 1]->busesNum, id);
	linesList[line - 1]->busesNum--;
	if (linesList[line - 1]->busesNum == 0)
		delete linesList[line - 1]->idList;
	return true;
}

uint * lineGetBuses(uint line) { return linesList[line - 1]->idList; }