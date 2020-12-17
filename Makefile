driver: obj/*.o
	gcc $(inputs) -o driver	
	mv driver bin/driver
obj/%.o: src/%.c
	gcc -c $(input)
	mv $(output) obj/$(output)

.PHONY: clean

clean:
	rm bin/*
	rm obj/*
