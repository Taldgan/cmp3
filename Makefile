SRCDIR := src
OBJDIR := obj
BINDIR := bin
DEBUGFLAGS := -ggdb

OBJECTS := $(OBJDIR)/songlist.o $(OBJDIR)/files.o $(OBJDIR)/test.o $(OBJDIR)/menu.o

run: all
	./$(BINDIR)/driver

all: $(BINDIR)/test

$(BINDIR)/test: $(OBJECTS)
	gcc $(OBJDIR)/*.o -o driver
	mv driver $(BINDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -c $(DEBUGFLAGS) $<
	mv *.o $(OBJDIR)

.PHONY: clean all run debug

debug: $(OBJECTS)
	gcc $(OBJDIR)/*.o -ggdb -o driver
	mv driver $(BINDIR)

clean:
	rm -f ./bin/*
	rm -f ./obj/*
