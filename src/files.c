#include <dirent.h>
#include <stdio.h>

void listFiles(char *path){
	DIR *testdir; //create DIR stream pointer
	testdir = opendir(path); //assign it to directory stream for 'music' dir
	struct dirent *dptr = NULL;
	while((dptr = readdir(testdir)) != NULL){
		printf("%s\n", dptr->d_name);
	}
	closedir(testdir);
}
