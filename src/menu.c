#include <string.h>
#include <stdio.h>

void printBanner(char *title, char *content){
	if(!title){
		printf("NULL title in printBanner");
		return;
	}
	int bannerLen = 40;
	int i, len;
	len = strlen(title);
	for(i = 1; i <= bannerLen; i++){
		if(i < (bannerLen/2)-(len/2)+1 || i > (bannerLen/2)+(len/2)){
			printf("%c", '-');
		}
		else{
			printf("%c", title[(i-(bannerLen/2)+1)]);
		}
	}
	printf("%s", content);
	for(i = 1; i <= 40; i++){
		printf("%c", '-');
	}
}

