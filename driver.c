#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mp3.h"

const char *options[] = {"Option One", "Option Two!!!", "Option Three\?!\?"};

void printMenu(){
	int i;
	for(i = 1; i <= sizeof(options)/sizeof(options[0]); i++){
		printf("%d: %s\n", i, options[i-1]);	
	}
	printf("0: Quit\n");
}

int main(int argc, char *argv[]){
	//update for safety!
	char userIn[20];
	printMenu();
	printf("Please pick a number: ");
	scanf("%s", userIn);
	while(strncmp("0", userIn, 2) != 0){
		printMenu();
		printf("Please pick a number: ");
		scanf("%s", userIn);
	}
	return 0;
}
