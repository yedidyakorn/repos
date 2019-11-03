#include<iostream>
#include"menu .h"
#include"SearchTree.h"

using namespace std;

int main() {
	SearchTreeSimple<int> tree;
	int num;
	MenuOption choice;

	tree.mode(INORDER);

	cout << "Enter 10 numbers\n";
	for (int i = 0; i<10; i++) {
		cin >> num;
		tree.add(num);
	}
	cout << "Inorder: ";
	tree.process();


	//GET_LEAVES, GET_HEIGHT, REFLECT, LEFT_SONS, GET_LEVEL, REMOVE
	while ((choice = menu()) != EXIT) {
		switch (choice) {
		case GET_LEAVES:
			cout << "Number of leaves: " << tree.leaves() << endl;
			break;

		case GET_HEIGHT:
			cout << "Height of the tree: " << tree.height() << endl;
			break;

		case REFLECT:
			tree.reflect();
			cout << "Show reflected tree: ";
			tree.process();
			tree.reflect();
			cout << endl;
			break;

		case LEFT_SONS:
			cout << "Number of left sons only: " << tree.onlyLeftSons() << endl;
			break;

		case GET_LEVEL:
			cout << "Enter a number ";
			cin >> num;
			cout << "Level of " << num << " on tree: " << tree.level(num) << endl;
			break;

		case REMOVE:
			cout << "Enter a number ";
			cin >> num;
			tree.remove(num);
			cout << "Tree after removing " << num << ": ";
			tree.process();
			cout << endl;
			break;

		default:
			cout << "ERROR!" << endl;
		}
	}
	return 0;
}
