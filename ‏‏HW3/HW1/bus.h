/* 
   File: bus.h
   Description: This is the header files with all the declarations for managing a bus fleet
   Course: 150018 C++ Workshop, Exercise 1, Question 1
   Author: Dan Zilberstein
*/

#ifndef __BUS_H_
#define __BUS_H_

#include "mytypes.h"
#include "line.h"


const uint MAX_SEATS = 50; // Max number of seats in a bus
const uint MAX_ID = 9999;  // Max license id number in our small country

/*
 Bus structure
   id:     the license number of the bus (1-9999)
   line:   the line which the bus is assigned to (1-9),
           0 means that there is no line assigned to the bus
   sеаts:   amount of sеаts in the bus
   driver: the name of the driver (each bus holds its own string in dynamic memory)
   NB: The "_" prefix means that these fields are not for access in other modules than bus.cpp
*/
struct Bus {
	uint _busId;
	uint _busLine;
	uint _busSеаts;
	cstring _busDriver;
};

// Functions for creating (constructing) abus - return nullptr if the id is wrong,
// add the bus to the fleet if it is OK.
Bus* busCtor(int);      // Create a bus with id and 50 seats
Bus* busCtor(int, int); // Create a bus with id and given number of seats
                        // returns nullptr if the number of seats is illegal
// You are suggested to replace two definitions by a single definition for a small bonus

// void busDtor(const Bus*); // Destroy (destruct) a bus and free all its memory
//         it is commented out because it is for use in bus.cpp only

// Setter - Assign (set) the line for a bus (returns false if the line is illegal)
// and adds it to the line or unassigns the line for a bus and remove it from the line
// if the line number is 0
bool busLine(Bus&, uint);
// Getter - Return line number assigned to the bus
uint busLine(const Bus&);

// Setter - Assign (set) the driver name for a bus (returns false if the name is nullptr)
bool busDriver(Bus&, const cstring);
// Getter - Return a string with a copy of bus's driver name
cstring busDriver(const Bus&);

// Prints information about the bus:
// - its license id
// - number of seats
// - the line number if it is assigned, "No line is assigned" otherwise
// - The bus driver's name
void busPrint(const Bus&);

// Sorted dynamic array of buses - Egged bus fleet list...
// extern Bus** buses; (commented out because it is for internal usage only)
//                        it has to be declared and used in bus.cpp only

// The amount of buses in the fleet
extern uint busFleetCount;

// Destroy the bus fleet with all its buses, unassign the lines and free all the memory
// allocated for the buses and for the fleet management
void busFleetDtor();

// Return the list of all the bus license id numbers in the fleet
uint* getBusList();

//bool checkBus(int); // Returns true if a bus with given id exists in the fleet
// commented out because it is for use in bus.cpp only

Bus* getBus(uint);   // Returns pointer to a bus object with given id, nullptr if the bus
                    // does not exist
bool delBus(int);   // Removes a bus from the fleet and destroys it (frees its memory),
                    // returns false if the bus does not exist or if the bus is assigned
                    // to a line
//bool addBus(const Bus&); // Adds a bus to the fleet (for internal usage only)
int check(uint);//checks if a bus is in the fleet
void printAll();//prints all info

#endif __BUS_H_
