CC = g++
CFLAGS = -g -Wall
setup_locales:
	$(CC) $(CFLAGS) setup_locales.cpp setup_locales.h -o setuplocales
all: setup_locales