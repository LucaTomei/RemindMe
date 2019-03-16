#include <stdlib.h> // exit
#include <stdio.h>  // perror

void on_responseFirstInstallationFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
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

void firstInstallationFunc (GtkButton *button, gpointer   user_data){
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