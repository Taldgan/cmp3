#ifndef MENU_H
#define MENU_H

#define bannerLen 40

typedef struct menu{
	int numOptions, capacity;
	char **options;
	char *title;
} menuT;

typedef struct menulist{
	int numMenus, capacity;
	char *menuType;
	menuT **menus;
} menulistT;


void freeMenuList(menulistT *list);
void freeMenu(menuT *menu);
void printMenu(menuT *menu);
menuT *initMenu(char *t, char **ops, int numOp);
menulistT *initMenuList(char *t, menuT **pmenus, int pnumMenus);
void addOption(menuT *menu, char *entry);
void printMenuList(menulistT *list);

#endif
