CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

todo_api_0: sockets.o message0.o
	$(CC) $(CFLAGS) -o todo_api_0 sockets.o message0.o -lm

todo_api_1: sockets.o message1.o
	$(CC) $(CFLAGS) -o todo_api_1 sockets.o message1.o -lm

todo_api_2: sockets.o message2.o
	$(CC) $(CFLAGS) -o todo_api_2 sockets.o message2.o -lm

todo_api_3: sockets.o message3.o
	$(CC) $(CFLAGS) -o todo_api_3 sockets.o message3.o -lm

todo_api_4: todo_api_4.c rest_api.h rest_api.c rest_api_2.c queue.c list.c
	$(CC) $(CFLAGS) -o $@  $^

todo_api_5: todo_api_5.c rest_api.h rest_api.c rest_api_2.c queue.c list.c
	$(CC) $(CFLAGS) -o $@  $^

todo_api_6: todo_api_6.c rest_api.h rest_api.c rest_api_2.c queue.c list.c
	$(CC) $(CFLAGS) -o $@  $^

sockets.o: sockets.c sockets.h
	$(CC) $(CFLAGS) -c sockets.c

message0.o: message0.c sockets.h
	$(CC) $(CFLAGS) -c message0.c

message1.o: message1.c sockets.h
	$(CC) $(CFLAGS) -c message1.c

message2.o: message2.c sockets.h
	$(CC) $(CFLAGS) -c message2.c

message3.o: message3.c sockets.h
	$(CC) $(CFLAGS) -c message3.c

.PHONY: clean
clean:
	rm -f todo_api_0 todo_api_1 todo_api_2 sockets.o message0.o message1.o message2.o
