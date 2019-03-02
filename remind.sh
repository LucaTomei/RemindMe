#!/bin/sh

made_by_func(){
	echo  "\033[41mThese scripts are made by:\033[0m"
	tput setaf 2;
	echo  "\e[5m"
	echo
	echo
	echo
	echo "###		    ###           ###     ################     ###############"
	echo "###		    ###           ###    #################    ###           ###"
	echo "###		    ###           ###   ###                   ###           ###"
	echo "###		    ###           ###   ###                   ###           ###"
	echo "###		    ###           ###   ###                   #################"
	echo "###		    ###           ###   ###                   ####LUCAS'MAC####"
	echo "###		    ###           ###   ###                   ###           ###"
	echo "###		    ###           ###   ###                   ###           ###"
	echo "###		    ###           ###   ###                   ###           ###"
	echo "################     ##############      #################    ###           ###"
	echo "################      ###########         ################   ####           ####"
	echo
	echo
	echo
}

sudo_startup(){
	echo
	echo
	sleep 1
   wget "https://www.dropbox.com/s/ut6ne2jd79qg6wr/avvio1_no_process.c?dl=0" -O avvio.c
	gcc -o startup avvio.c
	echo "Do you want to set this file global in your system?  (Y/N)"
	read Input
	case $Input in
y)
    sudo cp startup /usr/local/bin
    ;;
Y)
    sudo cp startup /usr/local/bin
    ;;
*)
    echo "Bye My Friend"
    sleep 1
    break
    ;;
esac

sudo rm -r startup avvio.c
}

automatic_main_generator(){
	echo
	echo
	wget "https://www.dropbox.com/s/3y2pvpt3mwc116v/main_generator.c?dl=0" -O main.c
	gcc -o main main.c
	echo
	echo
	echo
	echo "Do you want to set this file global in your system?  (Y/N)"
	read Input
	case $Input in
	y)
    sudo cp main /usr/local/bin
    ;;
	Y)
    sudo cp main /usr/local/bin
    ;;
	*)
    echo "Bye My Friend"
    sleep 1
    break
    ;;
esac

sudo rm -r main main.c
}

color_your_bar(){
		COLS="$(tput cols)"
		COLORS=$(($COLS/5))
		i=0

		while [ $i -le $(expr $COLS - 1) ]
		do
				if [ $i -le $COLORS ]; then
					echo -n '\033[31m█\033[0m'
					sleep 0.07

				elif [ $i -gt $COLORS ] && [ $i -le $(($COLORS*2)) ]; then

					echo -n '\033[33m█\033[0m'
					sleep 0.07
				
				elif [ $i -gt $(($COLORS*2)) ] && [ $i -le $(($COLORS*3)) ]; then
					
					echo -n '\033[93m█\033[0m'
					sleep 0.07
				elif [ $i -gt $(($COLORS*3)) ] && [ $i -le $(($COLORS*4)) ]; then

					echo -n '\033[92m█\033[0m'
					sleep 0.07
				else
					echo -n '\033[32m█\033[0m'
					sleep 0.07
				fi
				
				i=`expr $i + 1`
		done
		echo
}
# end of progress bar 


sudo_func_all(){
	wget "https://www.dropbox.com/s/vl2aaubyfgi7rja/avvio.c?dl=0" -O avvio.c
	
}


tput reset
made_by_func
#SPACES FOR MY BAR
echo
echo
echo
echo
color_your_bar
tput reset
while :
do
	tput setaf 2;
	tput bold;
	echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
	echo "What would you like to remember?"
	echo "(1)	Hide xPad icon		(2)	Set Parallels default resolution"
	echo "(3)	gcc-4.8     		(4)	Change executable icon "
	echo "(5)	Set eclipse icon	(6)	First Software Installation"	
	echo "(7)	Set size for gedit plugins terminal	                "	
	echo "(8)	gcc-8 + make	        (9)	Set xPad resolution and dimentions"	
	echo "(10)	Set grub dimentions     (11) Change app/x-sharedlib icon (gcc-8) "
	echo "(12)    Set 'startup' for automatic update     (13) Automatic Main     "
	echo "(0)	break			                    "
	echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"

	
  read INPUT_STRING
  case $INPUT_STRING in
  1)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is only a guide:"
		echo "To hide xPad icon "
		echo "1) Go into .config/xpad and edit 'default-style'"
		echo "2) Set 1 for hide_from_taskbar"
		echo "3) Set 1 for hide_from_switcher"
		echo "NOTE: These values ​​were previously set to 0"
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo 
		echo
		echo
		echo
		color_your_bar
		;;
	2)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is only a guide:"
		echo "To set default boot resolution for parallels driver:"
		echo "1)	First install parallels-tool"
		echo "2)	Then go into /usr/share/X11/xorg.conf.d"
		echo "3) Open file '40-prltools.conf'"
		echo "4) Modify voice Modes in # Parallels Screen section setting it into '1440x900' "
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo 
		echo
		echo
		echo
		color_your_bar
		;;
	
	3)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is NOT a guide:"
		sudo apt-get install gcc-4.8-multilib && sudo apt-get purge gcc-4.8-base:i386
		echo "Now i set gcc-4.8 as default GNU compiler"
		echo "                                                                               "
		ls -la /usr/bin/ | grep -oP "[\S]*(gcc|g\+\+)(-[a-z]+)*[\s]" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f "/usr/bin/${link}-${0}" "/usr/bin/${link}"; done' 4.8
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo 
		echo
		echo
		echo
		color_your_bar
		;;
	4)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is a guide:"
		echo "To change default executable icon of Ubuntu:"
		echo "1) Create a backup archive containing /usr/share/icons/Adwaita folder"
		echo "2) Download or Create .png icon and rename it into 'application-x-executable'"
		echo "3) Move your application-x-executable into all mimetipes folders for all dimentions"
		echo "(es: sudo cp <application-x-executable>  /usr/share/icons/Adwaita/<dimentions>/mimetypes)"
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo 
		echo
		echo
		echo
		echo "------> Press 0 and Reboot System <------"
		sleep 5
	   ;;
	5)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is a guide:"
		echo "To set eclipse icon:"
		echo "1) Create 'eclipse.desktop' file in '.local/share/applications'"
		echo "2) Write this into eclipse.desktop file:"
		echo
		echo "       [Desktop Entry]"
		echo "	Version=1.0		"
		echo "	Name=Eclipse   "
		echo "	Comment=Eclipse"
		echo "	Exec=/home/lucasmac/eclipse/java-oxygen/eclipse/eclipse <--- path exec"
		echo "	Icon=/home/lucasmac/eclipse/java-oxygen/eclipse/icon.xpm  <--- path icon"
		echo "	Terminal=false"
		echo "	Type=Application"
		echo "	Categories=Utility;Application;"
			  
		echo "3) Save and Reboot"
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo
		echo
		echo
		echo
		color_your_bar
		;;
	6)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "Wait 3"
		sleep 1
		echo "Wait 2"
		sleep 1
		echo "Wait 1"
		sleep 1
		echo
		echo
		echo "Starting update & ugrade"
		sudo apt update && sudo apt upgrade && sudo apt autoremove
		echo	
		echo
		
		echo "Start for install jdk for Java"
		echo "Wait 3"
		sleep 1
		echo "Wait 2"
		sleep 1
		echo "Wait 1"
		sleep 1
		echo
		sudo apt-get install default-jdk
		echo	
		echo
		
		echo "Start for install gtk-theme-config"
		echo "Wait 3"
		sleep 1
		echo "Wait 2"
		sleep 1
		echo "Wait 1"
		sleep 1
		echo
		sudo apt-get install gtk-theme-config
		echo	
		echo
		
		echo "Start for install synaptic"
		echo "Wait 3"
		sleep 1
		echo "Wait 2"
		sleep 1
		echo "Wait 1"
		sleep 1
		echo
		sudo apt-get install synaptic
		echo	
		echo
		
		echo "End of installation"
		echo "Wait 3"
		sleep 1
		echo "Wait 2"
		sleep 1
		echo "Wait 1"
		sleep 1
		echo
		sudo apt update && sudo apt upgrade && sudo apt autoremove && sudo apt autoclean && sudo dpkg --configure -a && sudo apt-get install -f
		echo
		echo
		echo
		color_your_bar
		;;
	7)	
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is a guide:"
		echo "If you wish to set the resolutive size of the gedit terminal, you'll have to:"
		echo "1) Go into /usr/lib/x86_64-linux-gnu/gedit/plugins"
		echo "2) Modify with sudo terminal.py file"
		echo "3) Set at line 53 ---> self.set_size_request(200, 100)"
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo
		echo
		echo
		echo
		color_your_bar
		;;
	8)	
		tput reset
		sudo apt-get install gcc
		sudo apt-get install gcc-8 && sudo apt-get install make
		sudo apt update && sudo apt upgrade && sudo apt autoremove
		ls -la /usr/bin/ | grep -oP "[\S]*(gcc|g\+\+)(-[a-z]+)*[\s]" | xargs bash -c 'for link in ${@:1}; do sudo ln -s -f "/usr/bin/${link}-${0}" "/usr/bin/${link}"; done' 8
		echo 
		echo
		echo "Verifico Versione gcc installata:"
		echo
		gcc -v
		color_your_bar
		;;
	9)	
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is a guide:"
		echo "If you want to set the resolutive size of the xPad note or its dimentions:"
		echo "1) Go into /config/xpad"
		echo "2) Edit with gedit 'info-***' file"
		echo
		echo "N.B.: If you want to set its position on the top right of the screen, yuo'll edit the file like this:"
		echo
		echo "width 290"
		echo "height 215"
		echo "x 1164"
		echo "y 27"
		echo "follow_font 1"
		echo "follow_color 1"
		echo "sticky 1"
		echo "hidden 0"
		echo "back rgb(255,238,153)"
		echo "text rgb(0,0,0)"
		echo "fontname Sans 10"
		echo "content content-MG38HZ"
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo
		color_your_bar
		;;
	10)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is only a guide:"
		echo "To set default boot resolution for grub:"
		echo "1)	Navigate into /etc/default"
		echo "2)	Edit 'grub' file with gedit"
		echo "3) Uncomment 25 line and paste this GRUB_GFXMODE=1440x900"
		echo "4) Ran sudo update-grub"
		echo "5) Reboot the system"
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo
		echo
		echo
		echo
		color_your_bar
		;;
	11)
		tput reset
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo "This is Not a Guide, Automatic install"
		echo
		echo "If You Want to download a different icon:" 
		echo "1) paste the link before wget"
		echo "2) remove 'mv Retro-Flower-Fire-2-icon.png' and paste 'youricon.png_name.png application-x-sharedlib.png'  "
		echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
		echo
		echo
		echo
		echo "Please Wait 5 seconds:"
		color_your_bar
		wget http://icons.iconarchive.com/icons/ph03nyx/super-mario/256/Retro-Flower-Fire-2-icon.png

		mv Retro-Flower-Fire-2-icon.png  application-x-sharedlib.png

		sudo cp /home/lucasmac/Desktop/application-x-sharedlib.png /usr/share/icons/Adwaita/512x512/mimetypes

		sudo cp /home/lucasmac/Desktop/application-x-sharedlib.png /usr/share/icons/Adwaita/48x48/mimetypes

		sudo cp /home/lucasmac/Desktop/application-x-sharedlib.png /usr/share/icons/Adwaita/32x32/mimetypes

		sudo cp /home/lucasmac/Desktop/application-x-sharedlib.png /usr/share/icons/Adwaita/24x24/mimetypes

		sudo cp /home/lucasmac/Desktop/application-x-sharedlib.png /usr/share/icons/Adwaita/22x22/mimetypes

		sudo cp /home/lucasmac/Desktop/application-x-sharedlib.png /usr/share/icons/Adwaita/16x16/mimetypes

		tput reset
		echo
		echo
		echo "Run this command ------>  sudo -H gedit /etc/mime.types"
		echo "Add this line in the file:"
		echo "application/x-sharedlib				so"
		echo
		echo
		echo "Press any button if done"
		color_your_bar
		read String
		
		sudo gtk-update-icon-cache /usr/share/icons/Humanity
		sudo gtk-update-icon-cache /usr/share/icons/Adwaita
		sudo gtk-update-icon-cache /usr/share/icons/gnome

		gsettings set org.gnome.desktop.interface icon-theme culoculo
		gsettings reset org.gnome.desktop.interface icon-theme

		rm -r application-x-sharedlib.png
		
		echo "Now i'll reboot the system'"
		color_your_bar
		sudo reboot
		;;
	12)
		tput reset
		echo "Now I'm Downloading necessary files"
		echo
		echo
		sudo_startup
		color_your_bar
		;;
	13)
		tput reset
		echo "Now I'm Setting the automatic main generator"
		echo
		echo
		automatic_main_generator
		color_your_bar
		;;
	0)
		color_your_bar
		break
		;;
	*)
		tput reset
		
		;;
  esac
done

echo 
echo "See you again!"
