// Author: Taldgan
// Email: bananaphone993@live.com

/*
 * Linked List Node containing data about a song
 */

typedef struct songnode {
	songnode *next; 
	songnode *prev;
	char *name;				//Name of song
	char *path;				//Path to song file

} songnodeT;

/*
 * Playlist ADT. Keeps track of begining/end of list, as well as current "playing" songnode.
 */

typedef struct playlist {
	songnodeT *head;		//
	songnodeT *tail;
	songnodeT *playing;

} playlistT;


void skip(playlistT *plist, int forward){
	if(forward){
		plist->playing = playing->next;	
	}
	else{
		plist->playing = playing->prev;	
	}	
}
