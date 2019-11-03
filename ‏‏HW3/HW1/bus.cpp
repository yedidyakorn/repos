#include "bus.h"
using namespace std;

Bus *buses = new Bus;

int numOfBuses = 0;

bool addBus(const Bus& bus);
void busDtor(const Bus* bus);

Bus* busCtor(int id, int seats)
{
	Bus *temp = new Bus;
	temp->_busDriver = nullptr;
	temp->_busLine = 0;
	temp->_busId = id;
	temp->_busSеаts = seats;
	if (id < 1 || id>9999 || seats < 8 || seats>50)
		return nullptr;
	if (addBus(*temp))
		return temp;
	delete temp;
	return nullptr;
	
}//

Bus* busCtor(int id)
{
	Bus *temp = new Bus;
	temp->_busDriver = nullptr;
	temp->_busLine = 0;
	temp->_busId = id;
	temp->_busSеаts = 50;
	if (id < 1 || id>9999)
		return nullptr;
	if (addBus(*temp))
		return temp;
	delete temp;
	return nullptr;
}

bool addBus(const Bus& bus)
{
	Bus *list = new Bus[numOfBuses +1];
	if (buses == nullptr)
	{
		list[0] = bus;
		numOfBuses++;
		buses = list;
		delete list;
		return true;
	}
	int i=0,j=0;
	for (i; i < numOfBuses; i++,j++)
	{
		if (bus._busId > buses[i]._busId)
			list[i] = buses[j];
		else
			break;
	}
	if (i = numOfBuses)
		list[i+1] = bus;
	else
	{
		list[i] = bus;
		i++;
		for (i; i <= numOfBuses; i++)
			list[i] = buses[j];
	}
	numOfBuses++;
	buses = list;
	delete list;
	return true;
}

bool delBus(int num) 
{
	int j = -1;
	for (int i = 0; i < numOfBuses; i++)
		if (buses[i]._busId == num&&buses[i]._busLine)
			j = i;
	if (j==-1)
		return false;
	Bus *list = new Bus[numOfBuses -1];
	for (int k = 0, i = 0; i <numOfBuses-1; i++, k++)
	{
		if (i == j)
			k++;
		list[i] = buses[k];
	}
	busDtor(&buses[j]);
	numOfBuses--;
	buses = list;
	delete list;
	return true;
}

void busDtor(const Bus* bus)
{
	delete bus->_busDriver;
	delete bus;
}

bool busLine(Bus& bus, uint line)
{
	if (line < 0||line>9)
		return false;
	if (line == 0)
	{
		lineDelBus(bus._busId, bus._busLine);
		bus._busLine = 0;
		return true;
	}
	if (bus._busLine != 0)
		lineDelBus(bus._busId, bus._busLine);
	if (lineAddBus(bus._busId, line))
		bus._busLine = line;
	else
		return false;
	return true;
}

uint busLine(const Bus& bus) { return bus._busLine;}

bool busDriver(Bus& bus, const cstring name)
{
	if (name == nullptr || strcmp(name, "") == 0)
		return false;
	if (bus._busDriver)
		delete bus._busDriver;
	bus._busDriver = new char[strlen(name)];
	return true;
}

cstring busDriver(const Bus& bus) { return bus._busDriver; }

void busPrint(const Bus& bus) 
{
	cout << "bus license id: " << bus._busId << "\n number of seats: " << bus._busSеаts << "\n";
	if (bus._busLine != 0)
		cout << "line number: " << bus._busLine << "\n";
	else
		cout << "No line is assigned\n";
	if (bus._busDriver!=nullptr)
		cout << "bus driver's name: " << bus._busDriver << "\n";
	else
		cout << "no bus driver\n";
}

void busFleetDtor()
{
	for (int i = 0; i < numOfBuses; i++)
	{
		lineDelBus(buses[i]._busId, buses[i]._busLine);
		delete buses[i]._busDriver;
		delete &buses[i];
	}
	delete buses;
}

uint* getBusList()
{
	uint *list = new uint[numOfBuses];
	for (int i = 0; i < numOfBuses; i++)
		list[i] = buses[i]._busId;
	return list;
}

bool checkBus(uint id)
{
	if(check>=0)
			return true;
	return false;
}

Bus* getBus(uint id)
{
	if (!checkBus(id))
		return nullptr;
	return &buses[check(id)];
}

int check(uint id) //בודק אם המספר הנתון מופיע במערך
{
	int mid;
	int low = 0;
	int high = numOfBuses - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (id == buses[mid]._busId)
			return mid;
		else if (id > buses[mid]._busId)
			low = mid + 1;
		else { high = mid - 1; }
	}
	return -1;
}
	
void printAll()
{
	for (int i = 0; i < numOfBuses; i++)
		busPrint(buses[i]);
}