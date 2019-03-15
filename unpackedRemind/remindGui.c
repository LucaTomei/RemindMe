#include "header.h"

static void installApplication();

// use strncpy(mine->homedir, "Herp", sizeof(mine->homedir)); to replace char* in data struct


extern config* mine;

int res;


int main(int argc, char *argv[]) {
  //downloadSettingIcon();
  installApplication();
  if(argc == 0)	system("gnome-terminal --geometry 73x20+100+300 -- sh -c 'sudo apt update;exit;exec bash'");
  else system("gnome-terminal --geometry 73x20+100+300 -- sh -c 'sudo ls -l;exit;exec bash'");
  
  printf("%d\n", argc);
  exit(0);
  pre_welcome();
  
  GtkApplication *app;
  int status;
 
  app = gtk_application_new ("org.gtk.remindGuiApp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run(G_APPLICATION (app), argc, argv);
  g_object_unref(app);

  //removeAndExit();
  freeMia();
  return 0;
}

int fileExists(const char* filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)  return 1;
    else  return 0;
}

static void activate (GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *hideXpadIcon;
  GtkWidget *parallelsRes;
  GtkWidget *gcc_4;
  GtkWidget *execIcon;
  GtkWidget *eclipseIcon;
  GtkWidget *firstInstallation;
  GtkWidget *geditSize;
  GtkWidget *gcc_8;
  GtkWidget *xPadResDim;
  GtkWidget *grubDim;
  GtkWidget *x_sharedIcon;
  GtkWidget *startup;
  GtkWidget *autoMain;
  GtkWidget *sublInstaller;
  GtkWidget *autoBackup;
  GtkWidget *e_liquidCalc;
  GtkWidget *installConky;
  GtkWidget *testFork;


  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 350, 250);
  gtk_window_set_title(GTK_WINDOW(window), "Remind Gui App (By LucasMac)");
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);

  vbox = gtk_box_new(TRUE, 1);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  hideXpadIcon = gtk_button_new_with_label("Hide xPad icon");
  parallelsRes = gtk_button_new_with_label("Set Parallels default resolution");
  gcc_4 = gtk_button_new_with_label("gcc-4.8");
  execIcon = gtk_button_new_with_label("Change executable icon");
  eclipseIcon = gtk_button_new_with_label("Set eclipse icon");
  firstInstallation = gtk_button_new_with_label("First Software Installation");
  geditSize = gtk_button_new_with_label("Set Size for Gedit Terminal Plugin");
  gcc_8 = gtk_button_new_with_label("gcc-8 + make");
  xPadResDim = gtk_button_new_with_label("Set xPad resolution and dimentions");
  grubDim = gtk_button_new_with_label("Set grub dimentions");
  x_sharedIcon = gtk_button_new_with_label("Change app/x-sharedlib icon (gcc-8)");
  startup = gtk_button_new_with_label("Set 'startup' for automatic update");
  autoMain = gtk_button_new_with_label("Automatic Main Generator");
  sublInstaller = gtk_button_new_with_label("Sublime_Text Installer");
  autoBackup = gtk_button_new_with_label("Automatic Ubuntu Backup");
  e_liquidCalc = gtk_button_new_with_label("E-Liquid Calculator");
  installConky = gtk_button_new_with_label("Conky Manager Autoinstaller");
  
  testFork = gtk_button_new_with_label("I'm a test");

  gtk_box_pack_start(GTK_BOX(vbox), hideXpadIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), parallelsRes, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), gcc_4, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), execIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), eclipseIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), firstInstallation, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), geditSize, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), gcc_8, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), xPadResDim, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), grubDim, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), x_sharedIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), startup, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), autoMain, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), sublInstaller, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), autoBackup, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), e_liquidCalc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), installConky, TRUE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(vbox), testFork, TRUE, TRUE, 0);


  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);


  // Funzioni di salto
  g_signal_connect (GTK_BUTTON (hideXpadIcon), "clicked",  G_CALLBACK (hideXpadIconDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (parallelsRes), "clicked",  G_CALLBACK (parallelsResDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (gcc_4), "clicked",  G_CALLBACK (gcc_4Func), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (execIcon), "clicked",  G_CALLBACK (execIconFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (eclipseIcon), "clicked",  G_CALLBACK (eclipseIconDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (firstInstallation), "clicked",  G_CALLBACK (firstInstallationFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (geditSize), "clicked",  G_CALLBACK (geditSizeDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (gcc_8), "clicked",  G_CALLBACK (gcc_8Func), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (xPadResDim), "clicked",  G_CALLBACK (xPadResDimDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (grubDim), "clicked",  G_CALLBACK (grubDimDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (x_sharedIcon), "clicked",  G_CALLBACK (x_sharedIconFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (startup), "clicked",  G_CALLBACK (startupFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (autoMain), "clicked",  G_CALLBACK (autoMainFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (sublInstaller), "clicked",  G_CALLBACK (sublInstallerFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (autoBackup), "clicked",  G_CALLBACK (autoBackupFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (e_liquidCalc), "clicked",  G_CALLBACK (e_liquidCalcFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (installConky), "clicked",  G_CALLBACK (installConkyFunc), GTK_WINDOW (window));
  
  g_signal_connect (GTK_BUTTON (testFork), "clicked",  G_CALLBACK (forkTest_Func), GTK_WINDOW (window));

  
  gtk_main();
}


/*------------------------------------------------------------------------------------------------------
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                TEMPORARY INSTALLATION
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-------------------------------------------------------------------------------------------------------*/

void downloadSettingIcon(){
  struct passwd *pw = getpwuid(getuid());
  char *homedir = pw->pw_dir;   // home directory
  
  int res;

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
  
  int res;

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


// create or chef file update.conf for verify updates of my app
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
      res = system("wget -bqc https://github.com/LucaTomei1995/RemindMe/raw/master/unpackedRemind/remindGui -O remindGui && chmod +x remindGui");
      if(res != 0)  handle_error("unable to copy");
      res = system("gnome-terminal --geometry 60x20+100+300 -- sh -c \"printf 'I've installed the latest version. Please reboot the program\n'; exec bash\"");
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

    int res;
    
    // download .helf directly from my github
    struct passwd *pw = getpwuid(getuid());
    
    
    mine->homedir = append(pw->pw_dir, "/");
    
    char* current_dir = getcwd(NULL, 0);
    
    mine->launchDir = append(current_dir, "/");
    /*printf("%s\n", mine->launchDir);
    handle_error("exit successfull");*/

    // create variables thata stores location containing data of my app
    
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