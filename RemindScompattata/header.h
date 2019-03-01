#include <gtk/gtk.h>
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
#include "PreWelcome/pre_welcome.h"



#define BAR "=================================================================="


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


char* append(char* string1, char* string2);
void pre_welcome();
void progress_bar_exit();
void downloadSettingIcon();
void removeAndExit();
static void on_response (GtkDialog *dialog, gint response_id, gpointer user_data);
static void on_responseE_liquidCalcFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void e_liquidCalcFunc (GtkButton *button, gpointer   user_data);
static void on_responseAutoBackupFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void autoBackupFunc (GtkButton *button, gpointer   user_data);
static void on_responseSublInstallerFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void sublInstallerFunc (GtkButton *button, gpointer   user_data);
static void on_responseAutoMainFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void autoMainFunc (GtkButton *button, gpointer   user_data);
static void on_responseStartupFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void startupFunc (GtkButton *button, gpointer   user_data);
static void on_responsex_sharedIconFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void x_sharedIconFunc (GtkButton *button, gpointer   user_data);
static void grubDimDialog (GtkButton *button, gpointer   user_data);
static void xPadResDimDialog (GtkButton *button, gpointer   user_data);
static void on_responsegcc_8Func(GtkDialog *dialog, gint response_id, gpointer user_data);
static void gcc_8Func (GtkButton *button, gpointer   user_data);
static void geditSizeDialog (GtkButton *button, gpointer   user_data);
static void on_responseFirstInstallationFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void firstInstallationFunc (GtkButton *button, gpointer   user_data);
static void eclipseIconDialog (GtkButton *button, gpointer   user_data);
static void on_responsegcc_execIconFunc(GtkDialog *dialog, gint response_id, gpointer user_data);
static void on_responsegcc_4Func(GtkDialog *dialog, gint response_id, gpointer user_data);
static void hideXpadIconDialog (GtkButton *button, gpointer   user_data);
static void parallelsResDialog (GtkButton *button, gpointer   user_data);
static void activate (GtkApplication *app, gpointer user_data);

