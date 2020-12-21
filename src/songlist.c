// Author: Taldgan
// Email: bananaphone993@live.com
// C file containing functions to create and interact with a 'song'/'playlist' data structure

#include <stdio.h>
#include "files.h"

/*
 * Linked list Node containing data about a song
 */

typedef struct songnode {
	struct songnode *next; 
	struct songnode *prev;
	char *name;				//Name of song
	char *path;				//Path to song file

} songnodeT;

/*
 * Playlist ADT. Keeps track of begining/end of list,
 * as well as current "playing" songnode.
 */

typedef struct playlist {
	songnodeT *head;		
	songnodeT *tail;
	songnodeT *playing;
	int songCount;
} playlistT;


/*
 * -skip-
 * Skip forward or backward in the playlist
 * playlistT *plist - pointer to playlist data structure being used
 * int forward - boolean determining forward(0) or back(1)
 */

void skip(playlistT *plist, int forward){
	if(forward){
		plist->playing = plist->playing->next;	
	}
	else{
		plist->playing = plist->playing->prev;	
	}	
}

/* 
 * -printPlaylist-
 * Iterates through playlist object, printing song names
 * playlistT plist - playlist ADT being iterated through
 * return void
 */

void printPlaylist(playlistT *plist){
	if(!plist)
		fprintf(stderr, "%s,", "printPlaylist: plist object NULL");
		return;
	if(!plist->head){
		puts("Empty Playlist");
		return;
	}
	songnodeT *currNode = plist->head;
	while(currNode ->next != NULL){
		if(!currNode->name)
			fprintf(stderr, "%s", "printPlaylist: missing song name");
		else
			printf("%s\n", currNode->name);
	}
}
