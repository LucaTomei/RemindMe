#include <stdlib.h> // exit
#include <stdio.h>  // perror

void on_responsegcc_4Func(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  if(response_id == -5) {
    system("sudo apt-get install gcc-4.8-multilib && ls -la /usr/bin/ | grep -oP \"[\\S]*(gcc|g\\+\\+)(-[a-z]+)*[\\s]\" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f \"/usr/bin/${link}-${0}\" \"/usr/bin/${link}\"; done' 4.8");
  }else printf("Ok Non faccio nulla!\n");
}

void gcc_4Func (GtkButton *button, gpointer   user_data){
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


void on_responsegcc_8Func(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  if(response_id == -5) {
    system("sudo apt-get install gcc-8-multilib && ls -la /usr/bin/ | grep -oP \"[\\S]*(gcc|g\\+\\+)(-[a-z]+)*[\\s]\" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f \"/usr/bin/${link}-${0}\" \"/usr/bin/${link}\"; done' 8");
  }else printf("NO!\n");
}
void gcc_8Func (GtkButton *button, gpointer   user_data){
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