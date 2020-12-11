// Author: Taldgan
// Email: bananaphone993@live.com
// Header for MP3 functions/data structure

#ifndef MP3_H
#define MP3_H

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

} playlistT;

#endif
