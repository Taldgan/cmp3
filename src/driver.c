#include <stdlib.h>
#include "menu.h"
#include <stdio.h>

//Want to be able to create a list of related menus easily
//Control entries using functions in this c file
//...

char *options[2] = {"Op 1", "Op 2"};
char *title = "Test Menu";

int main(int argc, char *argv[]){
	menuT *testMenu = NULL;
	testMenu = initMenu(title, options, 0); 
	printf("Title: %s\nOption 1: %s\n Option 2: %s\n", testMenu->title, testMenu->options[0], testMenu->options[1]);
	printMenu(testMenu);
	return 0;
}
