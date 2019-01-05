#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>



char* append(char* string1, char* string2);
void create_dipendencies_desktop();
char* home_sig_exe();
char* home_sig_png();
void write_desktop_file();
void download_jar_from_dropbox();
void copy_relative_files_to_folders();



int main(int argc, char const *argv[]){
	//create_dipendencies_desktop();
	download_jar_from_dropbox();
	write_desktop_file();
	copy_relative_files_to_folders();
	return 0;
}


char* append(char* string1, char* string2){
	size_t dim = (strlen(string1)) + (strlen(string2) + 1);
	char *ret = malloc(dim * sizeof(char));
    strcpy(ret, string1);
    strcat(ret, string2);
   	return ret;
}

void create_dipendencies_desktop(){
	// Download the icon
	system("wget https://cdn2.iconfinder.com/data/icons/vape/100/05-512.png -O ~/Downloads/icon.png");
	// create .desktop file
	system("touch ~/Downloads/Siga.desktop");
	system("echo [Desktop Entry] >> ~/Downloads/Siga.desktop");
	system("ehco Type=Application >> ~/Downloads/Siga.desktop");
	system("echo Name=Siga >> ~/Downloads/Siga.desktop");
	system("echo Exec=java -jar /home/lucasmac/Desktop/Test-in-Progress/SigaJar/Siga.jar >> ~/Downloads/Siga.desktop"); // cambialo
	system("echo Icon=/home/lucasmac/Desktop/Test-in-Progress/SigaJar/siga.png >> ~/Downloads/Siga.desktop"); 	// cambialo
	system("echo Terminal=false >> ~/Downloads/Siga.desktop");
	system("echo Categories=Application; >> ~/Downloads/Siga.desktop");

}

char* home_sig_exe(){
	struct passwd *pw = getpwuid(getuid());
	char *homedir = pw->pw_dir;		// home directory
	char* sigFolder = append(homedir, "/Siga/");
	char* tmp = append(sigFolder, "Siga.jar");
	char* sigEx = append(tmp, "\n");
	free(tmp);
	free(sigFolder);
	return sigEx;
}


char* home_sig_png(){
	struct passwd *pw = getpwuid(getuid());
	char *homedir = pw->pw_dir;
	char* sigFolder = append(homedir, "/Siga/");
	char* tmp = append(sigFolder, "Siga.png");
	char* sigIcon = append(tmp, "\n");
	free(tmp);
	free(sigFolder);
	return sigIcon;
}

void write_desktop_file(){
	FILE *f = fopen("Siga.desktop", "w");
	
	if (f == NULL){
	    printf("Error opening file!\n");
	    exit(1);
	}
	char* text = "[Desktop Entry]\nVersion=1.0\nType=Application\nName=Luca's Siga\nExec=java -jar ";
	char* exe = append(text, home_sig_exe());
	char* exe_png = append(exe, "Icon=");
	char* result = append(exe_png, home_sig_png());

	fprintf(f, "%s\n", result);
	fclose(f);	
	free(exe);
	free(exe_png);
	free(result);
	
}

void download_jar_from_dropbox(){
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
}

void copy_relative_files_to_folders(){
	system("cp Siga.desktop ~/.local/share/applications");
	system("rm Siga.desktop");
	system("chmod a+x ~/.local/share/applications");
}
