#ifndef MENU_H
#define MENU_H

#define bannerLen 40

typedef struct menu{
	int numOptions, maxOptions;
	char **options;
	char *title;
} menuT;

typedef struct menulist{
	int numMenus;
	char *menuType;
	menuT **menus;
} menulistT;


void freeMenus(menulistT *list);
void freeMenu(menuT *menu);
void printMenu(menuT *menu);
menuT *initMenu(char *t, char **ops, int numOp);
void addOption(menuT *menu, char *entry);

#endif
