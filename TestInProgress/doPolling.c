#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/inotify.h>

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
      		if ( event->mask & IN_CREATE ) {
        		if ( event->mask & IN_ISDIR ) {
          			printf( "New directory %s created.\n", event->name);
        		}
        	else {
          		printf( "New file %s created.\n", event->name );
        	}
      		}else if ( event->mask & IN_DELETE ) {
        		if ( event->mask & IN_ISDIR ) {
          			printf( "Directory %s deleted.\n", event->name );
        		}
        		else {
          			printf( "File %s deleted.\n", event->name );
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

int main(int argc, char const *argv[]){
	
	int res;
	system("touch file.txt");

	res = system("gnome-terminal --geometry 73x20+100+300 -- sh -c 'sudo apt update;rm file.txt; exit; exec bash;'");
	if(res != 0)	handle_error("Unable to launch gnome-terminal");

	
	res = doPolling("/home/lucasmac/Desktop/file.txt");
	if(res != 0)	handle_error("Unable to do polling");
	
	printf("OK!\n");
	
	return 0;
}