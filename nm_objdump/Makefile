CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME0 = hnm
NAME1 = hobjdump

.PHONY: all clean oclean fclean re

all: $(NAME0) $(NAME1)

$(NAME0): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME1): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *~ $(NAME0) $(NAME1)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all
