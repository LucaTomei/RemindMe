#include "header.h"

int main(int argc, char *argv[]) {
  downloadSettingIcon();
  pre_welcome();
  GtkApplication *app;
  int status;
 
  app = gtk_application_new ("org.gtk.remindGuiApp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  removeAndExit();
  return 0;
}


/* FUNZIONI*/
char* append(char* string1, char* string2){
  size_t dim = (strlen(string1)) + (strlen(string2) + 1);
  char *tmp = malloc(dim * sizeof(char));
    strcpy(tmp, string1);
    strcat(tmp, string2);
    return tmp;
}






static void on_response (GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
}


static void on_responseE_liquidCalcFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  
  if(response_id == -5) {
    // downloading jar from dropbox
    
    system("wget https://www.dropbox.com/s/4xalr9b94btiohs/Siga3.0.jar?dl=0 -O Siga.jar");
    system("mkdir ~/Siga");
    system("cp Siga.jar ~/Siga"); // now siga.jar is in home directory
    system("rm -r Siga.jar"); 
    // Now siga is in home/Siga

    // Download icon
    system("wget https://www.dropbox.com/s/e64omkitsv7z78h/Siga.png?dl=0 -O Siga.png");
    system("cp Siga.png ~/Siga");
    system("rm -r Siga.png");
    // now icon is with jar file in siga directory


    // writing desktop file
      // exe file 
    struct passwd *pw = getpwuid(getuid());
    char *homedir = pw->pw_dir;   // home directory
    char* sigFolder = append(homedir, "/Siga/");
    char* tmp = append(sigFolder, "Siga.jar");
    char* sigEx = append(tmp, "\n");
    free(tmp);
    
      // icon file
    char* sigIcon = append(sigFolder, "Siga.png\n");
    free(sigFolder);

    FILE *f = fopen("Siga.desktop", "w");
    
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    char* text = "[Desktop Entry]\nVersion=1.0\nType=Application\nName=Luca's Siga\nExec=java -jar ";
    char* exe = append(text, sigEx);
    char* exe_png = append(exe, "Icon=");
    char* result = append(exe_png, sigIcon);

    fprintf(f, "%s\n", result);
    fclose(f);  
    system("cp Siga.desktop ~/.local/share/applications");
    system("rm Siga.desktop");
    system("chmod a+x ~/.local/share/applications");

    free(exe);
    free(exe_png);
    free(result);
    free(sigEx);
    free(sigIcon);
  }else printf("Ok Non faccio nulla!\n");
  system("tput reset");
  printf("Go to the app--->\n");
}
static void e_liquidCalcFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("My Java E-Liquid Calculator", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is NOT a guide, is an automatic installer</b>\n\n\n\
  \t\t\t\t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseE_liquidCalcFunc), NULL);

}

static void on_responseAutoBackupFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  printf("\n");
  printf("   +======================================================================+\n"
  "   |                     Automatic Backup for Ubuntu                      |\n"
  "   +======================================================================+\n"
  "   |                  Copyright (C) 2018 Luca Tomei                       |\n"
  "   +----------------------------------------------------------------------+\n"
  "   |\tVersion: 1.0                                                      |\n"
  "   +----------------------------------------------------------------------+\n"
  "   |  This program comes with ABSOLUTELY NO WARRANTY. This is free        |\n"
  "   |  software, and you are welcome to redistribute it under certain      |\n"
  "   |  conditions; for further details, please refer to the GNU General    |\n"
  "   |  Public License provided with this program.                          |\n"
  "   +======================================================================+\n"
  "   +======================================================================+\n\n");

  printf("  +---Description-----------------------------------------------------------+\n");
  printf("  |This program make a backup of all your /home/username directory (incuding|\n");
  printf("  |Desktop folder, Documents folder, Download folder, ...) and also .config |\n");
  printf("  |and .local folder that contains setting of your old installed programs!  |\n");
  printf("  +-------------------------------------------------------------------------+\n");

  if(response_id == -5) {
    printf("\n\nDo you want to proceed?[Y/n]\n");
    char choice;
    scanf("\n%c", &choice);
    if(choice != 'Y' && choice != 'y') backup_error("See you later!");

    int ret;

    // creating backup folder in /home/username/
    struct stat st = {0};
    char* tmp = "/Backup_Folder";

    struct passwd *pw = getpwuid(getuid());
    char *hometmp = pw->pw_dir;
    char* backup_tmp = append(hometmp, tmp);
    char* backup_folder = append(backup_tmp, "/");

    if (stat(backup_folder, &st) == -1) {
      mkdir(backup_folder, 0700);
    }else {
      fprintf(stderr, "Error: There is just a directory with Backup_Folder name in %s!\n", hometmp);
      printf("Do you want to delete de directory for to recreate it?[Y/n]\n");
      scanf("\n%c", &choice);
      if(choice == 'Y' || choice == 'y')  {
        char* rm = append("sudo rm -R ", backup_folder);
        ret = system(rm);
        free(rm);
        mkdir(backup_folder, 0700);
      }else backup_error("Error: I'm closing the program!");
      
    }
    if(ret != 0)  backup_error("Error: Unable to execute command!");
  

    char* homedir = append(hometmp, "/");
    char* path = homedir;
    ret = chdir(path);
    if(ret == -1) backup_error("Error: Unable to move in this directory");


    //  Preparing command
    char* one = append("rsync -avz ", homedir);
    char* space = append(one, " ");
    char* two = append(space, backup_folder);
    char* exclude = " --exclude Backup_Folder --exclude snap --exclude .cache --exclude .conky --exclude .eclipse --exclude .fonts --exclude .gnupg --exclude .java --exclude .mozilla --exclude .parallels --exclude .ssh --exclude .swt --exclude .tooling --exclude .bash_history --exclude .bash_logout --exclude .bashrc --exclude .ICEauthority --exclude .profile --exclude .sudo_as_admin_successful --exclude .wget-hsts";
    char* okGo = append(two, exclude);

    // putting username name for to create archive whit it!
    const char ch = '/';
    char *try = strrchr(hometmp, ch);
    char* userName = try + 1;
    char* aft = append(userName, "Backup.tar.gz Backup_Folder");
    char* back = append("tar -zcvf ", aft);

    char* tm2 = append(okGo, " && ");
    char* letsGo = append(tm2, back);
    system(letsGo);

    printf("\t\n\n\n");
    printf("\tPlease, after the end of terminal activity, before\n");
    printf("\tto close terminal, wait until 'yourUserName.tar.gz'\n");
    printf("\tfile is created in %s!\n\n\n", homedir);
    sleep(2);
    printf("Do you want to cancel 'Backup_Folder' folder?[Y/n]\n");
    scanf("\n%c", &choice);
    if(choice == 'Y' || choice == 'y'){
      system("sudo rm -R Backup_Folder");
      printf("\n\nBye bye my friend!\n");
    }else printf("\n\nBye bye my friend!\n");

    free(tm2);
    free(letsGo);
    free(backup_tmp);
    free(backup_folder);
    free(homedir);
    free(one);
    free(space);
    free(two);
    free(okGo);
    free(aft);
    free(back);

  }else printf("Ok Non faccio nulla!\n");

  system("tput reset");
  printf("Go to the app--->\n");
}
static void autoBackupFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("My Automatic Ubuntu Backup", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is my Automatic Ubuntu Backup App</b>\n\n\n\
  \tNow I'm Setting Necessary Files\n\n\
  \t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseAutoBackupFunc), NULL);

}



static void on_responseSublInstallerFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  char response;
  if(response_id == -5) {
    system("wget https://www.dropbox.com/s/9tl1ctd4amlwvtc/sublime_text.tar.gz?dl=0 -O sublime_text.tar.gz");
    system("mkdir sublime_text");
    system("tar -xzvf sublime_text.tar.gz -C sublime_text");

    struct passwd *pw = getpwuid(getuid());
    char *homedir = pw->pw_dir;

    char* cp = append("cp -R sublime_text ", homedir);      
    char* homeSubl = append(cp, "/");
    system(homeSubl);
    free(cp);
    free(homeSubl); 

    char* chmod1 = append("chmod a+x ", homedir);
    char* chmod = append(chmod1, "/sublime_text/sublime_text");         

    system(chmod);
    free(chmod1);
    free(chmod);

    printf("Do You Want to set 'subl' command global in your system? [Y/n]\n");
    scanf("\n%c", &response);
    if(response == 'Y' || response == 'y'){
      char* global = append("sudo ln -sv ", homedir);
      char* global_subl = append(global, "/sublime_text/sublime_text /usr/local/bin/subl");
      system(global_subl);
      free(global);
      free(global_subl);
    }
    response = '\0';
    // Create desktop file
    FILE *f = fopen("sublime-text-3.desktop", "w");
    if(f == NULL) handle_error("\n\nImpossibile creare il file in scrittura\n\n");

    char* init_test = "[Desktop Entry]\nVersion=1.0\nType=Application\nName=Sublime Text\nGenericName=Text Editor\nComment=Sophisticated text editor for code, markup and prose\nExec=";
  
    char* subl_folder = append(homedir, "/sublime_text/");  
    char* tmp = append(subl_folder, "sublime_text ");
    char* exe_location = append(tmp, "%F\n");

    char* exe_dir = append(init_test, exe_location);
  
    char* tmp_icon = append(exe_dir, "Terminal=false\nMimeType=text/plain;\n");
    char* ttt = append("Icon=", homedir);
    char* subl_folder1 = append(ttt, "/sublime_text/");   
    char* tmp1 = append(subl_folder1, "Icon/256x256/sublime-text.png");
    char* icon_location = append(tmp1, "\n");
    char* exe_icon = append(tmp_icon, icon_location);

    char* post_one = append(exe_icon, "Categories=TextEditor;Development;\nStartupNotify=true\nActions=Window;Document;\n\n[Desktop Action Window]\nName=New Window\nStartupWMClass=subl\nExec=");

    char* tmp2 = append(subl_folder, "sublime_text ");
    char* exe_post = append(tmp2, "-n\n");
    char* post_exe = append(post_one, exe_post);
    char* o = append(post_exe, "OnlyShowIn=Unity;\n\n[Desktop Action Document]\nName=New File\nExec=");

    char* exe = append(subl_folder, "sublime_text");
    char* quasi_fatto = append(o, exe);

    char* fileOK  = append(quasi_fatto, " --command new_file\nOnlyShowIn=Unity;\n");
  
    fprintf(f, "%s\n", fileOK);
    fclose(f);

    free(subl_folder);
    free(exe_location);
    free(tmp1);
    free(tmp);
    free(exe_dir);
    free(tmp_icon);
    free(ttt);
    free(tmp2);
    free(subl_folder1);
    free(icon_location);
    free(exe_icon);
    free(post_one);
    free(exe_post);
    free(post_exe);
    free(o);
    free(exe);
    free(quasi_fatto);
    free(fileOK);

    // copy desktop file in location
    char* copy = "cp sublime-text-3.desktop ";
    char* homedir1 = append(copy, pw->pw_dir);
    char* local = append(homedir1, "/.local/share/applications/");
    system(local);
    free(homedir1);
    free(local);

    // Remove all files
    system("tput reset");
    system("rm -R sublime_text");
    system("rm sublime_text.desktop");
    system("rm sublime_text.tar.gz");
    printf("Do you want to delete installation file [Y/n]\n");
    
    scanf("\n%c", &response);
    if(response == 'y' || response == 'Y')  system("rm sublime_installer");
    else  exit(EXIT_SUCCESS);
  }else printf("Ok Non faccio nulla!\n");

  system("tput reset");
  printf("Go to the app--->\n");
}
static void sublInstallerFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Sublime Text Installer & Cracker", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is NOT a guide, is an automatic installer</b>\n\n\n\
  \tNow I'm Setting Necessary Files\n\n\
  \t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseSublInstallerFunc), NULL);

}


static void on_responseAutoMainFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  char response;
  if(response_id == -5) {
    system("wget 'https://www.dropbox.com/s/hcxc0eod6sx7z5i/main_vers_3.c?dl=0' -O main.c");
    system("gcc -o main main.c");
    printf("Do you want to set this file global in your system?  (Y/N)");
    scanf("\n%c", &response);
    if(response == 'Y' || response == 'y') system("sudo cp main /usr/local/bin && sudo rm -r main main.c");
    else system("sudo rm -r main.c");
  }else printf("Ok Non faccio nulla!\n");

  system("tput reset");
  printf("Go to the app--->\n");
}
static void autoMainFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("My Automatic Main Generator", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is NOT a guide, is an automatic installer</b>\n\n\n\
  \tNow I'm Setting Necessary Files\n\n\
  \t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseAutoMainFunc), NULL);

}

static void on_responseStartupFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  char response;
  if(response_id == -5) {
    system("wget 'https://www.dropbox.com/s/mospp3iiyc18zad/avvio_no_process.c?dl=0' -O avvio.c");
    system("gcc -o startup avvio.c");
    printf("Do you want to set this file global in your system?  (Y/N)");
    scanf("\n%c", &response);
    if(response == 'Y' || response == 'y') system("sudo cp startup /usr/local/bin && sudo rm -r startup avvio.c");
    else system("sudo rm -r avvio.c");
  }else printf("Ok Non faccio nulla!\n");

  system("tput reset");
  printf("Go to the app--->\n");
}
static void startupFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("My Startup Application", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is NOT a guide, is an automatic installer</b>\n\n\n\
  \tNow I'm Setting the automatic startup program and\n\
  \tI'm calling it 'startup'\n\n\
  \t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseStartupFunc), NULL);

}


static void on_responsex_sharedIconFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  char response;
  char* name;
  char link[300];
  char *wget_temp, *wget;
  if(response_id == -5) {
      printf("Do you Want to set different icon?[Y/n]\n");
      scanf("\n%c", &response);
      if(response == 'y' || response == 'Y'){
        printf("\n\nPaste the link above of your desiderate png icon\n");
        scanf("%s", link);
        wget_temp = append("wget ", link);
        wget = append(wget_temp, " -O application-x-sharedlib.png");
        system(wget); // scarico l'icona
        system("sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-sharedlib.png");
      }else{
        printf("Automatic Icon Setting\n\n");
        system("sleep 1");
        system("wget http://icons.iconarchive.com/icons/ph03nyx/super-mario/256/Retro-Flower-Fire-2-icon.png -O application-x-executable.png");
        system("sudo cp application-x-executable.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-executable.png");
        system("tput reset");
        printf("Go to the app--->\n");
      }
  }else printf("Ok Non faccio nulla!\n");
  system("tput reset");
  printf("Go to the app--->\n");
}
static void x_sharedIconFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Change x-sharedlib Icon (Gcc-8)", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is NOT a guide, is an automatic installer</b>\n\n\n\
  \t<b>NOTE:</b>\n\
  \tIf you want to set a different icon plese insert 'Y' and paste the link\n\
  \tabove, else press any key and wait for installation\n\n\
  \t\t\t\t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responsex_sharedIconFunc), NULL);

}


static void grubDimDialog (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Set Grub Resolution on Boot", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  
  label = gtk_label_new ("");
  gtk_label_set_markup(GTK_LABEL(label), "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is only a guide:</b>\n\
  \tTo set default boot resolution for grub:\n\
  \t1) Navigate into /etc/default\n\
  \t2) Edit 'grub' file with a text editor\n\
  \t3) Uncomment 25 line and paste this GRUB_GFXMODE=1440x900\n\
  \t4) Ran sudo update-grub\n\
  \t5) Reboot the system\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_response), NULL);

}

static void xPadResDimDialog (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Set Size for Xpad Note", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  
  label = gtk_label_new ("");
  gtk_label_set_markup(GTK_LABEL(label), "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is only a guide:</b>\n\
  \tIf you want to set the resolutive size of the xPad note or its dimentions:\n\
  \t1) Go into /config/xpad\n\
  \t2) Edit with gedit 'info-***' file\n\
  \t<b>N.B.</b>: If you want to set its position on the top right of the screen, you'll edit the file like this:\
  \n\n\t\t\t------------------------CODE------------------------\n\
  \t\t\t\twidth 290\n\
  \t\t\t\theight 215\n\
  \t\t\t\tx 1164\n\
  \t\t\t\ty 27\n\
  \t\t\t\tfollow_font 1\n\
  \t\t\t\tfollow_color 1\n\
  \t\t\t\tsticky 1\n\
  \t\t\t\thidden 0\n\
  \t\t\t\tback rgb(255,238,153)\n\
  \t\t\t\ttext rgb(0,0,0)\n\
  \t\t\t\tontname Sans 10\n\
  \t\t\t\tcontent content-MG38HZ\n\
  \t\t\t--------------------END OF CODE-------------------\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_response), NULL);

}




static void on_responsegcc_8Func(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  if(response_id == -5) {
    system("sudo apt-get install gcc-8-multilib && ls -la /usr/bin/ | grep -oP \"[\\S]*(gcc|g\\+\\+)(-[a-z]+)*[\\s]\" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f \"/usr/bin/${link}-${0}\" \"/usr/bin/${link}\"; done' 8");
  }else printf("NO!\n");
}
static void gcc_8Func (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Install gcc-8-multilib and set it as default gcc", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"This is NOT a guide! Do you want to continue? (OK/x)");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responsegcc_8Func), NULL);

}



static void geditSizeDialog (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Set Size For Gedit Terminal Plugin", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  
  label = gtk_label_new ("");
  gtk_label_set_markup(GTK_LABEL(label), "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is only a guide:</b>\n\
  \tIf you wish to set the resolutive size of the gedit terminal, you'll have to:\n\
  \t1) Go into /usr/lib/x86_64-linux-gnu/gedit/plugins\n\
  \t2) Modify with sudo terminal.py file\n\
  \t3) Set at line 53 ---> self.set_size_request(200, 100)\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_response), NULL);

}



static void on_responseFirstInstallationFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  char response;
  if(response_id == -5) {
      system("sudo apt update && sudo apt upgrade && sudo apt autoremove");
      system("tput reset");
      printf("Do you want to install all necessary files (Y/n)\n");
      scanf("\n%c", &response);
      if(response == 'Y' || response == 'y'){
        system("sleep 2");
        system("sudo apt-get install default-jdk && sudo snap install eclipse && sudo apt-get install xpad && sudo apt update && sudo apt upgrade && sudo apt autoremove && sudo apt autoclean && sudo dpkg --configure -a && sudo apt-get install -f");  
      }else{
        printf("Ok Non faccio nulla!\n");
      }
  }else printf("Ok Non faccio nulla!\n");
}
static void firstInstallationFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("First Software Automatic Installer", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is NOT a guide, is an automatic installer.</b>\n\nDo You Want to Continue?(OK/x)\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseFirstInstallationFunc), NULL);

}


static void eclipseIconDialog (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Set Eclipse Oxygen Icon", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  
  label = gtk_label_new ("");
  gtk_label_set_markup(GTK_LABEL(label), "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is only a guide:</b>\n\
  \tTo set eclipse icon:\n\
  \t1) Create 'eclipse.desktop' file in '.local/share/applications'\n\
  \t2) Write this into eclipse.desktop file this code:\n\
  \t\t\t------------------------CODE------------------------\n\
  \t\t\t\t[Desktop Entry]\n\t\t\t\tVersion=1.0\n\t\t\t\tName=Eclipse\n\t\t\t\tComment=Eclipse\n\t\t\t\tExec=/home/lucasmac/eclipse/java-oxygen/eclipse/eclipse\n\t\t\t\tIcon=/home/lucasmac/eclipse/java-oxygen/eclipse/icon.xpm\n\t\t\t\tTerminal=false\n\t\t\t\tType=Application\n\t\t\t\tCategories=Utility;Application;\n\
  \t\t\t--------------------END OF CODE-------------------\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_response), NULL);

}



static void on_responsegcc_execIconFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  char* name;
  char response;
  char link[300];
  char *wget_temp, *wget;
  if(response_id == -5) {
      printf("Do you Want to set different icon?[Y/n]\n");
      scanf("\n%c", &response);
      if(response == 'y' || response == 'Y'){
        printf("\n\nPaste the link above of your desiderate png icon\n");
        scanf("%s", link);
        wget_temp = append("wget ", link);
        wget = append(wget_temp, " -O application-x-executable.png");
        system(wget); // scarico l'icona
        system("sudo cp application-x-executable.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-executable.png");
      }else{
        printf("Automatic Icon Setting\n\n");
        system("sleep 1");
        system("wget http://icons.iconarchive.com/icons/ph03nyx/super-mario/256/Retro-Flower-Fire-2-icon.png -O application-x-executable.png");
        system("sudo cp application-x-executable.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-executable.png");
      }
  }else printf("Ok Non faccio nulla!\n");
}
static void execIconFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Install gcc-4.8 and set it as default gcc", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \tThis is NOT a guide, is an automatic installer\n\n\n\
  \t<b>NOTE:</b>\n\
  \tIf you want to set a different icon plese insert 'Y' and paste the link\n\
  \tabove, else press any key and wait for installation\n\n\
  \t\t\t\t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responsegcc_execIconFunc), NULL);

}



static void on_responsegcc_4Func(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  if(response_id == -5) {
    system("sudo apt-get install gcc-4.8-multilib && ls -la /usr/bin/ | grep -oP \"[\\S]*(gcc|g\\+\\+)(-[a-z]+)*[\\s]\" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f \"/usr/bin/${link}-${0}\" \"/usr/bin/${link}\"; done' 4.8");
  }else printf("Ok Non faccio nulla!\n");
}
static void gcc_4Func (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Install gcc-4.8 and set it as default gcc", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"This is NOT a guide! Do you want to continue? (OK/x)");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responsegcc_4Func), NULL);

}

static void hideXpadIconDialog (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Hyde xPad Icon", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  
  label = gtk_label_new ("");
  gtk_label_set_markup(GTK_LABEL(label), "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is only a guide:</b>\n\
  \tTo hide xPad icon\n\
  \t1) Go into .config/xpad and edit 'default-style'\n\
  \t2) Set 1 for hide_from_taskbar\n\
  \t3) Set 1 for hide_from_switcher\n\n\
  \t<b>NOTE: These values ​​were previously set to 0</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_response), NULL);

}


static void parallelsResDialog (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Set Parallels 1440x900 Resolution", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is a guide:</b>\n\
  \tTo set default boot resolution for parallels driver:\n\
  \t1)  First install parallels-tool\n\
  \t2)  Then go into /usr/share/X11/xorg.conf.d\n\
  \t3) Open file '40-prltools.conf'\n\
  \t4) Modify voice Modes in # Parallels Screen section setting it into '1440x900'\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_response), NULL);

}



static void on_responseInstallConkyFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  if(response_id == -5) {
    // Download in this folder
	system("wget http://de.archive.ubuntu.com/ubuntu/pool/main/c/coreutils/realpath_8.26-3ubuntu4_all.deb -O realPath.deb");
	system("sudo dpkg -i realPath.deb");

	system("wget https://launchpad.net/~teejee2008/+archive/ubuntu/ppa/+files/conky-manager_2.4~136~ubuntu16.04.1_amd64.deb -O conkyManager.deb");
	
	system("sudo apt install gdebi");
	system("sudo gdebi conkyManager.deb");
	
	// end download & installation

	system("timeout -k 1s 1s conky-manager");				
	
	char cwd[PATH_MAX];
  	char* current_dir = getcwd(cwd, sizeof(cwd));
  	if(current_dir == NULL)	handle_error("Errore: Impossibile ricavare la directory in uso!");

	struct passwd* pw = getpwuid(getuid());
	char* tmp = pw->pw_dir;
	char* homefolder = append(tmp, "/");

	char* conkydir = append(homefolder,".conky/TeejeeTech/");
	int ret = chdir(conkydir);
	if(ret == -1) handle_error("Errore: Impossibile cambiare directory!");
	
	
	ret = unlink("Process Panel");
	if(ret == -1) printf("\n\nImpossibile Eliminare il file Process Panel!\n\n");


	char* txt = "# **********************************************************************\n\
# \"CPU Panel (8-core)\" theme for Conky by LucaTomei\n\
#\n\
# Webpage: In progress!!!\n\
# **********************************************************************\n\n\
background yes\n\
double_buffer yes\n\n\
alignment bottom_left\n\n\
border_width 1\n\
cpu_avg_samples 2\n\
default_color white\n\
default_outline_color white\n\
default_shade_color white\n\
draw_borders no\n\
draw_graph_borders yes\n\
draw_outline no\n\
draw_shades no\n\n\
gap_x 1250\n\
gap_y 15\n\
net_avg_samples 2\n\
no_buffers yes\n\
out_to_console no\n\
out_to_stderr no\n\
extra_newline no\n\n\
own_window yes\n\
own_window_type normal\n\
own_window_transparent yes\n\
own_window_colour 000000\n\
own_window_argb_visual no\n\
own_window_argb_value 0\n\
own_window_hints undecorated,below,sticky,skip_taskbar,skip_pager\n\n\
minimum_size 170 0\n\
stippled_borders 0\n\
update_interval 2.0\n\
uppercase no\n\
use_spacer none\n\n\
show_graph_scale no\n\
show_graph_range no\n\n\
use_xft yes\n\
xftalpha 0.1\n\
xftfont Droid Sans:size=10\n\
color0 white\n\
color1 EAEAEA\n\
color2 FFA300\n\
color3 grey\n\n\
TEXT\n\
${color2}CPU ${color0}${alignr}${cpu cpu0}%\n\
${cpubar cpu0 5,}\n\
${top name 1} $alignr ${top cpu 1}%\n\
${top name 2} $alignr ${top cpu 2}%\n\
${top name 3} $alignr ${top cpu 3}%\n\
${top name 4} $alignr ${top cpu 4}%\n\
${top name 5} $alignr ${top cpu 5}%\n\n\
${color2}RAM ${color0}${alignr}${mem}\n\
${membar 5,}\n\
${top_mem name 1} $alignr ${top_mem mem_res 1}\n\
${top_mem name 2} $alignr ${top_mem mem_res 2}\n\
${top_mem name 3} $alignr ${top_mem mem_res 3}\n\
${top_mem name 4} $alignr ${top_mem mem_res 4}\n\
${top_mem name 5} $alignr ${top_mem mem_res 5}\n";

	FILE* f = fopen("Process Panel", "w");
	if(f == NULL)	handle_error("\n\nImpossibile aprire il file in scrittura\n\n");
	fprintf(f, "%s", txt);

	
	// create desktop file for startup
	char* tmp1 = append(homefolder, ".config/autostart");
	ret = chdir(tmp1);
	if(ret == -1) handle_error("Errore: Impossibile cambiare directory!");
	char* desktopStartup = "[Desktop Entry]\nType=Application\nExec=sh \"";
	char* tmp2 = append(desktopStartup, homefolder);
	char* tmp3 = append(tmp2, ".conky/conky-startup.sh\"\n");
	char* continua = append(tmp3, "Hidden=false\nNoDisplay=false\nX-GNOME-Autostart-enabled=true\nName[en_IN]=Conky\nName=Conky\nComment[en_IN]=\nComment=");
	FILE* f2 = fopen("conky.desktop", "w");
	if(f2 == NULL)	handle_error("\n\nImpossibile aprire il file in scrittura\n\n");
	fprintf(f2, "%s", continua);



	// create sh file
	char* conf = append(homefolder, ".conky/");
	ret = chdir(conf);
	if(ret == -1) handle_error("\n\nErrore: Impossibile cambiare directory!\n\n");
	
	char* startupInConfig = "sleep 10s\nkillall conky\ncd \"";
	char* tmp5 = append(startupInConfig, homefolder);
	char* tmp6 = append(tmp5, ".conky/TeejeeTech\"\nconky -c \"");
	char* tmp7 = append(tmp6, homefolder);
	char* cont = append(tmp7, ".conky/TeejeeTech/Process Panel\" &");
	
	FILE* f3 = fopen("conky-startup.sh", "w");

	if(f3 == NULL)	handle_error("\n\nImpossibile aprire il file in scrittura\n\n");
	fprintf(f3, "%s", cont);
	
	// remove all files
	system("timeout -k 1s 1s conky-manager");
  	int returnToMyDir = chdir(current_dir);
  	if(returnToMyDir == -1) handle_error("\n\nErrore: Impossibile cambiare directory!\n\n");

  	char* conkyManDeb = "conkyManager.deb";
  	char* realPathDeb = "realPath.deb";

  	ret = unlink(conkyManDeb);
  	if(ret == -1)	printf("\n\nImpossibile Eliminare il file conkyManager.deb!\n\n");
  	ret = unlink(realPathDeb);
  	if(ret == -1)	printf("\n\nImpossibile Eliminare il file realPath.deb!\n\n");


	
	free(conkydir);
	free(homefolder);
	free(tmp1);
	free(tmp2);
	free(tmp3);
	free(conf);
	free(tmp5);	
	free(tmp6);
	free(tmp7);
	free(cont);
	free(continua);
	fclose(f);
	fclose(f2);
	fclose(f3);
  }else printf("Ok Non faccio nulla!\n");
  system("tput reset");
  printf("Go to the app--->\n");
}
static void installConkyFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Automatic ConkyManager Installer", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"This is NOT a guide! Do you want to continue?");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all (dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseInstallConkyFunc), NULL);

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




  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);


  // MIEI
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

  
  gtk_main();
}

void downloadSettingIcon(){
  struct passwd *pw = getpwuid(getuid());
  char *homedir = pw->pw_dir;   // home directory
  

  char* wget_tmp1 = "wget -bqc https://cdn3.iconfinder.com/data/icons/digital-marketing-2/200/vector_395_20-512.png -O ";
  char* wget_tmp2 = append(wget_tmp1, homedir);
  char* wget = append(wget_tmp2, "/myIcon.png");   // l'icona si chiama myIcon.png
  
  system(wget);
  system("tput reset");
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


  system("cp remindGui.desktop ~/.local/share/applications");
  
  system("chmod a+x ~/.local/share/applications/remindGui.desktop");
  
  
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
  system("rm ~/.local/share/applications/remindGui.desktop");
  char* preRemove1 = "rm ";
  char* preRemove2 = append(preRemove1, homedir);
  char* okRemove = append(preRemove2, "/myIcon.png");
  system(okRemove);

  char cwd[PATH_MAX];
  char* current_dir = getcwd(cwd, sizeof(cwd));
  if(current_dir == NULL) handle_error("Errore: impossibile sapere qual'è la directory corrente");
  char* removeHere = append("rm ", current_dir);
  char* removeDesktopHere = append(removeHere, "/remindGui.desktop");
  system(removeDesktopHere);
  
  system("tput reset");
  free(removeHere);
  free(removeDesktopHere);
  free(preRemove2);
  free(okRemove);
}