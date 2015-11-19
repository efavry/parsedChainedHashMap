cc=gcc
CFLAGS = -Wall -Wextra -Werror -fpic -pedantic -ansi -g

vv=valgrind
VFLAGS = -v --leak-check=full --track-origins=yes --show-leak-kinds=all --leak-resolution=high --leak-check-heuristics=all --keep-stacktraces=alloc-and-free

OUT = hashmap.i386

SRC=$(wildcard ./src/*.c)

run: $(OUT)
	./$(OUT)

alone: $(OUT)
	

val: $(OUT)
	$(vv) ./$(OUT) $(VFLAGS)

purge: 
	rm $(OUT)

$(OUT): $(INCLUDE) $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) -Iinclude
