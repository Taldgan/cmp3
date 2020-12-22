#ifndef MENU_H
#define MENU_H

#define bannerLen 90

typedef struct menu{
	int numOptions;
	char **options;
	char *title;
} menuT;

menuT *initMenu(char *t, char **ops, int numOptions);
void printMenu(menuT *menu);
void freeMenu(menuT *menu);

#endif
