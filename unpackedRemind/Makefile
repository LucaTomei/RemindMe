CC=gcc
ProgName=remindGui
ProgLocation=remindGui.c
CFLAGS1+=`pkg-config --cflags gtk+-3.0`
CFLAGS2+=`pkg-config --libs gtk+-3.0`

project:
	$(CC) $(CFLAGS1) $(ProgLocation) -o $(ProgName) $(CFLAGS2)

test: 
	$(CC) $(CFLAGS1) test.c -o test $(CFLAGS2)
PHONY: 
	$(ProgName) clean & tput reset 