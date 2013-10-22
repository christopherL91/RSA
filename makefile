CC=cc
CFLAGS=-ansi -c
EXECUTABLE=RSA
LDFLAGS=-lgmp
all: program

program: main.o check_of_message.o message.o
	$(CC) main.o check_of_message.o message.o -o $(EXECUTABLE) $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) main.c

check_of_message.o: check_of_message.c
	$(CC) $(CFLAGS) check_of_message.c

message.o: message.c
	$(CC) $(CFLAGS) message.c

clean:
	rm -rf *.o RSA
