#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit
#include <stdio.h>  // perror
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>


#define handle_error(msg)\
do{\
	perror(msg);\
	exit(EXIT_FAILURE);\
}while(0)

/*
				1. Download
				2. Extract zip
				3. Copy zip content in /home/user/nomeFolder
				4. chmod a+x sublime_text executable file
				5. Create desktop file
				6. Copy desktop file in .local/share/application
				7. Remove .desktop file in actual folder
				8. Remove zip file 
				9. TEST IT ALL
*/

char* append(char* string1, char* string2);

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
	
	char* subl_folder = append(homedir, "/sublime_text/");	// TODO: RINOMINA CON  sublime_text
	char* tmp = append(subl_folder, "sublime_text ");
	char* exe_location = append(tmp, "%F\n");

	char* exe_dir = append(init_test, exe_location);
	
	char* tmp_icon = append(exe_dir, "Terminal=false\nMimeType=text/plain;\n");
	

	char* ttt = append("Icon=", homedir);
	char* subl_folder1 = append(ttt, "/sublime_text/"); 	// TODO: RINOMINA CON  sublime_text
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
	system("tput reset");
}

int main(int argc, char const *argv[]){
	sublime_installer();
	return 0;
}


char* append(char* string1, char* string2){
	size_t dim = (strlen(string1)) + (strlen(string2) + 1);
	char *tmp = (char*)malloc(dim * sizeof(char));
    strcpy(tmp, string1);
    strcat(tmp, string2);
	return tmp;
}