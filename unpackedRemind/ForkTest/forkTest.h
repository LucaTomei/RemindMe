#include <sys/wait.h>
#include <unistd.h>

/*
	Con questo test dimostro che per disabilitare la scocciante finestra di dialogo che resta sempre attiva finché
	non termina la system, conviene:
	* Rimpiazzare la system con execpv e vfork
	* Far eseguire il primo comando al figlio creato dal padre del processo principale
	* E così via

	CONTINUA A CERCARE DI CAPIRE COME FUNZIONANO STI CAZZO DI PROCESSI
*/

void on_response_forkTest(GtkDialog *dialog, gint response_id, gpointer user_data){
	printf("Sono qui\n");
	gtk_widget_destroy(GTK_WIDGET (dialog));
	if(response_id == -5) {
		pid_t pid = vfork();
		if(pid == 0){
			printf("Terzo\n");
			char* cmd[] = {"sudo", "apt", "update", NULL};
			int res = execvp(cmd[0], cmd);
		}else if(pid < 0)	handle_error("None");
		// Il padre non deve fare nulla

	}else printf("Ok Non faccio nulla!\n");
}

void forkTest_Func(GtkButton *button, gpointer   user_data){

	GtkWindow *window = user_data;
  GtkWidget *dialog;    // finestra di dialogo

  GtkWidget *content_area;
  GtkWidget *label;


  gint response_id;

  /*Create the dialog window. Modal windows prevent interaction with other 
  windows in the same application*/
  dialog = gtk_dialog_new_with_buttons ("Automatic ConkyManager Installer", window, GTK_DIALOG_MODAL,  "_OK", GTK_RESPONSE_OK, NULL);
 
  /*Create a label and attach it to the content area of the dialog*/
  content_area = gtk_dialog_get_content_area(GTK_DIALOG (dialog));
  label = gtk_label_new ("");

  gtk_label_set_markup(GTK_LABEL(label),"This is NOT a guide! Do you want to continue?");
  gtk_container_add(GTK_CONTAINER(content_area), label);
  

  /*The main purpose of this is to show dialog's child widget, label*/
  gtk_widget_show_all(dialog);
  
  /*Connecting the "response" signal from the user to the associated
  callback function*/
  g_signal_connect (GTK_DIALOG (dialog), "response", G_CALLBACK (on_response_forkTest), NULL);
}