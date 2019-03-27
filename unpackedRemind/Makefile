RED='\033[1;91m'
GREEN=\033[0;32m
NC='\033[0m'
NCGREEN = \033[0m
BLUE=\033[1;96m

CC=gcc
ProgName=remindGui
ProgLocation=remindGui.c
CFLAGS1+=`pkg-config --cflags gtk+-3.0`
CFLAGS2+=`pkg-config --libs gtk+-3.0`

help:
	@echo $(RED)"Comandi Disponibili:"$(NC)
	@echo "\t$(BLUE)remind$(NCGREEN) - Compila il Programma"
	@echo "\t$(GREEN)clean$(NCGREEN) - clean up"
	@echo "\t$(GREEN)help$(NCGREEN) - Stampa questo Messaggio di Aiuto"

remind:
	$(CC) $(CFLAGS1) $(ProgLocation) -o $(ProgName) $(CFLAGS2)

test: 
	$(CC) $(CFLAGS1) test.c -o test $(CFLAGS2)

clean: 
	$(RM) $(ProgName) && tput reset 

.PHONY: 
	$(ProgName) clean & tput reset 