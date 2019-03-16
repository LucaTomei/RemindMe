#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <time.h>



#define BAR "=================================================================="

void pre_welcome(){
  system("tput reset");
  system("echo \033[41mThese scripts are made by:\033[0m");
  system("tput sgr0");
  system("tput setaf 2");
  system("tput blink");
  printf("\n\n\n");
  printf("###                 ###           ###     ################     ###############\n");
  printf("###                 ###           ###    #################    ###           ###\n");
  printf("###                 ###           ###   ###                   ###           ###\n");
  printf("###                 ###           ###   ###                   ###           ###\n");
  printf("###                 ###           ###   ###                   #################\n");
  printf("###                 ###           ###   ###                   ####LUCAS'MAC####\n");
  printf("###                 ###           ###   ###                   ###           ###\n");
  printf("###                 ###           ###   ###                   ###           ###\n");
  printf("###                 ###           ###   ###                   ###           ###\n");
  printf("################     ##############      #################    ###           ###\n");
  printf("################      ###########         ################   ####           ####\n\n\n\n");
  
  system("tput sgr0");

  printf("\n\n\n\n\n");
  

  system("tput setaf 6");
  int BAR_WIDTH = 60;
  unsigned int percentage=0;
  while(percentage<100){
    ++percentage;
    unsigned int lbar=percentage*BAR_WIDTH/100;
    unsigned int rbar=BAR_WIDTH-lbar;
    printf("\r[%.*s%*s] %d%% Completed.", lbar, BAR, rbar, "", percentage);
    fflush(stdout);
    nanosleep((const struct timespec[]){{0, 30000000L}}, NULL);

  }
  printf("\n");
  system("tput sgr0");
  system("tput reset");
} 
