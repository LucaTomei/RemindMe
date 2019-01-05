#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>

#define handle_error(msg)\
do{\
	fprintf(stderr, "%s\n", msg);\
	sleep(1);\
	system("tput reset");\
	exit(EXIT_FAILURE);\
}while(0)

char* append(char* string1, char* string2);
void backup_home_files();

int main(int argc, char *argv[]){
	backup_home_files();
	return 0;
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
	if(choice != 'Y' && choice != 'y') handle_error("See you later!");

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
		}else handle_error("Error: I'm closing the program!");
		
	}

	if(ret != 0)	handle_error("Error: Unable to execute command!");
	

	char* homedir = append(hometmp, "/");
	char* path = homedir;
	ret = chdir(path);
	if(ret == -1)	handle_error("Error: Unable to move in this directory");


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
	system("tput reset");
}

char* append(char* string1, char* string2){
	size_t dim = (strlen(string1)) + (strlen(string2) + 1);
	char *ret = malloc(dim * sizeof(char));
    strcpy(ret, string1);
    strcat(ret, string2);
   	return ret;
}