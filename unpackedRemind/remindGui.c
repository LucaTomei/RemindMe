#include "header.h"

static void installApplication();

// use strncpy(mine->homedir, "Herp", sizeof(mine->homedir)); to replace char* in data struct


extern config* mine;

int res;


int main(int argc, char *argv[]) {
  //downloadSettingIcon();
  installApplication();
  if(argc == 1)	 pre_welcome();
  
  GtkApplication *app;
  int status;
 
  app = gtk_application_new ("org.gtk.remindGuiApp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run(G_APPLICATION (app), argc, argv);
  g_object_unref(app);

  //removeAndExit();
  freeMia(mine);
  return 0;
}


static void activate (GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *hideXpadIcon;
  GtkWidget *parallelsRes;
  GtkWidget *gcc_4;
  GtkWidget *execIcon;
  GtkWidget *eclipseIcon;
  GtkWidget *firstInstallation;
  GtkWidget *geditSize;
  GtkWidget *gcc_8;
  GtkWidget *xPadResDim;
  GtkWidget *grubDim;
  GtkWidget *x_sharedIcon;
  GtkWidget *startup;
  GtkWidget *autoMain;
  GtkWidget *sublInstaller;
  GtkWidget *autoBackup;
  GtkWidget *e_liquidCalc;
  GtkWidget *installConky;


  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 350, 250);
  gtk_window_set_title(GTK_WINDOW(window), "Remind Gui App (By LucasMac)");
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);

  vbox = gtk_box_new(TRUE, 1);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  hideXpadIcon = gtk_button_new_with_label("Hide xPad icon");
  parallelsRes = gtk_button_new_with_label("Set Parallels default resolution");
  gcc_4 = gtk_button_new_with_label("gcc-4.8");
  execIcon = gtk_button_new_with_label("Change executable icon");
  eclipseIcon = gtk_button_new_with_label("Set eclipse icon");
  firstInstallation = gtk_button_new_with_label("First Software Installation");
  geditSize = gtk_button_new_with_label("Set Size for Gedit Terminal Plugin");
  gcc_8 = gtk_button_new_with_label("gcc-8 + make");
  xPadResDim = gtk_button_new_with_label("Set xPad resolution and dimentions");
  grubDim = gtk_button_new_with_label("Set grub dimentions");
  x_sharedIcon = gtk_button_new_with_label("Change app/x-sharedlib icon (gcc-8)");
  startup = gtk_button_new_with_label("Set 'startup' for automatic update");
  autoMain = gtk_button_new_with_label("Automatic Main Generator");
  sublInstaller = gtk_button_new_with_label("Sublime_Text Installer");
  autoBackup = gtk_button_new_with_label("Automatic Ubuntu Backup");
  e_liquidCalc = gtk_button_new_with_label("E-Liquid Calculator");
  installConky = gtk_button_new_with_label("Conky Manager Autoinstaller");
  
  

  gtk_box_pack_start(GTK_BOX(vbox), hideXpadIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), parallelsRes, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), gcc_4, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), execIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), eclipseIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), firstInstallation, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), geditSize, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), gcc_8, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), xPadResDim, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), grubDim, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), x_sharedIcon, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), startup, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), autoMain, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), sublInstaller, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), autoBackup, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), e_liquidCalc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), installConky, TRUE, TRUE, 0);



  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);


  // Funzioni di salto
  g_signal_connect (GTK_BUTTON (hideXpadIcon), "clicked",  G_CALLBACK (hideXpadIconDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (parallelsRes), "clicked",  G_CALLBACK (parallelsResDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (gcc_4), "clicked",  G_CALLBACK (gcc_4Func), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (execIcon), "clicked",  G_CALLBACK (execIconFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (eclipseIcon), "clicked",  G_CALLBACK (eclipseIconDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (firstInstallation), "clicked",  G_CALLBACK (firstInstallationFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (geditSize), "clicked",  G_CALLBACK (geditSizeDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (gcc_8), "clicked",  G_CALLBACK (gcc_8Func), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (xPadResDim), "clicked",  G_CALLBACK (xPadResDimDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (grubDim), "clicked",  G_CALLBACK (grubDimDialog), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (x_sharedIcon), "clicked",  G_CALLBACK (x_sharedIconFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (startup), "clicked",  G_CALLBACK (startupFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (autoMain), "clicked",  G_CALLBACK (autoMainFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (sublInstaller), "clicked",  G_CALLBACK (sublInstallerFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (autoBackup), "clicked",  G_CALLBACK (autoBackupFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (e_liquidCalc), "clicked",  G_CALLBACK (e_liquidCalcFunc), GTK_WINDOW (window));
  g_signal_connect (GTK_BUTTON (installConky), "clicked",  G_CALLBACK (installConkyFunc), GTK_WINDOW (window));
  
  
  gtk_main();
}

