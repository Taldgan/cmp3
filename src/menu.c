#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//C file to gather user input and do various 'menu' related tasks

#define MIN_LIST 2
#define MIN_OPTION 2
#define bannerLen 90



/**
 * Menu list struct, holds a collection of similar menus
 * int numMenus - keeps track of the number of menus inside of the list
 * char *menuType - identifying type the menu is (playlists/commands/etc)
 * char *menus - array of menu structs
 */

typedef struct menulist{
	int numMenus;
	char *menuType;
	menuT *menus;
} menulistT;

/*
 * Menu struct
 * int numOptions - keeps track of the number of menu options available
 * char **options - string array of the options the menu contains
 * char *title - title of the menu for banner printing
 */

typedef struct menu{
	int numOptions;
	char **options;
	char *title;
} menuT;

//Function declarations

void freeMenus(menulistT *list);
void printBanner(menuT *menu);


/**
 * -initMenu-
 *  Initializes menu struct to contain appropriate variables
 *  char *t - 'title' string
 *  char **options - array of strings containing menu entries
 *  int numOp - the number of options to initialize the menu too
 *  return menuT - returns the newly created menu object
 */

menuT *initMenu(char *t, char** ops, int numOp){
	menuT *newMenu = (menuT *) malloc(sizeof(menuT));
	newMenu->title = t;
	int i;
	if(numOp < MIN_OPTION){
		newMenu->numOptions = MIN_OPTION;
	}
	else{
		newMenu->numOptions = numOp;
	}
	newMenu->options = (char *) malloc(sizeof(char*)*numOptions);
	newMenu->numOptions = 0;
	for(i = 0; i < newMenu->numOptions; i++){
		if(ops[i]){
			
		}
		else{
			break;
		}
	}
	return newMenu;
}

/**
 * -printMenu-
 * Prints a bannerLen based off of the title and contents of the menu struct.		-----				 -------------
 * Note: If title exceeds assigned banner length, the result is a cut off title: 	CUT O, as opposed to ===CUT OFF===
 *																					-----				 -------------
 *	menuT menu - Pointer to the menu object, printMenu prints contents of this object
 *	return void
 */

void printMenu(menuT *menu){
	if(!menu)
		return;

	int i, j, titleCount;
	int titleLen = strlen(menu->title);

	for(i = 0; i < 5; i++){
		switch(i){
			case 1:
				titleCount = 0;
				for(j = 0; j < bannerLen; j++){				//Print title in middle of banner
					if(j < ((bannerLen/2)-(titleLen/2)) || j > ((bannerLen/2)+(titleLen/2)) ){
						printf("%c", '=');
					}
					else{
						printf("%c", menu->title[titleCount++]);
					}
				}
				puts("");
				break;

			case 3:											//Print contents of menu
				for(j = 0; j < menu->numOptions; j++){
					printf("%d: %s\n", j, menu->options[j]);
				}
				break;

			default:										//Print dashes everywhere else
				for(j = 0; j < bannerLen; j++){
					printf("%c", '-');
				}
				puts("");
				break;
		}
	}
}

/**
 * -freeMenu-
 *  Free's menu object
 *  menuT *menu - the menu struct being freed
 *  return void
 */

void freeMenu(menuT *menu){
	free(menu);
}
