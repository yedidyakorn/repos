#include <iostream>
#include <windows.h>
#include "board.h"
using namespace std;

board welcome() //starts a game, bulids a board
{
	system("Color 0A");
	int row, col;
	cout << "welcome to 4 in a row game! \n choose number of rows:\n";
	cin >> row;
	cout << "choose number of colums: (betreen 2-10)\n";
	cin >> col;
	while (col > 10||col<2) {
		cout << "choose number of colums: (betreen 2-10)\n";
		cin >> col;
	}
	board b(row, col);
	return b;
}

void endLine(char winner)// the end of the game
{
	if (winner == 'N')
		cout << "tiad game! play again\n";
	else
		cout << "the winner is: " << winner << endl;
}

int main() {
	char sign = 'Y';
	board b=welcome();
	b.show();
	while (!b.gameOver())
	{
		if (sign == 'X')
			sign = 'Y';
		else
			sign = 'X';
		b.actoin(sign);
		b.show();
	}
	endLine(b.winner());
	b.~board();
	system("pause");
	return 0;
}