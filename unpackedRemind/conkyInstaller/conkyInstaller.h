#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <sys/wait.h>
#include <unistd.h>

extern config* mine;

GtkWidget *dialog;    // finestra di dialogo


void on_responseInstallConkyFunc(GtkDialog *dialog, gint response_id, gpointer user_data){


	//sleep(10);
    /*
	system("wget http://de.archive.ubuntu.com/ubuntu/pool/main/c/coreutils/realpath_8.26-3ubuntu4_all.deb -O realPath.deb");
	system("sudo dpkg -i realPath.deb");

	system("wget https://launchpad.net/~teejee2008/+archive/ubuntu/ppa/+files/conky-manager_2.4~136~ubuntu16.04.1_amd64.deb -O conkyManager.deb");
	
	system("sudo apt install gdebi");
	system("sudo gdebi conkyManager.deb");
	
	// end download & installation

	system("timeout -k 1s 1s conky-manager");				
	
	char cwd[PATH_MAX];
  	char* current_dir = getcwd(cwd, sizeof(cwd));
  	if(current_dir == NULL)	handle_error("Errore: Impossibile ricavare la directory in uso!");

	struct passwd* pw = getpwuid(getuid());
	char* tmp = pw->pw_dir;
	char* homefolder = append(tmp, "/");

	char* conkydir = append(homefolder,".conky/TeejeeTech/");
	int ret = chdir(conkydir);
	if(ret == -1) handle_error("Errore: Impossibile cambiare directory!");
	
	
	ret = unlink("Process Panel");
	if(ret == -1) printf("\n\nImpossibile Eliminare il file Process Panel!\n\n");


	char* txt = "# **********************************************************************\n\
# \"CPU Panel (8-core)\" theme for Conky by LucaTomei\n\
#\n\
# Webpage: In progress!!!\n\
# **********************************************************************\n\n\
background yes\n\
double_buffer yes\n\n\
alignment bottom_left\n\n\
border_width 1\n\
cpu_avg_samples 2\n\
default_color white\n\
default_outline_color white\n\
default_shade_color white\n\
draw_borders no\n\
draw_graph_borders yes\n\
draw_outline no\n\
draw_shades no\n\n\
gap_x 1250\n\
gap_y 15\n\
net_avg_samples 2\n\
no_buffers yes\n\
out_to_console no\n\
out_to_stderr no\n\
extra_newline no\n\n\
own_window yes\n\
own_window_type normal\n\
own_window_transparent yes\n\
own_window_colour 000000\n\
own_window_argb_visual no\n\
own_window_argb_value 0\n\
own_window_hints undecorated,below,sticky,skip_taskbar,skip_pager\n\n\
minimum_size 170 0\n\
stippled_borders 0\n\
update_interval 2.0\n\
uppercase no\n\
use_spacer none\n\n\
show_graph_scale no\n\
show_graph_range no\n\n\
use_xft yes\n\
xftalpha 0.1\n\
xftfont Droid Sans:size=10\n\
color0 white\n\
color1 EAEAEA\n\
color2 FFA300\n\
color3 grey\n\n\
TEXT\n\
${color2}CPU ${color0}${alignr}${cpu cpu0}%\n\
${cpubar cpu0 5,}\n\
${top name 1} $alignr ${top cpu 1}%\n\
${top name 2} $alignr ${top cpu 2}%\n\
${top name 3} $alignr ${top cpu 3}%\n\
${top name 4} $alignr ${top cpu 4}%\n\
${top name 5} $alignr ${top cpu 5}%\n\n\
${color2}RAM ${color0}${alignr}${mem}\n\
${membar 5,}\n\
${top_mem name 1} $alignr ${top_mem mem_res 1}\n\
${top_mem name 2} $alignr ${top_mem mem_res 2}\n\
${top_mem name 3} $alignr ${top_mem mem_res 3}\n\
${top_mem name 4} $alignr ${top_mem mem_res 4}\n\
${top_mem name 5} $alignr ${top_mem mem_res 5}\n";

	FILE* f = fopen("Process Panel", "w");
	if(f == NULL)	handle_error("\n\nImpossibile aprire il file in scrittura\n\n");
	fprintf(f, "%s", txt);

	
	// create desktop file for startup
	char* tmp1 = append(homefolder, ".config/autostart");
	ret = chdir(tmp1);
	if(ret == -1) handle_error("Errore: Impossibile cambiare directory!");
	char* desktopStartup = "[Desktop Entry]\nType=Application\nExec=sh \"";
	char* tmp2 = append(desktopStartup, homefolder);
	char* tmp3 = append(tmp2, ".conky/conky-startup.sh\"\n");
	char* continua = append(tmp3, "Hidden=false\nNoDisplay=false\nX-GNOME-Autostart-enabled=true\nName[en_IN]=Conky\nName=Conky\nComment[en_IN]=\nComment=");
	FILE* f2 = fopen("conky.desktop", "w");
	if(f2 == NULL)	handle_error("\n\nImpossibile aprire il file in scrittura\n\n");
	fprintf(f2, "%s", continua);



	// create sh file
	char* conf = append(homefolder, ".conky/");
	ret = chdir(conf);
	if(ret == -1) handle_error("\n\nErrore: Impossibile cambiare directory!\n\n");
	
	char* startupInConfig = "sleep 10s\nkillall conky\ncd \"";
	char* tmp5 = append(startupInConfig, homefolder);
	char* tmp6 = append(tmp5, ".conky/TeejeeTech\"\nconky -c \"");
	char* tmp7 = append(tmp6, homefolder);
	char* cont = append(tmp7, ".conky/TeejeeTech/Process Panel\" &");
	
	FILE* f3 = fopen("conky-startup.sh", "w");

	if(f3 == NULL)	handle_error("\n\nImpossibile aprire il file in scrittura\n\n");
	fprintf(f3, "%s", cont);
	
	// remove all files
	system("timeout -k 1s 1s conky-manager");
  	int returnToMyDir = chdir(current_dir);
  	if(returnToMyDir == -1) handle_error("\n\nErrore: Impossibile cambiare directory!\n\n");

  	char* conkyManDeb = "conkyManager.deb";
  	char* realPathDeb = "realPath.deb";

  	ret = unlink(conkyManDeb);
  	if(ret == -1)	printf("\n\nImpossibile Eliminare il file conkyManager.deb!\n\n");
  	ret = unlink(realPathDeb);
  	if(ret == -1)	printf("\n\nImpossibile Eliminare il file realPath.deb!\n\n");

	
	free(conkydir);
	free(homefolder);
	free(tmp1);
	free(tmp2);
	free(tmp3);
	free(conf);
	free(tmp5);	
	free(tmp6);
	free(tmp7);
	free(cont);
	free(continua);
	fclose(f);
	fclose(f2);
	fclose(f3);*/


	
/*  else printf("Ok Non faccio nulla!\n");
  system("tput reset");
  printf("Go to the app--->\n");
*/
	//gtk_widget_destroy (GTK_WIDGET (dialog));
}


void installConkyFunc(GtkButton *button, gpointer user_data){
	
   	GtkWindow *parent = user_data;
   	GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
   
   	dialog = gtk_message_dialog_new(parent, /*GTK_DIALOG_MODAL*/flags, 
                                            GTK_MESSAGE_WARNING, 
                                            GTK_BUTTONS_OK_CANCEL, 
                                            "Automatic ConkyManager Installer");
   	GtkResponseType result;
   	result =  gtk_dialog_run(GTK_DIALOG(dialog));
   	
   	int res;
   	//gtk_widget_destroy(dialog);
   	if(result == GTK_RESPONSE_OK || result == GTK_RESPONSE_APPLY) {

   	 	gtk_widget_destroy(dialog);
   	 	
   	 	// now i launch commands directly from another terminal
   	 	res = chdir(mine->launchDir);
   	 	if(res != 0)	handle_error("Unable  to move to directory");
   	 	// download and install realpath
   	 	
   	 	FILE* f4 = fopen("test.sh", "w");
	   	char* str = "#!/bin/sh\ngnome-terminal --geometry 73x20+100+300 -- sh -c 'wget http://de.archive.ubuntu.com/ubuntu/pool/main/c/coreutils/realpath_8.26-3ubuntu4_all.deb -O realPath.deb; sudo dpkg -i realPath.deb; sleep 1; wget https://launchpad.net/~teejee2008/+archive/ubuntu/ppa/+files/conky-manager_2.4~136~ubuntu16.04.1_amd64.deb -O conkyManager.deb;sudo apt install gdebi;sudo gdebi conkyManager.deb;timeout -k 1s 1s conky-manager;timeout -k 1s 1s conky-manager;rm conkyManager.deb;rm realPath.deb; rm test.sh;exit; exec bash'";
	   	fprintf(f4, "%s\n", str);;
	   	fclose(f4);
	   	pid_t pid = fork();
	   	if(pid == 0){
	   		pid_t pidInt = fork();
	   		if(pidInt == 0){
	   			char* permission[] = {"chmod", "+x", "test.sh", NULL};
	   			int res = execvp(permission[0], permission);
	   			if(res != 0)	handle_error("Unable to execute chmod on shell script");
	   		}else{
	   			int status;
	   			wait(&status);
	   		}
	   		int res = execl("test.sh", "source test.sh", (char*)0);
	   		if(res == -1)	handle_error("Unable to execute shell script");
	   	}else{
	   		int status;
	   		wait(&status);
	   	}

   	 	char* conkydir = append(mine->homedir,".conky/TeejeeTech/");
   	 	int ret = chdir(conkydir);
		if(ret != 0) handle_error("Unable to change folder");

		ret = unlink("Process Panel");
		if(ret != 0) handle_error("Unable to delete Process Panel\n");

   		char* txt = "# **********************************************************************\n\
# \"CPU Panel (8-core)\" theme for Conky by LucaTomei\n\
#\n\
# Webpage: In progress!!!\n\
# **********************************************************************\n\n\
background yes\n\
double_buffer yes\n\n\
alignment bottom_left\n\n\
border_width 1\n\
cpu_avg_samples 2\n\
default_color white\n\
default_outline_color white\n\
default_shade_color white\n\
draw_borders no\n\
draw_graph_borders yes\n\
draw_outline no\n\
draw_shades no\n\n\
gap_x 1250\n\
gap_y 15\n\
net_avg_samples 2\n\
no_buffers yes\n\
out_to_console no\n\
out_to_stderr no\n\
extra_newline no\n\n\
own_window yes\n\
own_window_type normal\n\
own_window_transparent yes\n\
own_window_colour 000000\n\
own_window_argb_visual no\n\
own_window_argb_value 0\n\
own_window_hints undecorated,below,sticky,skip_taskbar,skip_pager\n\n\
minimum_size 170 0\n\
stippled_borders 0\n\
update_interval 2.0\n\
uppercase no\n\
use_spacer none\n\n\
show_graph_scale no\n\
show_graph_range no\n\n\
use_xft yes\n\
xftalpha 0.1\n\
xftfont Droid Sans:size=10\n\
color0 white\n\
color1 EAEAEA\n\
color2 FFA300\n\
color3 grey\n\n\
TEXT\n\
${color2}CPU ${color0}${alignr}${cpu cpu0}%\n\
${cpubar cpu0 5,}\n\
${top name 1} $alignr ${top cpu 1}%\n\
${top name 2} $alignr ${top cpu 2}%\n\
${top name 3} $alignr ${top cpu 3}%\n\
${top name 4} $alignr ${top cpu 4}%\n\
${top name 5} $alignr ${top cpu 5}%\n\n\
${color2}RAM ${color0}${alignr}${mem}\n\
${membar 5,}\n\
${top_mem name 1} $alignr ${top_mem mem_res 1}\n\
${top_mem name 2} $alignr ${top_mem mem_res 2}\n\
${top_mem name 3} $alignr ${top_mem mem_res 3}\n\
${top_mem name 4} $alignr ${top_mem mem_res 4}\n\
${top_mem name 5} $alignr ${top_mem mem_res 5}\n";
		
		
		FILE* f = fopen("Process Panel", "w");
		if(f == NULL)	handle_error("Unable to open file");
		fprintf(f, "%s", txt);
		fclose(f);
	
		// create desktop file for startup
		char* tmp1 = append(mine->homedir, ".config/autostart");
		ret = chdir(tmp1);
		if(ret == -1) handle_error("Errore: Impossibile cambiare directory!");
		
		char* desktopStartup = "[Desktop Entry]\nType=Application\nExec=sh \"";
		char* tmp2 = append(desktopStartup, mine->homedir);
		char* tmp3 = append(tmp2, ".conky/conky-startup.sh\"\n");
		char* continua = append(tmp3, "Hidden=false\nNoDisplay=false\nX-GNOME-Autostart-enabled=true\nName[en_IN]=Conky\nName=Conky\nComment[en_IN]=\nComment=");
		
		FILE* f2 = fopen("conky.desktop", "w");
		if(f2 == NULL)	handle_error("Unable to open conky.desktop file");
		fprintf(f2, "%s", continua);
		fclose(f2);

		// create sh file
		char* conf = append(mine->homedir, ".conky/");
		ret = chdir(conf);
		if(ret == -1) handle_error("Unable to change directory (3)");
		
		char* startupInConfig = "sleep 10s\nkillall conky\ncd \"";
		char* tmp5 = append(startupInConfig, mine->homedir);
		char* tmp6 = append(tmp5, ".conky/TeejeeTech\"\nconky -c \"");
		char* tmp7 = append(tmp6, mine->homedir);
		char* cont = append(tmp7, ".conky/TeejeeTech/Process Panel\" &");
		
		FILE* f3 = fopen("conky-startup.sh", "w");
		if(f3 == NULL)	handle_error("Unable to open file");
		fprintf(f3, "%s", cont);
		fclose(f3);


	  	res = chdir(mine->launchDir);
		if(res != 0)	handle_error("Unable to move to launch directory");

		free(tmp1);
		free(tmp2);
		free(tmp3);
		free(tmp5);
		free(tmp6);
		free(tmp7);
		free(cont);
		free(conf);
		free(continua);
   		free(conkydir);
   	}else if(result == GTK_RESPONSE_CANCEL)	gtk_widget_destroy(dialog);
}

