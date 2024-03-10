CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
TARGET := hnm

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(TARGET)
