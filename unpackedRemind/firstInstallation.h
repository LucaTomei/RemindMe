#include <stdlib.h> // exit
#include <stdio.h>  // perror

GtkWidget *dialog;

void firstInstallationFunc (GtkButton *button, gpointer user_data){
	
	GtkWindow *parent = user_data;
    GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
   
    dialog = gtk_message_dialog_new(parent, flags, 
                                            GTK_MESSAGE_WARNING, 
                                            GTK_BUTTONS_OK_CANCEL, 
                                            "Automatic Software Installer for Unix");

  	
  	GtkResponseType result;
    result = gtk_dialog_run(GTK_DIALOG(dialog));
  
  	if(result == GTK_RESPONSE_OK || result == GTK_RESPONSE_APPLY) {
        gtk_widget_destroy(dialog);
        int ret = ret = system("gnome-terminal --geometry 73x20+100+300 -- sh -c 'sudo apt update;sudo apt upgrade;sudo apt-get install default-jdk;sudo snap install eclipse;sudo apt-get install xpad;sudo apt update;sudo apt upgrade;sudo apt autoremove;sudo apt autoclean;sudo dpkg --configure -a;sudo apt install -f;exit;exec bash'");
    }else gtk_widget_destroy(dialog);
}