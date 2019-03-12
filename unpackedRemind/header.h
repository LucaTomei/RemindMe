#include <gtk/gtk.h>
#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <limits.h>

#define BAR "=================================================================="

#define handle_error(msg)\
do{\
  perror(msg);\
  exit(EXIT_FAILURE);\
}while(0)


#define backup_error(msg)\
do{\
  fprintf(stderr, "%s\n", msg);\
  sleep(1);\
  system("tput reset");\
  exit(EXIT_FAILURE);\
}while(0)

typedef struct config{
  char* remindDir;  // 
  char* homedir;    // 
  char* exeDir;
  char* iconDir;
  char* updateFile; //  
  char* launchDir;  // launch directory
}config;

config* mine;

char* append(char* string1, char* string2){
    size_t dim = (strlen(string1)) + (strlen(string2) + 1);
    char *tmp = malloc(dim * sizeof(char));
    strcpy(tmp, string1);
    strcat(tmp, string2);
    return tmp;
}



#include "PreWelcome/pre_welcome.h"
#include "E_liquid/eliquid.h"
#include "AutoBackup/autobackup.h"
#include "SublInstaller/sublInstaller.h"
#include "StartupMain/startupMain.h"
#include "SetIconFunc/sharedExecIcon.h"
#include "gccFunctions/gccInstaller.h"
#include "InstallationsGuide/installGuide.h"
#include "conkyInstaller/conkyInstaller.h"
#include "firstInstallation/firstInstallation.h"
#include "ForkTest/forkTest.h"

void downloadSettingIcon();
void removeAndExit();
static void activate (GtkApplication *app, gpointer user_data);

