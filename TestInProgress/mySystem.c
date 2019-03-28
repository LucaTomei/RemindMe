#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <linux/inotify.h>
#include <sys/stat.h>
#include <string.h>

#define EVENT_SIZE (sizeof (struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

#define handle_error(msg)\
do{\
  perror(msg);\
  exit(EXIT_FAILURE);\
}while(0)


int doPolling(char* nameOfFileOrDir){
	int length, fd, wd, i = 0;
  	char buffer[EVENT_BUF_LEN];

  	/*creating the INOTIFY instance*/
  	fd = inotify_init();

  	/*checking for error*/
  	if (fd < 0) return 1;

  	char* path = nameOfFileOrDir;

  	/*adding the “/tmp” directory into watch list. Here, the suggestion is to validate the existence of the directory before adding into monitoring list.*/
  	wd = inotify_add_watch(fd, path, IN_CREATE | IN_DELETE);
  	if(wd == -1)	return 1;

  	length = read(fd, buffer, EVENT_BUF_LEN); 
  	if(length < 0)	return 1;


  	while(i < length){     
  		struct inotify_event *event = (struct inotify_event *) &buffer[ i ];     
  		if (event->len) {
      		if (event->mask & IN_CREATE) {
        		if (event->mask & IN_ISDIR) {
          			printf( "New directory %s created.\n", event->name);
        		}
        	else {
          		printf("New file %s created.\n", event->name);
        	}
      		}else if ( event->mask & IN_DELETE ) {
        		if ( event->mask & IN_ISDIR ) {
          			printf("Directory %s deleted.\n", event->name);
        		}
        		else {
          			printf("File %s deleted.\n", event->name);
        		}
      		}
    	}
    	i += EVENT_SIZE + event->len;
    	printf("%d\n", i);
  	}
  	if(i == 16)	return 0;
  	
  	/*removing the “/tmp” directory from the watch list.*/
   	if(inotify_rm_watch( fd, wd ) != 0)	 return 1;

  	/*closing the INOTIFY instance*/
   	close(fd);
   	return 0;
}


char* append(char* string1, char* string2){
    size_t dim = (strlen(string1)) + (strlen(string2) + 1);
    char *tmp = malloc(dim * sizeof(char));
    strcpy(tmp, string1);
    strcat(tmp, string2);
    return tmp;
}

int mySyscall(char* commandToExecute){
	int res;
	char* fileName = "tempor.tjs";
	FILE* f = fopen(fileName, "w");
	fprintf(f, "%s\n", "none");
	fclose(f);

	char* initString = "gnome-terminal --geometry 60x20+100+300 -- sh -c '";
	char* finalSring = ";sleep 1;rm tempor.tjs;exit;exec bash;'";
	size_t dim = (strlen(initString) + strlen(commandToExecute) + strlen(finalSring) +1);
	char* finalCommand = malloc(dim * sizeof(char*));
	strcpy(finalCommand, initString);
	strcat(finalCommand, commandToExecute);
	strcat(finalCommand, finalSring);

	// Now do magic!!!!
	res = system(finalCommand);
	if(res != 0)	return 1;
	res = doPolling(fileName);
	if(res != 0)	return 1;
	free(finalCommand);


	// check if file is not removed, then remove them
	struct stat buffer;
    int exist = stat(fileName,&buffer);
    if(exist == 0){
    	res = remove(fileName);
    	if(res != 0)	return 1;
    }
	return 0;
}

int main(int argc, char const *argv[]){
	int res = mySyscall("sudo ls");	// its value must be 0
	if(res != 0)	handle_error("Non funziona un cazzo!");
	return 0;
}