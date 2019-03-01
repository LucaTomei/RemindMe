#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void copyright(){
    printf("\n");
     printf("   +======================================================================+\n"
		"   |                       Automatic Main Generator                       |\n"
		"   +======================================================================+\n"
		"   |                  Copyright (C) 2018 Luca Tomei                       |\n"
		"   +----------------------------------------------------------------------+\n"
		"   |\tVersion: 1.0                                                          |\n"
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

void renamer_append(){
  //asprintf(&append, "%s%s", string1, string2);
  char filename[] = "abcdefghi.c";
  char temp[101];   // name of the file read from stdimput
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
    printf("File %s created successfully!\n", newfilename);
  }else{
   fprintf(stderr, "Error renaming %s.\n", filename);
   exit(EXIT_FAILURE);
  }
  
}

void standard_includers(){
  system("echo '#include <stdio.h>' >> abcdefghi.c");
  system("echo '#include <stdlib.h>' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo 'int main(int argc, char const *argv[]){' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo '\treturn 0;' >> abcdefghi.c");
  system("echo '}' >> abcdefghi.c");

  renamer_append();
}

void Threads_Semaphores(){
  system("echo '#include <stdio.h>' >> abcdefghi.c");
  system("echo '#include <stdlib.h>' >> abcdefghi.c");
  system("echo '#include <pthread.h>' >> abcdefghi.c");
  system("echo '#include <semaphore.h>' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo 'int main(int argc, char const *argv[]){' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo '\treturn 0;' >> abcdefghi.c");
  system("echo '}' >> abcdefghi.c");

  renamer_append();
}

void processes_signals(){
  system("echo '#include <stdio.h>' >> abcdefghi.c");
  system("echo '#include <stdlib.h>' >> abcdefghi.c");
  system("echo '#include <unistd.h>' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo 'int main(int argc, char const *argv[]){' >> abcdefghi.c");
  system("echo >> abcdefghi.c");
  system("echo '\treturn 0;' >> abcdefghi.c");
  system("echo '}' >> abcdefghi.c");

  renamer_append();
}

int main(int argc, char const *argv[]){
  copyright();
  printf("What kind of C program do you need?\n");
  printf("(1) Normal program\t(2) Threads/Semaphore\t(3) Processes/Signals\n");
  int choice;
  scanf("%d", &choice);
  printf("\n\n");
  switch (choice){
    case 1:
      standard_includers();
      break;
    case 2:
      Threads_Semaphores();
      break;
    case 3:
      processes_signals();
      break;
    default:
      printf("See you again!\n");
      break;
  }
  printf("See you again!\n");
  sleep(1);

  system("tput reset");
  
  return 0;
}
