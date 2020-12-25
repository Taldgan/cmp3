#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//C file to gather user input and do various 'menu' related tasks

#define MIN_LIST 2
#define MIN_OPTION 1
#define bannerLen 40

/*
 * Menu struct
 * int numOptions - keeps track of the number of menu options available
 * char **options - dynamic string array of the options the menu contains
 * char *title - title of the menu for banner printing
 */

typedef struct menu{
	int numOptions, capacity;
	char **options;
	char *title;
} menuT;

/**
 * Menu list struct, holds a collection of similar menus
 * int numMenus - keeps track of the number of menus inside of the list
 * char *menuType - identifying type the menu is (playlists/commands/etc)
 * char *menus - array of menu structs
 */

typedef struct menulist{
	int numMenus, capacity;
	char *menuType;
	menuT **menus;
} menulistT;


//Function declarations
void freeMenuList(menulistT *list);
void freeMenu(menuT *menu);
void printMenu(menuT *menu);
menuT *initMenu(char *t, char **opsa, int numOp);
menulistT *initMenuList(char *t, menuT **pmenus, int pnumMenus);
void addOption(menuT *menu, char *entry);
void printMenuList(menulistT *list);

menulistT *initMenuList(char *t, menuT **pmenus, int pnumMenus){
	if(!pmenus)
		return NULL;
	if(pnumMenus < MIN_LIST)
		return NULL;

	int i;
	menulistT *newList = malloc(sizeof(menulistT));

	newList->menuType = t;
	newList->numMenus = pnumMenus;
	newList->capacity = (newList->numMenus*2);
	newList->menus = calloc((newList->capacity), sizeof(menuT *));	
	for(i = 0; i < newList->numMenus; i++){
		newList->menus[i] = malloc(sizeof(menuT));
		newList->menus[i] = pmenus[i];
		//memcpy(newList->menus[i], pmenus[i], sizeof(menuT));
	}
	return newList;
}

/**
 * -initMenu-
 *  Initializes menu struct to contain appropriate variables
 *  char *t - 'title' string
 *  char **options - array of strings containing menu entries
 *  int numOp - the number of options to initialize the menu too
 *  return menuT - returns the newly created menu object
 */

menuT *initMenu(char *t, char **ops, int numOp){
	if(!ops)
		return NULL;
	if(numOp < MIN_OPTION){
		return NULL;
	}

	int i;
	menuT *newMenu = malloc(sizeof(menuT));

	newMenu->title = t;
	newMenu->numOptions = numOp;
	newMenu->capacity = (newMenu->numOptions*2);
	newMenu->options = NULL;
	newMenu->options = calloc(newMenu->capacity, sizeof(char*));

	for(i = 0; i < newMenu->numOptions; i++){
		newMenu->options[i] = malloc((strlen(ops[i])+1));				//Allocate space for string
		strcpy(newMenu->options[i], ops[i]);							//Copy string over using strcpy
	}
	return newMenu;
}
/**
 * -addOption-
 *  Adds an option to an existing menu, reallocating the options array if necessary.
 *  **Note: Each resize doubles the capacity of the memory to 2n
 *  menuT *menu - the menu that an option is being added to
 *  char *entry - the option being added
 *	return void
 */

void addOption(menuT *menu, char *entry){
	if(!menu)
		return;
	if(!entry)
		return;
	if(menu->numOptions == menu->capacity){
		menu->capacity *= 2;
		menu->options = reallocarray(menu->options, menu->capacity, sizeof(char *));
	}
	menu->options[menu->numOptions] = malloc(strlen(entry)+1);
	strcpy(menu->options[menu->numOptions++], entry);
}

/**
 * -printMenuList-
 * Prints every menu in the menulist
 * menulistT *list - the menulist being printed
 * return void
 */

void printMenuList(menulistT *list){
	int i;
	for(i = 0; i < list->numMenus; i++){
		printMenu(list->menus[i]);
	}
}

/**
 * -printMenu-
 * Prints a banner based off of the title and contents of the menu struct.		
 * **Note: If title exceeds assigned banner length, the result is a cut off title: 	
 *
 *		-----				 -------------																				
 *		CUT O, as opposed to ===CUT OFF===
 *		-----				 -------------
 *
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
 * -freeMenuList-
 *  Free's menulist struct
 *  menulistT *list - the menulist struct being freed
 *  return void
 */

void freeMenuList(menulistT *list){
	int i;
	for(i = 0; i < list->numMenus; i++){
		freeMenu(list->menus[i]);
	}
	free(list);
}

/**
 * -freeMenu-
 *  Free's menu struct
 *  menuT *menu - the menu struct being freed
 *  return void
 */

void freeMenu(menuT *menu){
	int i;
	for(i = 0; i < menu->numOptions; i++){
		free(menu->options[i]);				//Clear out strings
	}
	free(menu->options);					//Clear out string array
	free(menu);
}
