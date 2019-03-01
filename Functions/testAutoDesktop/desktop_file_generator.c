#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define handle_error(msg)\
do{\
	perror(msg);\
	exit(1);\
}while(0);

char* append(char* string1, char* string2){
	size_t dim = (strlen(string1)) + (strlen(string2));
	char *ret = (char*)malloc(dim * sizeof(char) + 1);
    strcpy(ret, string1);
    strcat(ret, string2);
	return ret;
}

void create_desktop_file(){
	char* init = "[Desktop Entry]\nType=Application\nName=";
	printf("What is the name of your app?\n");
	char tmp[256];
	
	fgets(tmp, sizeof(tmp), stdin);		// alternative scanf
	char* n = append(init, tmp);
	char* name = append(n, "Exec=");
	free(n);

	printf("Where is located the exe file? Please paste the path of this file\n");
	fgets(tmp, sizeof(tmp), stdin);
	char* e = append(name, tmp);
	free(name);
	char* exe_location = append(e, "Icon=");
	free(e);
	
	printf("Where is located the icon file? Please paste the path of this file\n");
	fgets(tmp, sizeof(tmp), stdin);
	char* end = append(exe_location, tmp);
	free(exe_location);

	printf("What is the name of this desktop file?\t");
	
	char *na = (char*)malloc(sizeof(char) + 1);
	scanf("%s", na);

	char* nameoffile = append(na, ".desktop");
	
	FILE* f = fopen(nameoffile, "w");
	if(f == NULL)	handle_error("\n\nImpossibile creare il file in scrittura\n\n");
	fprintf(f, "%s", end);

	free(end);
	free(name);
	free(na);
	free(nameoffile);
}


int main(int argc, char const *argv[]){
	create_desktop_file();
	return 0;
}
