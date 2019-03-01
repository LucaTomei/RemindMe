#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Dichiarazione di Funzioni
void copyright();
char* append(char* str1, char* str2);
char* renamer_append();
void standard_includers();
void Threads_Semaphores();
void processes_signals();
void plus_inputs(int num_of_inputs);



int main(int argc, char *argv[]){
	int input;
	char str[20];	// per gli input da tastiera (Quanti main vuoi?);
	
   	if(argc == 2) {
   	  strcpy(str, argv[1]);
   	  input = atoi(str);
   	  if(input == 0) goto ONE_ITEM;
   	  else{
   	  	plus_inputs(input);
   	  	exit(EXIT_SUCCESS);		// serve qualcosa che alla fine blocca tutto (Miglioralo)
   	  }
   	}

ONE_ITEM:

	system("tput reset");
	copyright();
	printf("What kind of C program do you need?\n");
	printf("(1) Normal program\t(2) Threads/Semaphore\t(3) Processes/Signals\n\n");
	char choice;
	scanf("\n%c", &choice);
	printf("\n\n");
	char *tmp;
	char* subl;
	switch(choice){
		case '1':
			standard_includers();
			tmp = renamer_append();
	    	subl = append("subl ", tmp);
	    	goto F;
	    	break;	// non si sa mai!
	    case '2':
	    	Threads_Semaphores();
	    	tmp = renamer_append();
	    	subl = append("subl ", tmp);
	    	goto F;
	    	break;
	    case '3':
	    	processes_signals();
	    	tmp = renamer_append();
	    	subl = append("subl ", tmp);
	    	goto F;
	    	break;
	    default:
	      	printf("See you again!\n");
	    	break;

	F:
		printf("Do You Want To Open Your File With Sublime_Text? (Y/n)\n");
		scanf("\n%c", &choice);
		if(choice == 'y' || choice == 'Y'){	
		  	system(subl);
		}else{
			printf("See you again!\n");
		}

	  	sleep(1);
	 	system("tput reset");
	 	exit(EXIT_SUCCESS);
	}


	return 0;
}




												/*FUNZIONI*/

void plus_inputs(int num_of_inputs){
	size_t buf_size = 20;
	char* buf = (char *)malloc(sizeof(char) * buf_size);
	strcpy(buf, "");
	buf = append(buf, "subl ");
	for(int i = 0; i < num_of_inputs; i ++){
		system("tput reset");
		copyright();
		char choice;
		printf("\t    +----------------------------------------------------+\n");
		printf("\t    | Program [%d] - What kind of C program do you need?  |\n", i+1);
		printf("\t    +----------------------------------------------------+\n");
		printf("(1) Normal program\t(2) Threads/Semaphore\t(3) Processes/Signals\n\n");
		scanf("\n%c", &choice);
		printf("\n\n");
		char* tmp;
		char* subl;
		size_t subl_size = 20;
		subl = (char *)malloc(sizeof(char) * subl_size);

		strcpy(subl, "");
		
		int i;
		if(choice == '1'){
			standard_includers();
   	  		tmp = renamer_append();
	    	subl = append("subl ", tmp);				
	    	 
	    	goto PLUS_ITEMS;							
	    	break;										
		}else if(choice == '2'){
			Threads_Semaphores();
	    	tmp = renamer_append();
	    	subl = append("subl ", tmp);
	    	
	    	goto PLUS_ITEMS;
	    	break;
		}else if(choice == '3'){
			processes_signals();
	    	tmp = renamer_append();
	    	subl = append("subl ", tmp);
	    	
	    	goto PLUS_ITEMS;
	    	break;
		}else	break;
		
   	PLUS_ITEMS:
		buf = append(buf, tmp);
		buf = append(buf, " ");
		int strl = strlen(buf);
	
		if(buf[strl-2] != 'c'){
			printf("%c\n", buf[strl-2]);
			buf[strl-2] = ' ';
		}
		
	}
	char choice;
	printf("Do You Want To Open Your File With Sublime_Text? (Y/n)\n");
	scanf("\n%c", &choice);
	if(choice == 'Y' || choice == 'y'){	
		system(buf);
	}
	printf("See you again!\n");
	sleep(1);
	system("tput reset");
}


void copyright(){
    printf("\n");
     printf("   +======================================================================+\n"
		"   |                       Automatic Main Generator                       |\n"
		"   +======================================================================+\n"
		"   |                  Copyright (C) 2018 Luca Tomei                       |\n"
		"   +----------------------------------------------------------------------+\n"
		"   |\tVersion: 3.0                                                      |\n"
		"   +----------------------------------------------------------------------+\n"
		"   |  This program comes with ABSOLUTELY NO WARRANTY. This is free        |\n"
		"   |  software, and you are welcome to redistribute it under certain      |\n"
		"   |  conditions; for further details, please refer to the GNU General    |\n"
		"   |  Public License provided with this program.                          |\n"
		"   +======================================================================+\n"
    "   +======================================================================+\n\n\n\n");
}


char* append(char* str1, char* str2){
	size_t dim = (strlen(str1)) + (strlen(str2));
	char *tmp = malloc(dim * sizeof(char));
    strcpy(tmp, str1);
    strcat(tmp, str2);
   	return tmp;
}	

char* renamer_append(){
  char filename[] = "abcdefghi.c";
  char temp[100];   // name of the file read from stdimput
  char* newfilename;
  printf("Please type the name of your file\n");
  scanf("%s", temp);
  char* dot = ".c";

  // test per verifica estensione
  if(strstr(temp, dot) == NULL){
    newfilename = append(temp, dot);  // stringa con estensione
  }else{  // ho già inserito '.c'
    newfilename = temp;
  }
  
  if(rename(filename, newfilename) == 0){
    printf("\n\t\t\tFile %s created successfully!\n\n", newfilename);
  }
  else{
   fprintf(stderr, "Error renaming %s.\n", filename);
   exit(EXIT_FAILURE);

  }
  return newfilename;
}

void standard_includers(){
  system("echo '#include <stdio.h>' >> abcdefghi.c");
  system("echo '#include <stdlib.h>' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo 'int main(int argc, char *argv[]){' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo '\treturn 0;' >> abcdefghi.c");
  system("echo '}' >> abcdefghi.c");
}

void Threads_Semaphores(){
  system("echo '#include <stdio.h>' >> abcdefghi.c");
  system("echo '#include <stdlib.h>' >> abcdefghi.c");
  system("echo '#include <pthread.h>' >> abcdefghi.c");
  system("echo '#include <semaphore.h>' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo 'int main(int argc, char *argv[]){' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo '\treturn 0;' >> abcdefghi.c");
  system("echo '}' >> abcdefghi.c");
}

void processes_signals(){
  system("echo '#include <stdio.h>' >> abcdefghi.c");
  system("echo '#include <stdlib.h>' >> abcdefghi.c");
  system("echo '#include <unistd.h>' >> abcdefghi.c");
  system("echo '#include <sys/wait.h>' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo 'int main(int argc, char *argv[]){' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo '\treturn 0;' >> abcdefghi.c");
  system("echo '}' >> abcdefghi.c");
}