#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <limits.h>

#define handle_error(msg)\
do{\
	perror(msg);\
	exit(EXIT_FAILURE);\
}while(0)


#define backup_error(msg)\
do{\
	fprintf(stderr, "%s\n", msg);\
	sleep(1);\
	system("tput reset");\
	exit(EXIT_FAILURE);\
}while(0)

#define BAR "=================================================================="
					/*							TODO
					* Fai un programma per IL backup automatico di Ubuntu
					* Setta i colori in modo adeguato
					* Nuovo dropbox (puxat@trimsj.com)
					* Inserisci eclipse all'automatic software installation
					* Aggiungi installazione automatica di conky
					* Aggiungi posizionamento automatico e installazione xpad (+ set startup)
					*/

// dichiarazione funzioni
void installConkyManager();
void progress_bar_welcome();
void progress_bar_exit();
void progress_bar();
void pre_welcome();
void welcome_message();
char *append(char * string1, char * string2);	
void set_size_for_gedit_plugin_terminal();
void set_eclipse_oxygen_icon();
void change_x_sharedlib_icon();
void change_executable_icon();
void set_gcc_4_8();
void set_gcc_8();
void first_software_installation();
void hide_xPad_icon();
void set_xPad_resolution_and_dimentions();
void set_grub_resolution();
void set_parallels_default_resolution();
void automatic_startup();
void automatic_main_generator();
void sublime_installer();
void backup_home_files();
void sigaInstaller();


int main(int argc, char const *argv[]){
	int choice;
	pre_welcome();
	do{
		welcome_message();
		system("tput sgr0");
		printf("Inserisci la tua scelta:\t");
		scanf("%d", &choice);
		switch(choice){
			case 1:	
				hide_xPad_icon();
				progress_bar();
				break;
			case 2:
				set_parallels_default_resolution();
				progress_bar();
				break;
			case 3:
				set_gcc_4_8();
				progress_bar();
				break;
			case 4:
				change_executable_icon();
				progress_bar();
				break;
			case 5:
				set_eclipse_oxygen_icon();
				progress_bar();
				break;
			case 6:
				first_software_installation();
				progress_bar();
				break;
			case 7:
				set_size_for_gedit_plugin_terminal();
				progress_bar();
				break;
			case 8:
				set_gcc_8();
				progress_bar();
				break;
			case 9:
				set_xPad_resolution_and_dimentions();
				progress_bar();
				break;
			case 10:
				set_grub_resolution();
				progress_bar();
				break;
			case 11:
				change_x_sharedlib_icon();
				progress_bar();
				break;
			case 12:
				automatic_startup();
				progress_bar();
				break;
			case 13:
				automatic_main_generator();
				progress_bar();
				break;
			case 14:
				sublime_installer();
				progress_bar();
				break;
			case 15:
				backup_home_files();
				progress_bar();
				break;
			case 16:
				sigaInstaller();
				progress_bar();
				break;
			case 17:
				installConkyManager();
				progress_bar();
				break;
			case 0:	break;
			default:	break;
		}
	}while(choice !=0);
	progress_bar_exit();
	sleep(1);
	system("tput reset");
	return 0;
}


void progress_bar_welcome(){
	system("tput setaf 6");
	int BAR_WIDTH = 60;
	unsigned int percentage=0;
	while(percentage<100){
		++percentage;
		unsigned int lbar=percentage*BAR_WIDTH/100;
		unsigned int rbar=BAR_WIDTH-lbar;
		printf("\r[%.*s%*s] %d%% Completed.", lbar, BAR, rbar, "", percentage);
		fflush(stdout);
		nanosleep((const struct timespec[]){{0, 25000000L}}, NULL);

	}
	printf("\n");
	system("tput sgr0");
	system("tput reset");
}

void progress_bar_exit(){
	system("tput setaf 6");
	int BAR_WIDTH = 60;
	unsigned int percentage=0;
	while(percentage<100){
		++percentage;
		unsigned int lbar=percentage*BAR_WIDTH/100;
		unsigned int rbar=BAR_WIDTH-lbar;
		printf("\r[%.*s%*s] %d%% Completed.", lbar, BAR, rbar, "", percentage);
		fflush(stdout);
		nanosleep((const struct timespec[]){{0, 25000000L}}, NULL);

	}
	printf("\n");
	system("tput sgr0");
}

void progress_bar(){
	system("tput setaf 6");
	int BAR_WIDTH = 60;
	unsigned int percentage=0;
	while(percentage<100){
		++percentage;
		unsigned int lbar=percentage*BAR_WIDTH/100;
		unsigned int rbar=BAR_WIDTH-lbar;
		printf("\r[%.*s%*s] %d%% Completed.", lbar, BAR, rbar, "", percentage);
		fflush(stdout);
		nanosleep((const struct timespec[]){{0, 20000000L}}, NULL);

	}
	printf("\n");
	system("tput sgr0");
	
}


void pre_welcome(){
	system("tput reset");
	system("echo \033[41mThese scripts are made by:\033[0m");
	system("tput sgr0");
	system("tput setaf 2");
	system("tput blink");
	printf("\n\n\n");
	printf("###		    ###           ###     ################     ###############\n");
	printf("###		    ###           ###    #################    ###           ###\n");
	printf("###		    ###           ###   ###                   ###           ###\n");
	printf("###		    ###           ###   ###                   ###           ###\n");
	printf("###		    ###           ###   ###                   #################\n");
	printf("###		    ###           ###   ###                   ####LUCAS'MAC####\n");
	printf("###		    ###           ###   ###                   ###           ###\n");
	printf("###		    ###           ###   ###                   ###           ###\n");
	printf("###		    ###           ###   ###                   ###           ###\n");
	printf("################     ##############      #################    ###           ###\n");
	printf("################      ###########         ################   ####           ####\n\n\n\n");
	
	system("tput sgr0");

	printf("\n\n\n\n\n");
	progress_bar_welcome();
}	
void welcome_message(){
	system("tput setaf 2");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("What would you like to remember?\n");
	printf(" (1)	Hide xPad icon		 (2)	Set Parallels default resolution\n");
	printf(" (3)	gcc-4.8     		 (4)	Change executable icon\n");
	printf(" (5)	Set eclipse icon	 (6)	First Software Installation\n");
	printf(" (7)	Set size for gedit plugins terminal	\n");
	printf(" (8)	gcc-8 + make	         (9)	Set xPad resolution and dimentions\n");
	printf("(10)	Set grub dimentions      (11) 	Change app/x-sharedlib icon (gcc-8)\n");
	printf("(12)    Set 'startup' for automatic update\n");
	printf("(13)    Automatic Main           (14)    Sublime_Text Installer\n");
	printf("(15)    Automatic Backup         (16)    E-Liquid Calculator\n");
	printf("(17)    Install Conky Manager    (0)	break\n\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");

}


char* append(char* string1, char* string2){
	size_t dim = (strlen(string1)) + (strlen(string2) + 1);
	char *tmp = malloc(dim * sizeof(char));
    strcpy(tmp, string1);
    strcat(tmp, string2);
   	return tmp;
}	

void set_size_for_gedit_plugin_terminal(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("This is a guide.\n");
	printf("If you wish to set the resolutive size of the gedit terminal, you'll have to:\n");
	printf("1) Go into /usr/lib/x86_64-linux-gnu/gedit/plugins\n");
	printf("2) Modify with sudo terminal.py file\n");
	printf("3) Set at line 53 ---> self.set_size_request(200, 100)\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n\n");
}

void set_eclipse_oxygen_icon(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("This is a guide:\n");
	printf("To set eclipse icon:\n");
	printf("1) Create 'eclipse.desktop' file in '.local/share/applications'\n");
	printf("2) Write this into eclipse.desktop file this code:\n");
	printf("\t\t------------------------CODE------------------------\n");
	printf("[Desktop Entry]\nVersion=1.0\nName=Eclipse\nComment=Eclipse\nExec=/home/lucasmac/eclipse/java-oxygen/eclipse/eclipse\nIcon=/home/lucasmac/eclipse/java-oxygen/eclipse/icon.xpm\nTerminal=false\nType=Application\nCategories=Utility;Application;\n");
	printf("\t\t--------------------END OF CODE-------------------\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n\n");
}

void change_x_sharedlib_icon(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	char* name;
	printf("This is NOT a guide, is an automatic installer\n\n");
	printf("\nNOTE:\nIf you want to set a different icon plese insert 'Y' and paste the link above, else press any key and wait for installation (Y/n)\n");
	char response;
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n\n");
	char link[300];
	char *wget_temp, *wget;
	scanf("\n%c", &response);

	if(response == 'y' || response == 'Y'){
		printf("\n\nPaste the link above of your desiderate png icon\n");
		scanf("%s", link);
		wget_temp = append("wget ", link);
		wget = append(wget_temp, " -O application-x-sharedlib.png");
		system(wget);	// scarico l'icona
		system("sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-sharedlib.png");

	}else{
		printf("Automatic Icon Setting\n\n");
		system("sleep 1");
		system("wget http://icons.iconarchive.com/icons/ph03nyx/super-mario/256/Retro-Flower-Fire-2-icon.png -O application-x-sharedlib.png");
		system("sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-sharedlib.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-sharedlib.png");
		
	}

	free(wget_temp);
	free(wget);
}

void change_executable_icon(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	char* name;
	printf("This is NOT a guide, is an automatic installer\n\n");
	printf("\nNOTE:\nIf you want to set a different icon plese insert 'Y' and paste the link above, else press any key and wait for installation (Y/n)\n");
	char response;
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n\n");
	char link[300];
	char *wget_temp, *wget;
	scanf("\n%c", &response);

	if(response == 'y' || response == 'Y'){
		printf("\n\nPaste the link above of your desiderate png icon\n");
		scanf("%s", link);
		wget_temp = append("wget ", link);
		wget = append(wget_temp, " -O application-x-executable.png");
		system(wget);	// scarico l'icona
		system("sudo cp application-x-executable.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-executable.png");

	}else{
		printf("Automatic Icon Setting\n\n");
		system("sleep 1");
		system("wget http://icons.iconarchive.com/icons/ph03nyx/super-mario/256/Retro-Flower-Fire-2-icon.png -O application-x-executable.png");
		system("sudo cp application-x-executable.png /usr/share/icons/Adwaita/512x512/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/32x32/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/48x48/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/24x24/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/22x22/mimetypes && sudo cp application-x-executable.png /usr/share/icons/Adwaita/16x16/mimetypes && sudo gtk-update-icon-cache /usr/share/icons/Humanity && sudo gtk-update-icon-cache /usr/share/icons/Adwaita && sudo gtk-update-icon-cache /usr/share/icons/gnome && gsettings set org.gnome.desktop.interface icon-theme culoculo && gsettings reset org.gnome.desktop.interface icon-theme && sudo rm -r application-x-executable.png");
		
	}

	free(wget_temp);
	free(wget);
}

void set_gcc_4_8(){
	system("tput reset");
	printf("This is NOT a guide! Do you want to continue? (Y/n)\n");
	char response;
	scanf("\n%c", &response);
	if(response == 'Y' || response == 'y'){
		system("sudo apt-get install gcc-4.8-multilib && ls -la /usr/bin/ | grep -oP \"[\\S]*(gcc|g\\+\\+)(-[a-z]+)*[\\s]\" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f \"/usr/bin/${link}-${0}\" \"/usr/bin/${link}\"; done' 4.8");
	}else{
		printf("\nBye bye my friend\n");
		system("sleep 1");
		exit(0);
	}
}

void set_gcc_8(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("This is NOT a guide! Do you want to continue? (Y/n)\n");
	char response;
	scanf("\n%c", &response);
	if(response == 'Y' || response == 'y'){
		system("sudo apt-get install gcc-8-multilib && ls -la /usr/bin/ | grep -oP \"[\\S]*(gcc|g\\+\\+)(-[a-z]+)*[\\s]\" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f \"/usr/bin/${link}-${0}\" \"/usr/bin/${link}\"; done' 8");
	}else{
		printf("\nBye bye my friend\n");
		system("sleep 1");
	}
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");

}

void first_software_installation(){
	system("tput reset");
	char response;
	system("sudo apt update && sudo apt upgrade && sudo apt autoremove");
	system("tput reset");
	// jdk install
	printf("Do you want to install all necessary files (Y/n)\n");
	scanf("\n%c", &response);
	if(response == 'Y' || response == 'y'){
		system("sleep 2");
		system("sudo apt-get install default-jdk && sudo apt-get install xpad && sudo apt-get install synaptic && sudo apt update && sudo apt upgrade && sudo apt autoremove && sudo apt autoclean && sudo dpkg --configure -a && sudo apt-get install -f");	
	}else{
		printf("\nBye bye my friend\n");
		system("sleep 1");
		exit(0);
	}
		
}

void hide_xPad_icon(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("This is only a guide:\n");
	printf("To hide xPad icon\n");
	printf("1) Go into .config/xpad and edit 'default-style'\n");
	printf("2) Set 1 for hide_from_taskbar\n");
	printf("3) Set 1 for hide_from_switcher\n\n");
	printf("NOTE: These values ​​were previously set to 0\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n\n");
}

void set_xPad_resolution_and_dimentions(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("This is a guide:\n");
	printf("If you want to set the resolutive size of the xPad note or its dimentions:\n");
	printf("1) Go into /config/xpad\n");
	printf("2) Edit with gedit 'info-***' file\n");
	printf("\nN.B.: If you want to set its position on the top right of the screen, you'll edit the file like this:\n");
	printf("\nwidth 290\n");
	printf("height 215\n");
	printf("x 1164\n");
	printf("y 27\n");
	printf("follow_font 1\n");
	printf("follow_color 1\n");
	printf("sticky 1\n");
	printf("hidden 0\n");
	printf("back rgb(255,238,153)\n");
	printf("text rgb(0,0,0)\n");
	printf("fontname Sans 10\n");
	printf("content content-MG38HZ\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
}

void set_grub_resolution(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("This is only a guide!\n");
	printf("To set default boot resolution for grub:\n");
	printf("1) Navigate into /etc/default\n");
	printf("2) Edit 'grub' file with a text editor\n");
	printf("3) Uncomment 25 line and paste this GRUB_GFXMODE=1440x900\n");
	printf("4) Ran sudo update-grub\n");
	printf("5) Reboot the system\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n\n");
}

void set_parallels_default_resolution(){
	system("tput reset");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
	printf("This is only a guide!\n");
	printf("To set default boot resolution for parallels driver:\n");
	printf("1)	First install parallels-tool\n");
	printf("2)	Then go into /usr/share/X11/xorg.conf.d\n");
	printf("3) Open file '40-prltools.conf'\n");
	printf("4) Modify voice Modes in # Parallels Screen section setting it into '1440x900'\n");
	printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n\n");

}


void automatic_startup(){
	system("tput reset");
	char response;
	printf("Now I'm Setting the automatic startup program and I'm calling it 'startup'\n\n\n");
	system("sleep 1");
	system("wget 'https://www.dropbox.com/s/mospp3iiyc18zad/avvio_no_process.c?dl=0' -O avvio.c");
	system("gcc -o startup avvio.c");
	printf("Do you want to set this file global in your system?  (Y/N)");
	scanf("\n%c", &response);
	if(response == 'Y' || response == 'y'){
		system("sudo cp startup /usr/local/bin && sudo rm -r startup avvio.c");
	}else{
		system("sudo rm -r avvio.c");
		printf("\nBye bye my friend\n");
		system("sleep 1");
		exit(0);
	}
}

void automatic_main_generator(){
	system("tput reset");
	char response;
	printf("Now I'm setting necessary files!\n\n\n");
	system("wget 'https://www.dropbox.com/s/hcxc0eod6sx7z5i/main_vers_3.c?dl=0' -O main.c");
	system("gcc -o main main.c");
	printf("\n\n\nDo you want to set this file global in your system?  (Y/N)");
	scanf("\n%c", &response);
	if(response == 'Y' || response == 'y'){
		system("sudo cp main /usr/local/bin && sudo rm -r main main.c");
	}else{
		system("sudo rm -r main.c");
		printf("\nBye bye my friend\n");
		system("sleep 1");
		exit(0);
	}
}

void sublime_installer(){
	system("wget https://www.dropbox.com/s/9tl1ctd4amlwvtc/sublime_text.tar.gz?dl=0 -O sublime_text.tar.gz");
	
	system("mkdir sublime_text");
	system("tar -xzvf sublime_text.tar.gz -C sublime_text");

	struct passwd *pw = getpwuid(getuid());
	char *homedir = pw->pw_dir;

	char* cp = append("cp -R sublime_text ", homedir);			
	char* homeSubl = append(cp, "/");
	system(homeSubl);
	free(cp);
	free(homeSubl);	

	char* chmod1 = append("chmod a+x ", homedir);
	char* chmod = append(chmod1, "/sublime_text/sublime_text");					

	system(chmod);
	free(chmod1);
	free(chmod);


	// rendo subl globale
	printf("Do You Want to set 'subl' command global in your system? [Y/n]\n");
	char response;
	scanf("\n%c", &response);
	if(response == 'Y' || response == 'y'){
		char* global = append("sudo ln -sv ", homedir);
		char* global_subl = append(global, "/sublime_text/sublime_text /usr/local/bin/subl");
		system(global_subl);
		free(global);
		free(global_subl);
	}
	
	response = '\0';


	// Create desktop file
	FILE *f = fopen("sublime_text.desktop", "w");
	if(f == NULL)	handle_error("\n\nImpossibile creare il file in scrittura\n\n");

	char* init_test = "[Desktop Entry]\nVersion=1.0\nType=Application\nName=Sublime Text\nGenericName=Text Editor\nComment=Sophisticated text editor for code, markup and prose\nExec=";
	
	char* subl_folder = append(homedir, "/sublime_text/");	
	char* tmp = append(subl_folder, "sublime_text ");
	char* exe_location = append(tmp, "%F\n");

	char* exe_dir = append(init_test, exe_location);
	
	char* tmp_icon = append(exe_dir, "Terminal=false\nMimeType=text/plain;\n");
	

	char* ttt = append("Icon=", homedir);
	char* subl_folder1 = append(ttt, "/sublime_text/"); 	
	char* tmp1 = append(subl_folder1, "Icon/256x256/sublime-text.png");
	char* icon_location = append(tmp1, "\n");
	char* exe_icon = append(tmp_icon, icon_location);

	char* post_one = append(exe_icon, "Categories=TextEditor;Development;\nStartupNotify=true\nActions=Window;Document;\n\n[Desktop Action Window]\nName=New Window\nExec=");
	

	char* tmp2 = append(subl_folder, "sublime_text ");
	char* exe_post = append(tmp2, "-n\n");
	char* post_exe = append(post_one, exe_post);
	char* o = append(post_exe, "OnlyShowIn=Unity;\n\n[Desktop Action Document]\nName=New File\nExec=");

	char* exe = append(subl_folder, "sublime_text");
	char* quasi_fatto = append(o, exe);

	char* fileOK  = append(quasi_fatto, " --command new_file\nOnlyShowIn=Unity;\n");
	
	fprintf(f, "%s\n", fileOK);
	fclose(f);

	free(subl_folder);
	free(exe_location);
	free(tmp1);
	free(tmp);
	free(exe_dir);
	free(tmp_icon);
	free(ttt);
	free(tmp2);
	free(subl_folder1);
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
	char* copy = "cp sublime_text.desktop ";
	char* homedir1 = append(copy, pw->pw_dir);
	char* local = append(homedir1, "/.local/share/applications/");
	system(local);
	free(homedir1);
	free(local);

	// Remove all files
	system("tput reset");
	system("rm -R sublime_text");
	system("rm sublime_text.desktop");
	system("rm sublime_text.tar.gz");
	printf("Do you want to delete installation file [Y/n]\n");
	
	scanf("\n%c", &response);
	if(response == 'y' || response == 'Y')	system("rm sublime_installer");
	else	exit(EXIT_SUCCESS);
}

void backup_home_files(){

	system("tput reset");
	printf("\n");
     printf("   +======================================================================+\n"
		"   |                     Automatic Backup for Ubuntu                      |\n"
		"   +======================================================================+\n"
		"   |                  Copyright (C) 2018 Luca Tomei                       |\n"
		"   +----------------------------------------------------------------------+\n"
		"   |\tVersion: 1.0                                                      |\n"
		"   +----------------------------------------------------------------------+\n"
		"   |  This program comes with ABSOLUTELY NO WARRANTY. This is free        |\n"
		"   |  software, and you are welcome to redistribute it under certain      |\n"
		"   |  conditions; for further details, please refer to the GNU General    |\n"
		"   |  Public License provided with this program.                          |\n"
		"   +======================================================================+\n"
    "   +======================================================================+\n\n");

    printf("  +---Description-----------------------------------------------------------+\n");
    printf("  |This program make a backup of all your /home/username directory (incuding|\n");
    printf("  |Desktop folder, Documents folder, Download folder, ...) and also .config |\n");
    printf("  |and .local folder that contains setting of your old installed programs!  |\n");
    printf("  +-------------------------------------------------------------------------+\n");
    printf("\n\nDo you want to proceed?[Y/n]\n");
	char choice;
	scanf("\n%c", &choice);
	if(choice != 'Y' && choice != 'y') backup_error("See you later!");

	int ret;

	// creating backup folder in /home/username/
	struct stat st = {0};
	char* tmp = "/Backup_Folder";

	struct passwd *pw = getpwuid(getuid());
	char *hometmp = pw->pw_dir;
	char* backup_tmp = append(hometmp, tmp);
	char* backup_folder = append(backup_tmp, "/");

	if (stat(backup_folder, &st) == -1) {
    	mkdir(backup_folder, 0700);
	}else	{
		fprintf(stderr, "Error: There is just a directory with Backup_Folder name in %s!\n", hometmp);
		printf("Do you want to delete de directory for to recreate it?[Y/n]\n");
		scanf("\n%c", &choice);
		if(choice == 'Y' || choice == 'y')	{
			char* rm = append("sudo rm -R ", backup_folder);
			ret = system(rm);
			free(rm);
			mkdir(backup_folder, 0700);
		}else backup_error("Error: I'm closing the program!");
		
	}

	if(ret != 0)	backup_error("Error: Unable to execute command!");
	

	char* homedir = append(hometmp, "/");
	char* path = homedir;
	ret = chdir(path);
	if(ret == -1)	backup_error("Error: Unable to move in this directory");


	//  Preparing command
	char* one = append("rsync -avz ", homedir);
	char* space = append(one, " ");
	char* two = append(space, backup_folder);
	char* exclude = " --exclude Backup_Folder --exclude snap --exclude .cache --exclude .conky --exclude .eclipse --exclude .fonts --exclude .gnupg --exclude .java --exclude .mozilla --exclude .parallels --exclude .ssh --exclude .swt --exclude .tooling --exclude .bash_history --exclude .bash_logout --exclude .bashrc --exclude .ICEauthority --exclude .profile --exclude .sudo_as_admin_successful --exclude .wget-hsts";
	char* okGo = append(two, exclude);


	// putting username name for to create archive whit it!
	const char ch = '/';
	char *try = strrchr(hometmp, ch);
    char* userName = try + 1;
    char* aft = append(userName, "Backup.tar.gz Backup_Folder");
    char* back = append("tar -zcvf ", aft);

    char* tm2 = append(okGo, " && ");
    char* letsGo = append(tm2, back);
    system(letsGo);

    printf("\t\n\n\n");
	printf("\tPlease, after the end of terminal activity, before\n");
    printf("\tto close terminal, wait until 'yourUserName.tar.gz'\n");
    printf("\tfile is created in %s!\n\n\n", homedir);
    sleep(2);
	printf("Do you want to cancel 'Backup_Folder' folder?[Y/n]\n");
	scanf("\n%c", &choice);
	if(choice == 'Y' || choice == 'y'){
		system("sudo rm -R Backup_Folder");
		printf("\n\nBye bye my friend!\n");
	}else printf("\n\nBye bye my friend!\n");
	free(tm2);
	free(letsGo);
    free(backup_tmp);
    free(backup_folder);
    free(homedir);
    free(one);
    free(space);
    free(two);
    free(okGo);
	free(aft);
	free(back);
	sleep(2);	
}

void sigaInstaller(){
	// downloading jar from dropbox
	system("wget https://www.dropbox.com/s/4xalr9b94btiohs/Siga3.0.jar?dl=0 -O Siga.jar");
	system("mkdir ~/Siga");
	system("cp Siga.jar ~/Siga");	// now siga.jar is in home directory
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
	char *homedir = pw->pw_dir;		// home directory
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
	sleep(2);
}

void installConkyManager(){
	// Download in this folder
	system("wget http://cz.archive.ubuntu.com/ubuntu/pool/main/c/coreutils/realpath_8.26-3ubuntu4_all.deb -O realPath.deb");
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
	fclose(f3);
}