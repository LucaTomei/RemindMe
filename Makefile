CC=gcc
ProgName=remindGui
ProgLocation=unpackedRemind/remindGui.c
CFLAGS1+=`pkg-config --cflags gtk+-3.0`
CFLAGS2+=`pkg-config --libs gtk+-3.0`

project:
	$(CC) $(CFLAGS1) $(ProgLocation) -o $(ProgName) $(CFLAGS2)
