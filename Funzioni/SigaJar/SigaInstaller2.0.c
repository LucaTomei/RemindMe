#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

char* append(char* string1, char* string2){
	size_t dim = (strlen(string1)) + (strlen(string2) + 1);
	char *ret = malloc(dim * sizeof(char));
    strcpy(ret, string1);
    strcat(ret, string2);
   	return ret;
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
}

int main(int argc, char *argv[]){
	sigaInstaller();
	return 0;
}
