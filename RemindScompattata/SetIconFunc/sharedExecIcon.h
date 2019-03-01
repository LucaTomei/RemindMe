#include <stdlib.h> // exit
#include <stdio.h>  // perror

void on_responsex_sharedIconFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
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
void x_sharedIconFunc (GtkButton *button, gpointer   user_data){
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

void on_responsegcc_execIconFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
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
void execIconFunc (GtkButton *button, gpointer   user_data){
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