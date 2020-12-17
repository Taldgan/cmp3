// Author: Taldgan
// Email: bananaphone993@live.com
// Header for songlist functions/data structure
// More in-depth function explanations in C file

#ifndef SONGLIST_H
#define SONGLIST_H

typedef struct songnode {
	struct songnode *next;
	struct songnode *prev;
	char *name;
	char *path;

} songnodeT;

typedef struct playlist {
	songnodeT *head;
	songnodeT *tail;
	songnodeT *playing;
	int songCount;

} playlistT;

void skip(playlistT *plist, int forward);
void printPlaylist(playlistT *plist);

#endif
