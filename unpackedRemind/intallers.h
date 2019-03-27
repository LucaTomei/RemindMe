#include <stdlib.h> // exit
#include <stdio.h>  // perror

/*------------------------------------------------------------------------------------------------------
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                TEMPORARY INSTALLATION
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-------------------------------------------------------------------------------------------------------*/

int res;

void downloadSettingIcon(){
  struct passwd *pw = getpwuid(getuid());
  char *homedir = pw->pw_dir;   // home directory


  char* wget_tmp1 = "wget -bqc https://cdn3.iconfinder.com/data/icons/digital-marketing-2/200/vector_395_20-512.png -O myIcon.png";
  char* wget_tmp2 = append(wget_tmp1, homedir);
  char* wget = append(wget_tmp2, "/myIcon.png");   // l'icona si chiama myIcon.png
  
  res = system(wget);
  if(res != 0)	handle_error("Unable to download Application Icon!");
  
  res = system("tput reset");
  if(res != 0)	handle_error("Unable to clean the screen!");
  sleep(1);
  // writing desktop file
  FILE *f = fopen("remindGui.desktop", "w");
  if (f == NULL) handle_error("Errore nell' apertura del file!");

  char* text = "[Desktop Entry]\nVersion=1.0\nType=Application\nName=remindGui\nExec=";


  // vedo da quale directory si sta lanciato il programma
  char cwd[PATH_MAX];
  char* current_dir = getcwd(cwd, sizeof(cwd));
  if(current_dir == NULL) handle_error("Errore: impossibile sapere qual'è la directory corrente");

  char* exec = append(current_dir, "/remindGui");
  char* icon = append(homedir, "/myIcon.png");


  // continuo con la scrittura del file
  char* text2 = append(text, exec);
  char* text3 = append(text2, "\nIcon=");
  char* result = append(text3, icon);
  
  fprintf(f, "%s", result);
  fclose(f);

  const char* desktopFileInDir = "~/.local/share/applications/remindGui.desktop";

  if(fileExists(desktopFileInDir)){
    res = remove(desktopFileInDir);
    if(res != 0)  handle_error("Unable to remove file in directory");
  }
  char* tmp = append("cp remindGui.desktop ", " ~/.local/share/applications");
  res = system(tmp);
  if(res != 0)	handle_error("Unable to create desktop file of my App");

  res = system("chmod a+x ~/.local/share/applications/remindGui.desktop");
  if(res != 0)	handle_error("Unable to do permission of my icon");
  
  free(tmp);
  free(text2);
  free(text3);
  free(result);
  free(exec);
  free(icon);
  free(wget);
  free(wget_tmp2);
}


void removeAndExit(){
  struct passwd *pw = getpwuid(getuid());
  char *homedir = pw->pw_dir;   // home directory

  // rimozione icona
  res = system("rm ~/.local/share/applications/remindGui.desktop");
  if(res != 0)	handle_error("Unable to remove icon Files");
  
  char* preRemove1 = "rm ";
  char* preRemove2 = append(preRemove1, homedir);
  char* okRemove = append(preRemove2, "/myIcon.png");
  
  res = system(okRemove);
  if(res != 0)	handle_error("Unable to remove icon Files");
  
  char cwd[PATH_MAX];
  char* current_dir = getcwd(cwd, sizeof(cwd));
  if(current_dir == NULL) handle_error("Errore: impossibile sapere qual'è la directory corrente");
  char* removeHere = append("rm ", current_dir);
  char* removeDesktopHere = append(removeHere, "/remindGui.desktop");
  
  res = system(removeDesktopHere);
  if(res != 0)	handle_error("Unable to remove icon Files");
  

  res = system("tput reset");
  if(res != 0)	handle_error("Unable to remove icon Files");
  
  free(removeHere);
  free(removeDesktopHere);
  free(preRemove2);
  free(okRemove);
}

/*------------------------------------------------------------------------------------------------------
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                END  TEMPORARY INSTALLATION
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-------------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------------------
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                          PERMANENT INSTALLATION
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-------------------------------------------------------------------------------------------------------*/


void createDesktopFileIn(char* f, char* icon, char* exe){
  char* text = "[Desktop Entry]\nVersion=1.0\nType=Application\nName=remindGui\nExec=";
  char* exeTmp = append(text, exe);
  char* tmp1 = append(exeTmp, "\nIcon=");
  
  char* res = append(tmp1, icon);
  
  // create desktop file and copy to his folder;
  FILE *file = fopen(f, "w");
  fprintf(file, "%s", res);
  fclose(file);

  free(tmp1);
  free(exeTmp);
  free(res);
}


// create or chek update.conf for verify updates of my app
// first line -> day
// second line -> month
void createOrCheckIfExist(){
  // check for update
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int currDay = tm.tm_mday;
  int currMonth = tm.tm_mon + 1;
  
  FILE* f;

  char store[2];  // store file content

  // check if update file exists
  if(fileExists(mine->updateFile)){ 
    int oldDay, oldMonth;

    f = fopen (mine->updateFile, "r"); 
    
    fscanf (f, "%d", &oldDay);  // line number one - day number
    fscanf (f, "%d", &oldMonth);// line number two - month number

    // If file is too old
    if(!(oldMonth == currMonth) || (currDay -  oldDay >= 15) || (oldDay - currDay >= 15)){
      res = chdir(mine->remindDir);
      if(res != 0)  handle_error("Unable to move to remind directory");
      res = system("gnome-terminal --geometry 60x20+100+300 -- sh -c 'wget -bqc https://github.com/LucaTomei1995/RemindMe/raw/master/unpackedRemind/remindGui -O remindGui;chmod +x remindGui; echo \"Relaunch your application and enjoy for updates!\";sleep 1;exit;exec bash;'");
      if(res != 0)  handle_error("Unable to talk with user");
    }
  }else{  // else i'l write it
    f = fopen(mine->updateFile, "w");

    fprintf(f, "%d\n", currDay);
    fprintf(f, "%d\n", currMonth);
  }

  fclose(f);
}

static void installApplication(){
    
    mine = malloc((8*6)*sizeof(struct config));

    // download .helf directly from my github
    struct passwd *pw = getpwuid(getuid());
    
    
    mine->homedir = append(pw->pw_dir, "/");
    
    char* current_dir = getcwd(NULL, 0);
    
    mine->launchDir = append(current_dir, "/");

    // create variables that stores location containing data of my app
    
    mine->remindDir = append(mine->homedir, ".local/share/applications/RemindMe/");
    mine->exeDir = append(mine->remindDir, "remindGui");
    mine->iconDir = append(mine->remindDir, "remindGui.png");

    char* installDesktop = append(mine->homedir, ".local/share/applications/remindGui.desktop");

    mine->updateFile = append(mine->remindDir, "update.conf");

    // Check if file exists in .local/share/applications
    // I check only if exists .local/share/applications folder: this folder exists only in Ubuntu
    if(!fileExists(mine->remindDir)){
      char* tmp1 = append("mkdir ", mine->remindDir);
      
      res = system(tmp1);
      if(res != 0)  handle_error("unable to create installation folder"); 
      free(tmp1);
    }
    res = chdir(mine->remindDir);
    if(res != 0)  handle_error("Unable to change directory");
    // download helf file
    res = system("wget -bqc https://github.com/LucaTomei1995/RemindMe/raw/master/unpackedRemind/remindGui -O remindGui && chmod +x remindGui");
    if(res != 0)  handle_error("unable to copy");
    // download icon file
    res = system("wget -bqc https://cdn3.iconfinder.com/data/icons/digital-marketing-2/200/vector_395_20-512.png -O remindGui.png");
    if(res != 0)  handle_error("unable to download icon");
    
    // if not exists desktop file - create one for my app
    if(!fileExists(installDesktop))  createDesktopFileIn(installDesktop, mine->iconDir, mine->exeDir);
    
    createOrCheckIfExist();
    
    free(installDesktop);
}

/*------------------------------------------------------------------------------------------------------
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                          END PERMANENT INSTALLATION
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-------------------------------------------------------------------------------------------------------*/