#include "bus.h"
using namespace std;

Bus *buses = nullptr;

int numOfBuses = 0;

void addBus(const Bus& bus);
void busDtor(const Bus* bus);

Bus* busCtor(int id, int seats)
{
	if (id < 1 || id>9999)
		throw intToString(id);
	if (seats < 8 || seats>50)
		throw seats;
	Bus *temp = new Bus;
	Bus* tmp;
	temp->_busDriver = nullptr;
	temp->_busLine = 0;
	temp->_busId = id;
	temp->_busSеаts = seats;
	try {
		addBus(*temp);
	}
	catch (const char* a) {
		busDtor(temp);
		throw a;
	}
	tmp = temp;
	delete temp;
	return tmp;
	
}//

Bus* busCtor(int id)
{
	if (id < 1 || id>9999)
		throw intToString(id);
	Bus *temp = new Bus;
	Bus* tmp;
	temp->_busDriver = nullptr;
	temp->_busLine = 0;
	temp->_busId = id;
	temp->_busSеаts = 50;
	try {
		addBus(*temp);
	}
	catch(const char* a){
		busDtor(temp);
		throw a;
	}
	tmp = temp;
	delete temp;
	return tmp;
}

void addBus(const Bus& bus)
{
	Bus *list = new Bus[numOfBuses +1];
	if (buses == nullptr)
	{
		list[0] = bus;
		numOfBuses++;
		buses = list;
		delete list;
		return;
	}
	else
		if (check(bus._busId) > 0)
			throw intToString(bus._busId);
	int i=0,j=0;
	for (i; i < numOfBuses; i++,j++)
	{
		if (bus._busId > buses[i]._busId)
			list[i] = buses[j];
		else
			break;
	}
	if (i == numOfBuses)
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
}

void delBus(int num) 
{
	int j = check(num);
	if (j < 0)
		throw intToString(num);
	if (buses[j]._busLine)
			throw buses[j]._busLine;
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
}

void busDtor(const Bus* bus)
{
	delete bus->_busDriver;
	delete bus;
}

void busLine(Bus& bus, uint line)
{
	if (line < 0||line>9)
		throw line;
	if (line == 0)
	{
		try {
			lineDelBus(bus._busId, bus._busLine);
			bus._busLine = 0;
		}
		catch (const char* ) {
			cout << "the bus is not assigned to the current line.\n";
		}
	}
	if (bus._busLine != 0) {
		try {
			lineDelBus(bus._busId, bus._busLine);
		}
		catch (const char* ) {
			cout << "error wiith bus infomatoin\n";
		}
	}
	try {
		lineAddBus(bus._busId, line);
		bus._busLine = line;
	}
	catch (int num) {
		bus._busLine = 0;
		throw num;
	}
	catch (const char* a) {
		bus._busLine = 0;
		throw a;
	}
}

uint busLine(const Bus& bus) { return bus._busLine;}

void busDriver(Bus& bus, const cstring name)
{
	if (name == nullptr || strcmp(name, "") == 0)
		throw nullptr;
	if (bus._busDriver)
		delete bus._busDriver;
	bus._busDriver = new char[strlen(name)];
}

cstring busDriver(const Bus& bus) { return bus._busDriver; }

void busPrint(const Bus& bus) 
{
	cout << "bus license id: " << bus._busId << "\n number of seats: " << bus._busSеаts << "\n";
	if (bus._busLine != 0)
		cout << "line number: " << bus._busLine << "\n";
	else
		cout << "No line is assigned\n";
	if (bus._busDriver)
		cout << "bus driver's name: " << bus._busDriver << "\n";
	else
		cout << "no bus driver\n";
}

void busFleetDtor()
{
	for (int i = 0; i < numOfBuses; i++)
	{
		try {
			lineDelBus(buses[i]._busId, buses[i]._busLine);
			delete buses[i]._busDriver;
			delete &buses[i];
		}
		catch (...) {
			cout << "error wiith buses infomatoin\n";
		}
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
	if(check(id)>=0)
			return true;
	return false;
}

Bus* getBus(uint id)
{
	if (!checkBus(id))
		throw (intToString(id));
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