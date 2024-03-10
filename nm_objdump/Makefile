CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
TARGET := hnm

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "OBJ: $(OBJ)"
	@echo "SRC: $(SRC)"
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(TARGET)
