#ifndef __MENU_H
#define __MENU_H

enum MenuOption {
	EXIT, GET_LEAVES, GET_HEIGHT, REFLECT, LEFT_SONS, GET_LEVEL, REMOVE,
	FIRST_MENU_OPTION = EXIT, LAST_MENU_OPTION = REMOVE
};

MenuOption menu();

#endif // __MENU_H
