#include <stdlib.h> // exit
#include <stdio.h>  // perror

int ret;

void on_responseAutoBackupFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
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
        if(ret != 0)	handle_error("Unable to remove files");

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
   	ret = system(letsGo);
   	if(ret != 0)	handle_error("Unable to create tar file containing your backup");

    printf("\t\n\n\n");
    printf("\tPlease, after the end of terminal activity, before\n");
    printf("\tto close terminal, wait until 'yourUserName.tar.gz'\n");
    printf("\tfile is created in %s!\n\n\n", homedir);
    sleep(2);
    printf("Do you want to cancel 'Backup_Folder' folder?[Y/n]\n");
    scanf("\n%c", &choice);
    if(choice == 'Y' || choice == 'y'){
      ret = system("sudo rm -R Backup_Folder");
      if(ret != 0)	handle_error("Unable to remove Backup_Folder");
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

  ret = system("tput reset");
  if(ret != 0)	handle_error("Unable the refresh screen");
  
  printf("Go to the app--->\n");
}
void autoBackupFunc (GtkButton *button, gpointer   user_data){
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