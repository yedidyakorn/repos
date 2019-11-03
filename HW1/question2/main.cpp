/*
File: main.cpp
Description: mangers 4 arrays of 5 cells each with difrfrint kinds of numbers
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include <iostream>
#include <iomanip>
#include<cstring>
#include<string.h>
#include<cstdlib>
#include "common.h"
#include"Rational.h"
#include<time.h>
#include"Complex.h"
#include"mytypes.h"
#include"menu.h"

using namespace std;


// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {
	MenuOption chosen;
	srand(time(0));
	int j,type,temp1,temp2,sum=0;
	float sum1 = 0,temp3,temp4;
	int integers[5];
	float dec[5];
	Rational rational[5],rsum;
	Complex complex[5], csum;
	rsum = rationalCtor(0);
	csum = complexCtor(0);
	for (int i = 0; i < 5; i++)
	{
		integers[i] =  (rand() % 21) - 10;
		rational[i] = rationalCtor((rand() % 21) - 10, (rand() % 21) - 10);
		complex[i] = complexCtor((rand() % 21) - 10, (rand() % 21) - 10);
		dec[i]= (rand() / (float)RAND_MAX * 19) -10;
	}

	do {
		chosen = FIRST_MENU_OPTION;
		cout << chosen;
		
		++chosen;
		cout << chosen;

		cout << endl << "Menu options:" << endl << endl;
		// The user will see:
		//           0 -- exit
		//           1 -- ...
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION; ++chosen)
			cout << menuOptionStrings[chosen] << endl;
		cout << endl;
		cout << "Please choose a menu option: ";
		cin >> chosen;


		// additional preparations if needed
		// ...

		// Note how the individual cases, match nicely to the
		//     operations they will perform.
		switch (chosen) {
		case EXIT_MENU:
			break;
		case INSERT_A_NUMBER://inserts a number
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			cout << "Enter a index: \n";
			cin >> j;
			switch (type)
			{
			case 1:
				cout << "Enter a number: \n";
				cin >> temp1;
				integers[j] = temp1;
				break;
			case 2:
				cout << "Enter the numerator: \n";
				cin >> temp1;
				cout << "Enter the denominator: \n";
				cin >> temp2;
				rational[j] = rationalCtor(temp1,temp2);
				break;
			case 3:
				cout << "Enter a number: \n";
				cin >> temp3;
				dec[j] = temp3;
				break;
			case 4:
				cout << "Enter the real number: \n";
				cin >> temp3;
				cout << "Enter the imaginary : \n";
				cin >> temp4;
				complex[j] = complexCtor(temp3, temp4);
				break;
			}
			break;
		case PRINT_A_ARRAY://prints out all the array
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			switch (type)
			{
			case 1:
				for (int i = 0; i < 5; i++)
					cout<<integers[i]<<" ";
				break;
			case 2:
				for (int i = 0; i < 5; i++)
					cout << rational[i] << " ";
				break;
			case 3:
				for (int i = 0; i < 5; i++)
					cout << dec[i] << " ";
				break;
			case 4:
				for (int i = 0; i < 5; i++)
					cout << complex[i] << " ";
				break;
			}
			cout << endl;
			break;
		case CALCULATE_SUM_OF_ARRAY://calculates the sum of all the array
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			switch (type)
			{
			case 1:
				for (int i = 0; i < 5; i++)
					sum+=integers[i];
				cout << sum << endl;
				sum = 0;
				break;
			case 2:
				for (int i = 0; i < 5; i++)
					rsum = rsum + rational[i];
				cout << rsum << endl;
				rsum = rationalCtor(0);
				break;
			case 3:
				for (int i = 0; i < 5; i++)
					sum1 += dec[i];
				cout << sum1 << endl;
				sum1 = 0;
				break;
			case 4:
				for (int i = 0; i < 5; i++)
					csum = csum+complex[i];
				cout << csum << endl;
				csum = complexCtor(0);
				break;
			}
			cout << sum << endl;
			break;
		case CALCULATE_MULTIPLICATION_OF_ARRAY://calculates the multiplication of all the array
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			switch (type)
			{
			case 1:
				for (int i = 0; i < 5; i++)
					sum *= integers[i];
				cout << sum << endl;
				sum = 0;
				break;
			case 2:
				for (int i = 0; i < 5; i++)
					rsum = rsum * rational[i];
				cout << rsum << endl;
				rsum = rationalCtor(0);
				break;
			case 3:
				for (int i = 0; i < 5; i++)
					sum1 *= dec[i];
				cout << sum1 << endl;
				sum1 = 0;
				break;
			case 4:
				for (int i = 0; i < 5; i++)
					csum = csum * complex[i];
				cout << csum << endl;
				csum = complexCtor(0);
				break;
			}

			break;
		case SUM_TWO_NUMBERS://sums two numbers from the array and puts the result in a third cell
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			cout << "enter target index\n";
			cin >> j;
			cout << "enter first index to sum\n";
			cin >> temp1;
			cout << "enter second index to sum\n";
			cin >> temp2;
			switch (type)
			{
			case 1:
				operation(&integers[j], &integers[temp1], &integers[temp2], [](void * a, const void* b, const void* c) {*(int*)a = *(int*)a + *(int*)b; });
				break;
			case 2:
				operation(&rational[j], &rational[temp1], &rational[temp2], addRational);
				break;
				operation(&dec[j], &dec[temp1], &dec[temp2], [](void * a, const void* b, const void* c) {*(float*)a = *(float*)a + *(float*)b; });
				break;
			case 4:
				operation(&complex[j], &complex[temp1], &complex[temp2], addComplex);
				break;
			}
			break;
		case MULTIPLY_TWO_NUMBERS://multipliys two numbers from the array and puts the result in a third cell
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			cout << "enter target index\n";
			cin >> j;
			cout << "enter first index to multiply\n";
			cin >> temp1;
			cout << "enter second index to multiply\n";
			cin >> temp2;
			switch (type)
			{
			case 1:
				operation(&integers[j], &integers[temp1], &integers[temp2], [](void * a, const void* b, const void* c) {*(int*)a = *(int*)a * *(int*)b; });
				break;
			case 2:
				operation(&rational[j], &rational[temp1], &rational[temp2], multRational);
				break;
				operation(&dec[j], &dec[temp1], &dec[temp2], [](void * a, const void* b, const void* c) {*(float*)a = *(float*)a * *(float*)b; });
				break;
			case 4:
				operation(&complex[j], &complex[temp1], &complex[temp2], multComplex);
				break;
			}
			break;
		case SUBTRACT_TWO_NUMBERS://subs two numbers from the array and puts the result in a third cell
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			cout << "enter target index\n";
			cin >> j;
			cout << "enter first index to sub\n";
			cin >> temp1;
			cout << "enter second index to sub\n";
			cin >> temp2;
			switch (type)
			{
			case 1:
				operation(&integers[j], &integers[temp1], &integers[temp2], [](void * a, const void* b, const void* c) {*(int*)a = *(int*)a - *(int*)b; });
				break;
			case 2:
				operation(&rational[j], &rational[temp1], &rational[temp2], subRational);
				break;
				operation(&dec[j], &dec[temp1], &dec[temp2], [](void * a, const void* b, const void* c) {*(float*)a = *(float*)a - *(float*)b; });
				break;
			case 4:
				operation(&complex[j], &complex[temp1], &complex[temp2], subComplex);
				break;
			}
			break;
		case SORT_ARRAY://sorts a array
			cout << "Enter number type: \n 1-integers \n 2-rational \n 3-decimal \n 4-complex\n";
			cin >> type;
			switch (type)
			{
			case 1:
				qsort(integers, 5, sizeof(int), [](const void* b, const void* c) { return *(int*)b - *(int*)c; });
				break;
			case 2:
				qsort(rational, 5, sizeof(int), compareRational);
				break;
				qsort(dec, 5, sizeof(int), [](const void* b, const void* c) { return *(int*)b - *(int*)c; });
				break;
			case 4:
				qsort(complex, 5, sizeof(int), compareComplex);
				break;
			}
			break;

		default: cout << "ERROR\n";
			break;
		}
	} while (chosen != EXIT_MENU);

	// Do not forget here to request destroying all the data and freeing all the memory

	return 0;
}
