#include <stdlib.h> // exit
#include <stdio.h>  // perror

void on_responseAutoMainFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
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

void autoMainFunc (GtkButton *button, gpointer   user_data){
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

void on_responseStartupFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
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


void startupFunc (GtkButton *button, gpointer   user_data){
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

