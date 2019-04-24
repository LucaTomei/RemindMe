
GtkWidget *dialog;




void installDeezeerDownloader(){
	int ret;
	
	// I'm in launching directory - Write desktop file


    // Download All necesary files and move them to .local/Share/Applications
    char* ExeLink = "https://www.dropbox.com/s/dfsqatjphaie4iq/DeezerDownloader?dl=0";
    char* icon = "http://www.icons101.com/icon_png/size_512/id_78111/Deezer_Tilt_Color_JasonZigrino.png";
    
    char* DeezerDir = append(mine->homedir, ".local/share/applications/DeezerDownloader");	


/*	FILE *f = fopen("DeezerDownloader.desktop", "w");
    if(f == NULL) handle_error("\n\nImpossibile creare il file in scrittura\n\n");



    char* init_test = "[Desktop Entry]\nVersion=1.0\nName=Deezer Downloader\nComment=The Most Beatuful Downloader\nExec= "
*/	

    char* tmp1 = append("gnome-terminal --geometry 73x20+100+300 -- sh -c 'mkdir ", DeezerDir);
    char* tmp2 = append(tmp1, ";exit;exec bash'");
   	
   	ret = system(tmp2);
    ret = chdir(DeezerDir);
    if(ret != 0)  handle_error("Unable to change directory");
    
    // Now i'm in .local
    char* tmp3 = append("wget ", ExeLink);
    char* tmp4 = append(tmp3, " -O DeezerDownloader");
    char* tmp5 = append("gnome-terminal --geometry 73x20+100+300 -- sh -c ' ", tmp4);
    char* tmp6 = append(tmp5,"; chmod a+x DeezerDownloader;exit;exec bash'");
    
    ret = system(tmp6);
    if(ret != 0)  handle_error("Unable to change directory");

    char* tmp7 = append("wget ", icon);
    char* tmp8 = append(tmp7, " -O icon.png");
    char* tmp9 = append("gnome-terminal --geometry 100x20+400+500 -- sh -c ' ", tmp8);
    char* tmp10 = append(tmp9, ";exit;exec bash'");

    ret = system(tmp10);
    if(ret != 0)  handle_error("Unable to change directory");

    // Download Completed (Icon and Executable are in .local/share/Applications)

    // Now i create .desktop file
    FILE* f = fopen("DeezerDownloader.desktop", "w");
    if(f == NULL) handle_error("\n\nImpossibile creare il file in scrittura\n\n");

    char* exeInDir = append(mine->homedir, ".local/share/applications/DeezerDownloader/DeezerDownloader");
    char* iconIndDir = append(mine->homedir, ".local/share/applications/DeezerDownloader/icon.png");

    char* dsk1 = append("[Desktop Entry]\nVersion=1.0\nName=Deezer Downloader\nComment=The Most Beatuful Downloader\nExec=", exeInDir);
    char* dsk2 = append(dsk1, "\nIcon=");
    char* dsk3 = append(dsk2, iconIndDir);
    char* dsk4 = append(dsk3, "\nTerminal=false\nType=Application\nCategories=Utility;Development;");
    fprintf(f, "%s\n", dsk4);
    fclose(f);


   	char* quasi1 = "gnome-terminal --geometry 73x20+100+300 -- sh -c 'sudo cp  DeezerDownloader.desktop /usr/share/applications;exit;exec bash'";
   	ret = system(quasi1);
   	if(ret != 0)	handle_error("Unable to move");


    free(DeezerDir);
    free(tmp1);
    free(tmp2);
    free(tmp3);
    free(tmp4);
    free(tmp5);
    free(tmp6);
    free(tmp7);
    free(tmp8);
    free(tmp9);
    free(tmp10);
    free(exeInDir);
    free(iconIndDir);
    free(dsk1);
    free(dsk2);
    free(dsk3);
    free(dsk4);
}