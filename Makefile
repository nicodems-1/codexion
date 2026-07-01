CC=cc
flags=-Wall -Wextra -Werror
args=6 100 20 20 10 2 5 0
.phony = NAME, all, clean, fclean, re, debug

make:
	$(CC) src/main.c src/initialization.c includes/struct.h src/parsing.c src/utils.c

run: make
	./a.out $(args)
clean:

fclean:

re:

debug:
