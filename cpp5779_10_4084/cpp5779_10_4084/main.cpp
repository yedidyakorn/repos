/*
File: main.cpp
Description:
Course: 150018 C++ Workshop
Exercise 10, Question 1
Author:Yedidya Korn
*/
#include<iostream>
#include<list>
#include<algorithm>
#include<string>
#include"menu.h"
#include"student.h"


using namespace std;

void add(list<Student*> lst)
{
	int choice,id,numOfCourses,research;
	string fname, lname;
	cout << "enter 1 to add a BA student\n enter 2 to add a MA student\n enter 3 to add a PHD student\n";
	cin >> choice;
	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> id >> fname >> lname >> numOfCourses;
	switch (choice)
	{
	default: 
		cout << "ERROR";
		break;
	case 1:
	{
		cout << "enter " << numOfCourses << " grades\n";
		BA* temp = new BA(id, fname, lname, numOfCourses);
		temp->entreGrades(numOfCourses);
		lst.push_back(temp);
		delete temp;
		break;
	}
	case 2:
	{
		cout << "enter " << numOfCourses << " grades\n";
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> research;
		MA* temp2 = new MA(id, fname, lname, numOfCourses);
		temp2->entreGrades(numOfCourses);
		if (research)
			temp2->setResearch(true);
		lst.push_back(temp2);
		delete temp2;
		break;
	}
	case 3:
	{
		PHD* temp3 = new PHD(id, fname, lname, numOfCourses);
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> research;
		if (research)
		{
			cout << "enter number of research hours\n";
			cin >> research;
		}
		temp3->setResearch(research);
		lst.push_back(temp3);
		delete temp3;
		break;
	}
	}

}

void milga(list<Student*> lst) {
	
	for_each(lst.begin(), lst.end(), [](Student* a) {if (a->stipend())  a->print(); });
}


Student* mostResearchHours(list<Student*> lst) {
	int most = 0;
	Student* mostt=nullptr;
	list<Student*>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
	{
		Student* std = *it;
		if (std->studType() == "PHD"&&std->getResearch() > most) {
			most = std->getResearch();
			mostt = *it;
		}
	}
	return mostt;  
}

int main() {
	
	list<Student*> lst;	

	MenuOption choice;
	Student* ptrStud;
	list<Student*>::iterator it;
	while ((choice = menu()) != EXIT) {
		int num;
		switch (choice) {
		case ADD_NEW_STUDENT:
			add(lst);
			break;

		case STIPEND_LIST:
			milga(lst);	
			break;

		case MOST_RESEARCH:
			ptrStud = mostResearchHours(lst);
			cout << "PHD studnet with most research hours: ";
			cout << ptrStud->firstName() << ' ' << ptrStud->lastName() << endl;
		break;

		case COUNT_STIPEND_BA:			// Prints  all the BA eligibles for stipend
			cout << "#BA studnets for milga: ";
			for_each(lst.begin(), lst.end(), [](Student* a) {if (a->stipend()&&a->studType()=="BA")  a->print(); });
			cout << endl;
			break;

		case NO_RESEARCH_MA:			// prints a list of last name and first name of the MA that are not doing any research
			cout << "list of no research MA students : ";
			for_each(lst.begin(), lst.end(), [](Student* a) {if (a->stipend() && a->getResearch() ==0) cout << a->firstName() << ' ' << a->lastName() << endl; });
			cout << endl;
			break;

		case OVERHEAD_STUDENT:
			for (it = lst.begin(); it != lst.end(); it++)
			{
				Student* std = *it;
				if (std->getCurses() > 15)
				{
					cout << "there is a student that takes more than 15 courses\n";
					break;
				}
			}
			cout << "no student takes more than 15 courses\n";
			break;

		case REMOVE_PHD_FAILERS:	// removes from the vector or the list all the PHD students who do not learn any courses
			lst.remove_if([](Student* a) { (a->studType() == "PHD" && a->getCurses() == 0); });

			break;

		default:
			cout << "ERROR!" << endl;
		}
	}

	return 0;
}
