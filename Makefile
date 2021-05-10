CC=gcc
Student : main.c register.o
	$(CC) -o $@ $^
clean:
	rm *.o market
