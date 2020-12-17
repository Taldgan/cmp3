#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songlist.h"

const char *options[] = {"List", "Option Two!!!", "Option Three\?!\?"};
const int NUM_OPTIONS = 3;

void printMenu(){
	int i;
	for(i = 1; i <= sizeof(options)/sizeof(options[0]); i++){
		printf("%d: %s\n", i, options[i-1]);	
	}
	printf("0: Quit\n");
}

void printFileNames(){
	FILE *fp;
	fp = popen("/usr/bin/ls ~/Documents/cmp3/music", "r"); //opens pipe to process
	if(fp != NULL){		//popen returns NULL if fails to execute command
		char line[1000];
		puts("\n----------------FILE LIST----------------");
		while(fgets(line, sizeof(line), fp)){
			printf("\t%s", line);
		}
		puts("-----------------------------------------\n");
	}
	pclose(fp);
}

int main(int argc, char *argv[]){
	//update for safety!
	char userIn[20];
	int i;
	do{
		do{
			printMenu();
			printf("Please pick a number: ");
			scanf("%s", userIn);
			if(atoi(userIn) == 1){
				printFileNames();
			}
		}while(atoi(userIn) != 0 && atoi(userIn) > NUM_OPTIONS);
	}while(strncmp("0", userIn, 2) != 0);
	return 0;
}
