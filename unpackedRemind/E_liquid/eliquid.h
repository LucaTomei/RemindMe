#include <stdlib.h> // exit
#include <stdio.h>  // perror

void on_responseE_liquidCalcFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
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
void e_liquidCalcFunc (GtkButton *button, gpointer   user_data){
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