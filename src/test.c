#include <stdlib.h>
#include "menu.h"
#include <stdio.h>

//Want to be able to create a list of related menus easily
//Control entries using functions in this c file
//...

char *options[2] = {"Op 1", "Op 2"};
char *options2[2] = {"Play", "Pause"};
char *title = "Test Menu";
char *title2 = "Test Menu2";

int main(int argc, char *argv[]){
	menuT *testMenu = NULL;
	menuT *testMenu2 = NULL;
	testMenu = initMenu(title, options, 2); 
	testMenu2 = initMenu(title2, options2, 2); 

	printf("Title: %s\nOption 1: %s\n Option 2: %s\n", testMenu->title, testMenu->options[0], testMenu->options[1]);
	printMenu(testMenu);
	puts("Adding 'op3'");
	addOption(testMenu, "Op 3");
	printMenu(testMenu);
	menuT *menus[2] = {testMenu, testMenu2};
	menulistT *testMenuList = initMenuList("Test Menu List", menus, 2);
	puts("Printing Menulist:\n");
	printMenuList(testMenuList);
	freeMenuList(testMenuList);
	return 0;
}
