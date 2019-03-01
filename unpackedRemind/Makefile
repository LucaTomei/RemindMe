CC=gcc
ProgName=remindGui
CFLAGS1+=`pkg-config --cflags gtk+-3.0`
CFLAGS2+=`pkg-config --libs gtk+-3.0`

project:
	$(CC) $(CFLAGS1) *.c -o $(ProgName) $(CFLAGS2)