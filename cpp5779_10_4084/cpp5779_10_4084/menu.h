
/*
File: menu.h
Description:
Course: 150018 C++ Workshop
Exercise 10, Question 1
Author:Yedidya Korn
*/
#ifndef __MENU_H
#define __MENU_H

enum MenuOption {
	 EXIT, ADD_NEW_STUDENT, STIPEND_LIST, MOST_RESEARCH, COUNT_STIPEND_BA, NO_RESEARCH_MA, OVERHEAD_STUDENT, REMOVE_PHD_FAILERS,
	 FIRST_MENU_OPTION = EXIT, LAST_MENU_OPTION = REMOVE_PHD_FAILERS
};

MenuOption menu();

#endif // __MENU_H