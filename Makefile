all:
		gcc -Wall -Wextra -Werror read.c rush-02.c string.c

fclean:	
		rm *.out
		rm *.o
		rm *.ghc
