exec = cgrep
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)
	make clean

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	-rm src/*.o
	-rm src/main
