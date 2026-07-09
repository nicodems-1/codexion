CC=cc
flags=-Wall -Wextra -Werror
args=6 100 20 20 10 2 5 0
.phony = NAME, all, clean, fclean, re, debug


make:
	$(CC) -g3 src/main.c src/initialization.c  src/parsing.c src/utils.c -Iincludes

run: make
	./a.out $(args)
clean:

fclean:

re:

debug:
