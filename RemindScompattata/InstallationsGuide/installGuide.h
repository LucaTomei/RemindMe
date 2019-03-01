#include <stdlib.h> // exit
#include <stdio.h>  // perror

void on_response (GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
}

void grubDimDialog (GtkButton *button, gpointer   user_data){
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


void xPadResDimDialog (GtkButton *button, gpointer   user_data){
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



void geditSizeDialog (GtkButton *button, gpointer   user_data){
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


void eclipseIconDialog (GtkButton *button, gpointer   user_data){
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


void hideXpadIconDialog (GtkButton *button, gpointer   user_data){
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


void parallelsResDialog (GtkButton *button, gpointer   user_data){
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