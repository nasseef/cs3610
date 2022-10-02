

CC = g++
CFLAGS = -Wall -std=c++14

a.out: main.cc
	$(CC) $(CFLAGS) main.cc -o a.out