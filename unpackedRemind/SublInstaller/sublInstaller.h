#include <stdlib.h> // exit
#include <stdio.h>  // perror

GtkWidget *dialog;
/*void on_responseSublInstallerFunc(GtkDialog *dialog, gint response_id, gpointer user_data){
  gtk_widget_destroy (GTK_WIDGET (dialog));
  char response;
  int ret;
  char cwd[PATH_MAX];	// directory corrente
  char* curr = cwd;		// copia directory corrente
  if (getcwd(cwd, sizeof(cwd)) == NULL) handle_error("Error on read current directory");

  if(response_id == -5) {
    ret = system("wget https://www.dropbox.com/s/9tl1ctd4amlwvtc/sublime_text.tar.gz?dl=0 -O sublime_text.tar.gz");
    if(ret != 0)	handle_error("Error on downloading sublime files!");
    
    ret = system("sudo mkdir /opt/sublime_text");
    if(ret != 0)	handle_error("Error on creating sublime directory!");
    
    ret = system("sudo tar -xzvf sublime_text.tar.gz -C /opt/sublime_text");
    if(ret != 0)	handle_error("Error on extracting files!");

    // Get home directory
    struct passwd *pw = getpwuid(getuid());
    char *homedir = pw->pw_dir;

    ret = system("sudo chmod 777 -R /opt/sublime_text");
    if(ret != 0)	handle_error("Error on permissions!");


    char* chmod = "sudo chmod a+x /opt/sublime_text/sublime_text";       

    ret = system(chmod);
    if(ret != 0)	handle_error("Error on execution permissions!");

    printf("Do You Want to set 'subl' command global in your system? [Y/n]\n");
    scanf("\n%c", &response);
    if(response == 'Y' || response == 'y'){
      char* global = "sudo ln -sv /opt/sublime_text/sublime_text /usr/local/bin/subl";
      ret = system(global);
      if(ret != 0)	handle_error("Error on setting global sublime");
    }
    response = '\0';
    // Create desktop file in home directory
	ret = chdir(homedir);
    if(ret != 0)	handle_error("Error change directory");
    FILE *f = fopen("sublime-text-3.desktop", "w");
    if(f == NULL) handle_error("\n\nImpossibile creare il file in scrittura\n\n");

    char* init_test = "[Desktop Entry]\nVersion=1.0\nType=Application\nName=Sublime Text\nGenericName=Text Editor\nComment=Sophisticated text editor for code, markup and prose\nExec=";
  
    char* subl_folder = "/opt/sublime_text/";
    char* tmp = append(subl_folder, "sublime_text ");
    char* exe_location = append(tmp, "%F\n");

    char* exe_dir = append(init_test, exe_location);
  
    char* tmp_icon = append(exe_dir, "Terminal=false\nMimeType=text/plain;\n");
    char* tmp1 = "Icon=/opt/sublime_text/Icon/256x256/sublime-text.png";
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

    free(exe_location);
    free(tmp);
    free(exe_dir);
    free(tmp_icon);
    free(tmp2);
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
	ret = chdir(homedir);
    if(ret != 0)	handle_error("Error change directory");
    char* copy = "sudo cp sublime-text-3.desktop /usr/share/applications";


    ret = system(copy);
    if(ret != 0)	handle_error("Error on execution permissions!");


    // Remove all files
    system("tput reset");
    system("rm sublime-text-3.desktop");

    printf("Do you want to delete installation file [Y/n]\n");
    scanf("\n%c", &response);
    if(response == 'Y' || response == 'y'){
    	ret = chdir(curr);
    	if(ret != 0)	handle_error("Error on moving!");
    	ret = remove("sublime_text.tar.gz");
    	if(ret != 0)	handle_error("Error on removing file");
    }
  }else printf("Ok Non faccio nulla!\n");

  system("tput reset");
  printf("Go to the app--->\n");
}*/
/*void sublInstallerFunc (GtkButton *button, gpointer   user_data){
  GtkWindow *window = user_data;
  GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
  GtkWidget *dialog;    

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  dialog = gtk_dialog_new_with_buttons ("Sublime Text Installer & Cracker", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);

  
  content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
  \t<b>This is NOT a guide, is an automatic installer</b>\n\n\n\
  \tNow I'm Setting Necessary Files\n\n\
  \t<b>You Must Continue in Terminal View!</b>\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
  gtk_container_add (GTK_CONTAINER (content_area), label);
  
  
  gtk_widget_show_all (dialog);
  
  
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_responseSublInstallerFunc), NULL);

}*/

void sublimeInstaller(){
    int ret;
    // I launch all commands in Launching Directory
    ret = chdir(mine->launchDir);
    if(ret != 0)  handle_error("Unable to change directory");
    ret = system("gnome-terminal --geometry 73x20+100+300 -- sh -c 'sudo mkdir /opt/sublime_text;wget https://www.dropbox.com/s/9tl1ctd4amlwvtc/sublime_text.tar.gz?dl=0 -O sublime_text.tar.gz;sudo tar -xzvf sublime_text.tar.gz -C /opt/sublime_text;sudo chmod 777 -R /opt/sublime_text/;chmod a+x /opt/sublime_text/sublime_text;sudo ln -sv /opt/sublime_text/sublime_text /usr/local/bin/subl;exit;exec bash'");
    if(ret != 0)  handle_error("Error on downloading sublime files!");

    // Create desktop file
}

void sublInstallerFunc (GtkButton *button, gpointer user_data){ // rename it to SublConstructor
    GtkWindow *parent = user_data;
    GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
   
    dialog = gtk_message_dialog_new(parent, /*GTK_DIALOG_MODAL*/flags, 
                                            GTK_MESSAGE_WARNING, 
                                            GTK_BUTTONS_OK_CANCEL, 
                                            "Automatic Sublime Text 3 Installer");
    GtkResponseType result;
    result =  gtk_dialog_run(GTK_DIALOG(dialog));
    
    //gtk_widget_destroy(dialog);
    if(result == GTK_RESPONSE_OK || result == GTK_RESPONSE_APPLY) {
        gtk_widget_destroy(dialog);
        sublimeInstaller();
    }else gtk_widget_destroy(dialog);
}